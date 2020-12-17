# Operating Systems

Based on Prof. Ryan Huang's [Principles of Operating Systems course](https://www.cs.jhu.edu/~huang/cs318/fall20/index.html).

OS: The layer between applications and hardware. Manage hardware (protection), ensure high utilization of hardware (resource sharing) and provide abstractions to applications.

## Hardware Support

- Protection.
  - Dual mode: user/kernel. Recorded in the register. Modern CPU may have more than 2 levels (x86:4, ARMv7:8).
  - Protected instructions: directly access I/O devices, manipulate memory management state, manipulate protected control registers, halt.
  - Memory protection: translate virtual address at Memory Mangement Unit (MMU).

- Events. Immediately stops current execution, changes mode to kernel, transfers control to handler code in the OS, and finally restores program state.
  |                                                     | Unexpected                        | Deliberate                         |
  |-----------------------------------------------------|-----------------------------------|------------------------------------|
  | Interrupts: caused by external event (async)        | interrupt (I/O, timer)            | software interrupt                 |
  | Exceptions: caused by executing instructions (sync) | fault (page fault, division by 0) | syscall trap (x86 int instruction) |

  - Interrupt (I/O): Polling or:
    1. I/O devices wired with Interrupt Request Lines (IRQs).
    2. IRQs are mapped to interrupt vectors by Programmable Interrupt Controller (PIC).
    3. PIC sends the interrupt vectors to CPU for handling.
    4. At software level, an Interrupt Vector Table (IVT), which in x86 is called Interrupt Descriptor Table (IDT), associate interrupts with handlers.
  - Trap: system call. How to pass result from syscall to user? Issue a special descriptor (e.g. file descriptor number).
  - Fault:
    - Faster than actively detecting faults. Modern OSes use VM faults for many functions (Debug, gc, copy-on-write)
    - Handing: fix and re-execute, notifying the process, kill the process.

- Synchronization: disable interrupts, atomic instructions

## Processes

A program in execution. Multiprogramming ensure higher throughput and higher hardware utilization.

- Process components: address space (code, data, execution stack), program counter (PC) indicating next instruction, some general registers and set of resources (opened files, network conns). Each process has its own view of the machine.
  - The data structure: Process Control Block (PCB). It contains process state, process id, program counter, registers, address space, open files, etc.
  - Inter-Process Communication (IPC): Passing message through kernel, sharing physical memory region, asyncrhonous signals or alert.

- OS point of view
  - OS usually maintains a queue of process for each state. Usually most processes will be in the waiting state, waiting for I/O. There may be many wait queues for each type of wait.
  - Scheduling, preemption described later in Thread.
  - Context switch: Usually starts with saving program counter, integer registers, etc. Then changes virtual address translations.

