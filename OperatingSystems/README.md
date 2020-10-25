# Operating Systems

The layer between applications and hardware. Manage hardware (protection), ensure high utilization of hardware (resource sharing) and provide abstractions to applications.

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

A program in execution. Multiprogramming ensure higher throughput and higer hardware utilization.

- Process components: address space, code, data, execution stack, program counter (PC) indicating next instruction, some general registers and set of resources (opened files, network conns). Each process has its own view of the machine.
  - The data structure: Process Control Block (PCB). It contains process state, process id, program counter, registers, address space, open files, etc.
- OS point of view
  - OS usually maintains a queue of process for each state. Most processes are in the waiting state, waiting for I/O. There may be many wait queues for each type of wait.
  - Scheduling, preemption described later in Threads.
  - Context switch: Usually starts with saving program counter, integer registers, etc. Then changes virtual address translations.
- Programmer point of view
  - Unix fork() duplicate current process, return child pid to parent process and return 0 to newly created child process.
  - Unix exec() stops current process and loads new program, so it won't return unless there is a problem. Pintos exec() is fork() + exec() and it will return child pid.
  - Compared to Windows CreateProcess(), fork() has no argument so it's much easier to use.