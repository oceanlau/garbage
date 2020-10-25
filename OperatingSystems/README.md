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
    - Can be done preemptively or preemptively.
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

- Locks: spinlock or mutex. Need hardware support to implement.
  - Atomic instructions: test-and-set. Can be used to implement spinlocks.
  - Disabling interrupts: no context switch anymore. Disabled only within acquire() and release().