- Programmer point of view
  - Unix fork() duplicate current process, return child pid to parent process and return 0 to newly created child process.
  - Unix exec() stops current process and loads new program, so it won't return unless there is a problem. Pintos exec() is fork() + exec() and it will return child pid.
  - Compared to Windows CreateProcess(), fork() has no argument so it's much easier to use.
  - wait(). [Wait for all child processes to finish](https://stackoverflow.com/questions/19461744/how-to-make-parent-wait-for-all-child-processes-to-finish).

## Thread

- Separate execution state from process concept. 
  - Process is static holding address space and attributes like privileges and resources. Thread is dynamic holding program counter, stack pointer and other register values.
  - Thread is the unit of scheduling.
  - Threads share heap, code, data, files. But have its own registers, stack.
  - The data structure: Thread Control Block (TCB).
  - thread_create() allocates TCB, stack, put function name and arguments onto the stack (calling convention) and finally put thread on the ready list.

-  Kernel level thread and User level thread:
  - Kernel level thread: Must go through kernel, so it is often slower to create. Same features (priority, etc.) for every one. Requires fixed-size in the kernel.
  - User level thread: Invisible to OS, so it cannot take advantage of multiple CPUs and may not be scheduled well.
  - Solution: associate or multiplex user threads to kernel threads. (n:m mapping)

- Scheduling
  - yield(): One thread yield the CPU. Context switch to another thread. That thread return from its own yield() and continue.
  - Non-preemptive scheduling: voluntarily yield
  - Preemptive scheduling: Timer interrupt forces current thread to yield.

- Context switch: save and restore context. Done at assembly. x86 examples below:
  - Calling conventions: a standard on how functions should be implemented and called by the machine. Compilers compile code to assembly and set up stack and registers according to this standard.
    - Stack:
       ```
                 +-----------------+
                 |                 |
                 |  arguments      |
                 |                 |
                 +-----------------+
                 |                 |
                 |  return addr    |
                 |                 |
                 +-----------------+
                 |                 |
                 |  old frame ptr  |
                 |                 |
       fp +----> +-----------------+
                 |                 |
                 |  callee-saved   |
                 |  registers      |
                 |                 |
                 +-----------------+
                 |                 |
                 |  local vars     |
                 |  and temps      |
                 |                 |
       sp +----> +-----------------+
                 |                 |
                 |                 |
       ```


    - Registers:
      - Caller-saved registers: %eax(return value), %edx, %ecx. Caller has saved them to the stack so callee function can freely modify these registers.
      - Callee-saved registers: %ebx, %edi, %ebp, %esp. Restore to original before return.

  - switch_threads(cur, next)

## Scheduling

- Criteria: Throughput, turnaround time (start to finish), response time (request to first response) of processes. Secondary criterias are CPU utilization and process waiting time.
  - Batch system often optimize for throughput and turnaround time. Interactive systems oftem optimize for response time.
  - Non-goal: process starvation

- Textbook scheduling
  - First-in-first-out: non-preemptive in nature. Has convoy effect.
  - Shortest job first: choose the job with smallest expected CPU burst. Provable optimal minimum average waiting time.
    - Inspiration: most jobs have bursts of computation and long waiting time for I/O. We can overlap computation of one thread with I/O time of others to maximize throughput.
    - Can be done non-preemptively or preemptively.
    - Does not minimize average turnaround time.
    - Can lead to unfairness or starvation.
    - It is impossible to know the CPU burst time ahead. Solution: estimate based on the past.
  - Round robin: each job is given a time slice called a quantum. Preempted and moved to FIFO queue after the quantum.
    - Low average waiting time.
    - Frequent context switch cost and high turnaround time.
    - Quantum should be picked larger than most CPU bursts time.

- Priority scheduling
  - Avoid starvation: age the processes. Increase priority as waiting time increases. Decrease as CPU consumption increases.
  - Avoid priority inversion (kind of like deadlock, but different in nature): high priority thread donates to low priority thread holding the resource.
  - Combining algorithms: multiple queues each with different algorithm. E.g. multiple-level feedback queues (MLFQ). 
    - MLFQ: Optimize turnaround time for batch jobs and minimize response time for interactive jobs.
      - Each queue has different priority. Within each queue we use RR.
      - Change priority based on the past. Interactive jobs has high priority. Batch jobs that used up a quantum was demoted.
      - Aovoid starvation and cheating: Periodically boost priority for jobs that haven't been scheduled. Also the demotion strategy can account for job's total run time at a priority level.

- Advanced scheduling

## Synchronization

Threads may share resources and may need to coordinate their execution.

Stack data are not shared. Global variables, static objects (both in static data segments) and dynamic objects (in heap) are shared.

The compiler might change the sequence of execution of your code. Threads may interleave executions arbitrarily.

- Mutual exclusion
  - Safety property: if one thread is in critical section, then no other is.

  - Liveness property:
    - Progress: any one outside critical section can enter. Those inside will eventually leave.
    - Bounded waiting (no starvation): any one waiting for critical section will eventually enter.

  - Performance: small overhead.

- Locks: spinlock or mutex. Need hardware support to implement:
  - Atomic instructions: test-and-set. Set to true but return old flag value. Break out of while loop if old value is different from new value. Can also be implemented using atomic swap. This is used to implement spinlocks.
  - Disabling interrupts: no context switch anymore. Disabled only within acquire() and release().

## Semaphores and Monitors

- Semaphore: a counter and a waiting queue. P() waits and then decreases the counter. V() Increases the counter and signals others.
  - Mutex semaphore (binary semaphore) vs counting semaphore: Limit the counter (number of access).

- Condition variables (C/V): wait for some condition.
  - Can be implemented with semaphore. What is special about C/V:
    - It must acquire lock before modifying the variable. 
    - The signal (or broadcase) has no history, unlike semaphore::signal. So it must atomically release the lock and started waiting to avoid missing the signal.

    To implement broadcast and the no history property, we must use a queue of semaphores to implement C/V. The queue is protected by the lock.

  - Two flavors:
    - Hoare: signal() immediately switches from caller to a waiting thread and guarantees the condition holds.
    - Mesa: signal() merely places a waiter on the ready queue and continue its own execution. The ready thread must recheck the condition when run.

- Monitor: programming language construct that controls access to shared data. It encapsulates the procedures on that shared data.
  - Only one thread can execute within a monitor at a time.
  - C/V can be used within Monitor without lock.

- Classic problems: Readers/Writers problem, Bounded Buffers problem.

## Deadlock

- Classic problem: Dining philosophers problem.
- Definition: every process in a set of processes is waiting for another one in the set.
  - Exists with all kinds of synchronization methods. One thing to remember is that it is always dangerous to hold locks while crossing the bourdary:
  ```
  lock(a);
  foo() // Internally using C/V. Will not release a when waiting.
  unlock(a);
  ```
- Conditions for deadlock. All 4 are needed for dealock to occur.
  - Mutual exclusion
  - Hold and wait
  - No preemption: critical sections are not aborted externally
  - Circular wait: can be shown with resource allocation graph

- Dealing with deadlock:
  - Ignore it.
  - Prevention. Eliminating one condition.
    - Dealing with Mutual exclusion: buy more resources, split or copy resources. One less philosopher would solve the dining philosophers problem.
    - Dealing with Hold and wait: wait on all resource at once. Need to know all in advance.
    - Dealing with No preemption: give up resource to another, like virtual memory manangement
    - Dealing with Circular wait: single lock for entire system or partial ordering of resources.
  - Avoidance: System only grants resource requests if it knows that the process can obtain all resources it needs in future requests. Need to know all resources needed in advance. Not pratical. There is a Banker's algorithm. But it causes low resource utilization.
  - Detection and recovery: implemented in VMS, MySQL.
    - Detection: traverse resource allocation graph. But it may be expensive.
    - Recovery: abort all/one process, preempt resource (force release. Tricky to implement).

## Virtual Memory

- Goal
  - Abstraction for programming
  - Allocate scarce memory resources.

- Issues with naive approach of allocating memory:
  - Protection
  - Transparency: a process doesn't require specific physical memory address but does often require large amounts of contiguous space
  - Resource exhaustion: sum of all processes memories is often larger than physical memory
- Solution:
  - Protection between processes
  - Give each process its own virtual address space. Process does not see the physical memory addresses. A Memory-Management Unit (MMU) translates and allocate them.
  - This space is often larger than the available physical memory.

- Implementation:
  - For each process, records a base and a bound register for translation. Good performance, cheap space overhead but hard to grow or share memory.
  - Segmentation: many bases and bounds (segments) in a table. Each virtual address is a segment number and offset concatenated together. Need translation (MMU hardware), not completely transparent (?), external (if use variable-sized segment) and internal fragmentation  (if use fixed-sized segment) waste space.
  - Alternative to hardware MMU: language-level protection (Java), software fault isolation (Google Native Client).

- Paging: fixed-sized segment. Usually 4K, an empirical choice.
  - Virtual address: 4B, 32 bits. Least significant 12 bits ($$ = \log_{2} 4K $$) are offset. Rest 20 sigificant bits are virtual page number.
  - Page table: maps virtual page number to physical page number, along with flags.
  - Page table entry: 12 bits (?) flags + 20 bits physical page number

- Good and bad:
  - Easy to allocate, no external fragmentation, easy to swap out.
  - Still has internal fragmentation, memory reference overhead (improve by hardware cache), memory space overhead (per process, 32 bits address space and 4K page need $$ 4B * 2^{32} / 2^{12} = 4MB $$ size page table. Can improve by paging the page table.)

## Virtual Memory Optimization

- How to reduce memory space overhead? Hierarchical page table. Some sub page tables don't need to be allocated. Use two-level x86 Paging as example:
  - Enabled by control register %cr0. %cr3 points to a 4KB size page directory.
  - Page directory: 1024 page directory entries ($$ 4KB / 4B $$ page directory entry size). $$ 1024 * 4B = 4KB$$ size page directory.
  - Page directory entry: Most significant 20 bits are base physical address of a page table. Rest are flags.
  - Page table: 1024 page table entries. Each page table covers 4MB ($$ = 4K * 1024 $$) memory space. Each page table is $$ 1024 * 4B = 4KB$$ in size.
  - Page table entry: Most significant 20 bits are base physical address. Rest are flags.
  - Virtual address: Most significant 10 bits are page directory number, middle 10 bits are virtual page number, least 12 bits are offset.

  Though we might use $$4KB + 4KB * 1024$$ for this two level page table (4KB larger than previous approach), most of the secondary page tables are not allocated.

  Also we are paging the page table, we won't page the outer page table to stop recursion (called wiring). Also we need special code when paging the OS address space.

- How to reduce memory reference overhead? Translation lookaside buffer (TLB, a hardware cache). Managed by MMU. Caches virtual page number to page table entry value (to include flags).
  - Loaded either by hardware (x86 MMU) or software (MIPS, Alpha, Sparc, PowerPC OS)
  - OS ensures consistency (invalidates if protection bit changes, context switches). (Usually hardware) Implements eviction policy like Last-Not-Used.

- Swap: paging in and out from disk. Designs: Page eviction if memory is full v.s. demand paging (all pages are default in disk until accessed).

- Page faults: when a process accesses a page that was evicted.

  1. When the OS evicts a page, it sets the PTE as invalid and stores the location
  of the page in the swap file in the PTE
  2. When a process accesses the page, the invalid PTE causes a trap (page fault)
  3. The trap will run the OS page fault handler
  4. Handler uses the invalid PTE to locate page in swap file
  5. Reads page into a physical frame, updates PTE to point to it
  6. Restarts process
  
- Summary cases:

  1. Read from TLB
  2. TLB misses. Load from page table by MMU or OS. Might be recursive if the page table is paged.
  3. TLB misses. If the page is invalid, page is not in physical memory, protection fault (read/write operation not permitted), causes a page fault.
    - Page is invalid, protection fault. Sends segmentation fault to process.
    - Page is not in physical memory. Sends page fault to OS for loading.

- Sharing: PTEs points to a same physical frame.
  - Need to update all PTEs when evicting a frame.
  - Pointer inside the shared region usually should not point to address outside the region.
  - Even if the pointer only points to address inside the region, if we don't force virtual addresses to shared region exactly the same, we would have a problem. To conclude:
    - Same virtual addresses: Might have conflict, but pointers inside the region are valid.
    - Different virtual addresses: Flexible, but pointers inside the region are invalid.

- Copy on write: When `fork()`, child virtual address space points to read-only parent pages. Parent and child only copies the page when there is a write (which causes a protection fault).

- Memory mapped file: `mmap()` in Unix. Binds a file to a virtual memory region. Load into memory when a file segment is accessed. Writes back when a page is evicted.
  - Good: uniform access for files and memory, less copying (page is never read or written if it is not accessed or dirty).
  - Bad: Less control over data movement, does not generalize to streamed I/O.

## Page Replacement

Choose which page to evict.

- Some thoughs:
  - Locality: temporal locality (recently referencied pages are more likely to be referenced again), spatial locality.
  - 80/20 rule. 20% "hot" memory.
- FIFO
  - Belady's Anomaly: more physical memory does not always mean fewer faults.
- Optimal algorithm: Belady's algorithm. Evict a page that is "never" touched again. Used as a yardstick.
- LRU
  - Straw Man LRU: keep a timer value on PTEs. Large overhead. Using a doubly-linked list is also expensive.
  - Clock algorithm
  - Use a second clock hand for large memory
- How to decide the memory space to each process?
  - Fixed space: replace its own pages. Might be too good/bad to some processes.
  - Variable space: global replacement. One process might ruin all others.

## Dynamic Memory Allocation

- Stack allocation and Heap allocation (our focus).
- Problem with the naive approach: random allocation and free create fragmentation. Allocator cannot move regions already assigned to users.
- Some thoughts:
  - Fragmentation comes from different lifetime and sizes of requested block.
  - Important placement choice: Split large block (causes internal fragmentation), coalescing small blocks (causes external fragmentation).
- Best fit:
  - Search freelist and find block closest in size to the request.
  - Problem: sawdust. Small fragments every where. Not serious in practice.
- First fit:
  - LIFO: free object on front of list. Simple, good locality but high fragmentation.
  - Address Sort: easy coalescing. Good locality. Used in practice. Roughly like sorting list by size. Operationally similar to best fit. Serious sawdust at the beginning.
  - FIFO: similar to address sort according to statistics.
- Worst fit: fight sawdust by find blocks to split that maximize leftover size. In real life seems to ensure that no large blocks around.
- Next fit: use first fit and remember last position. Tends to break down entire list in real life.
- Buddy systems: Round up allocations to power of 2 to make management faster. Used by Linux, FreeBSD.
- Memory usage patterns
  - Ramps
  - Peaks: use Arena allocation. Allocate just by moving pointer and free together. Save size tag space (?).
  - Plateaus
- Slab allocation: useful when allocating many instances of same struct. A slab is multiple pages of contiguous physical memory. A cache is multiple slabs and only for one kind of object. Then we can use bitmap to manage and avoid internal fragmentation. Used in FreeBSD and Linux, implemented on top of buddy page allocator.
- Simple, Fast Segregated Free Lists. TCMalloc. Use lists and tree to record free block of different sizes. Fast small alloc without size tag. But might waste space when keeping the data structure.
- Inside `malloc()` move heap (program break) up by some size using `sbrk()`. But it is tricky to return memory to the system because we might not be freeing the last object. In reality we use `mmap()` and `munmap()`.

## I/O and Disks

- I/O device interfaces
  - Port: The usual connection point.
  - Bus: PCI/PCIe, expansion bus for slower devices.
  - Controller: electronics that operate port, bus or directly on devices.
- Control:
  - I/O instructions: `in` and `out` instructions on x86. Read and write device interface registers.
  - Memory-mapped I/O: device registers appear as memory locations
- Status: Polling vs Interrupts: If the device is really fast (network card), polling is better.
- Data: programmed I/O v.s. direct memory access (DMA). DMA avoids data copying to memory. CPU only handles control requests. Let the device read and write memory.
- Use abstraction to handles different devices. E.g. File system > Block layer > Driver > Hard Drive
- Hard disk
  - Provide 512B (~ 4KB) atomically write.
  - Seek (move head to the right track) cost most. Can be 4-10 ms. Rotate time can be 4ms if 7200 RPM. Transfer time is only 5us. So disk is good for sequential bad for random read.
  - Disk scheduling
    - First come first served
    - Shortest seek time first: can cause starvation.
    - Elevator (SCAN). SSTF but next seek must be in the same direction. Good locality and bounded waiting. But cylinders in the middle get better service and might miss locality SSTF could exploit. CSCAN: Only sweep in one direction. Very commonly used algorithm in Unix.
- Flash memory: faster but limited number of overwrites (wear out) and limited durability.

## File Systems

- Main tasks
  - Don’t go away (ever)
  - Associate bytes with name (files)
  - Associate names with each other (directories)
  - Can implement file systems on disk, over network, in memory, in non-volatile ram (NVRAM), on tape, w/ paper.
- Trends and observation
  - Disk bandwidth, cost/bit and also CPU/memory improves exponentially
  - Seek time and rotational delay is the bottleneck
  - Major goal of FS design: operations have as few disk accesses as possible and minimal space overhead of content (file metadata)
  - Content in a file, files in a directory tend to be used together
- File: named bytes on disk. Has properties (flags, timestamps) and type (encoded in the name or contents).
  - Compare FS to VM: Both are doing mapping, CPU time not a big deal in FS but need to limit disk accesses. 
  - File access methods: sequential, random, indexed (file is like a structured kv), record (file is like an array)
  - Index node or inode: The structure that tracks a file's sectors.
- Sector allocation scheme
  - Contiguous allocation: inode records location and size. Like VM segmentation this causes external fragmentation.
  - Linked files: inode records the location of first block. A free list records empty blocks. Each content block points to the next block in the file. This is in fact random accesses on disk. Bad for both reading the whole file and random access within the file.
  - DOS FS: Put the links (including starting block position and end of file) in fixed-size file allocation table rather than content blocks. Easier for caching.
  - Indexed files: Each file has an array holding pointers to all the content blocks. Good for random access now. But this array itself may need large chunk of contiguous space. Same problem as the single layer page table in VM.
  - Multi-level indexed files (Unix inodes): First 12 pointers in the array are direct blocks pointing to the content block. Then single, double, triple indirect pointers. Plus some file metadata.
- Inode array: location and size fixed when disk initialized. The index of an inode in this array is called i-number.
- Directory: logical locations of the files. Directory itself is a file. Content is the file names and their i-numbers.
  - `/`, `.`, `..` provided by the FS.
  - `~`, `*` provided by the shell program.
- Hard link and soft link
  - Hard link, synonym: `ln`. File not removed until all synonyms are removed. Inode of the file keeps a reference count.
  - Soft link, symbolic link: `ln -s`. File may even not exist at all. Reference count unchanged.
- File Buffer Cache: system wide blocks r/w cache. Compete with VM for memory. Also needs replacement algorithms.
  - Write cache: periodically flush to disk or forced to flush by `fsync`.
  - Read cache: often read ahead to exploit locality
- File sharing: concurrency control and protection
  - Access control list: for each file, maintain a list of users and their permitted actions. Easier to manage, but can be bad for performance if there are too many users.
  - Capabilities: The permitted actions on each file of a user.
  - In Unix, ACL is used on files, capabilities are used in file descriptors.

## Advanced File Systems

- Original Unix FS only gets 2% of disk maximum transfer rate when reading from disk. Because the blocks are too small (and large number of the indexes. Cause lots of disk access), free list is unorganized and often fragmented, inodes and content blocks are far away, the locality of files inside a directory is not utilized.
- Fast File System for BSD Unix:
  - Larger block size: tradeoff between bandwidth and fragmentation. Improve by split block like malloc.
  - Free list: use bitmap
  - Locality: try to put file inode and content blocks, files inside the same directory in the same cylinder group. Each group now works as a mini FS.
- Log-structured File System: Writes are append-only. Optimize for smaller and random writes. Also not agnostic to disk geometry.
  - How to read latest: use inode map. inode number -> latest inode location. inode map are segmented.
  - Disk cleaning