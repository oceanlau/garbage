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

  - Interrupt: 
    1. I/O devices wired with Interrupt Request Lines (IRQs).
    2. IRQs are mapped to interrupt vectors by Programmable Interrupt Controller (PIC). PIC sends the interrupt vectors to CPU for handling.
    3. At software level, an Interrupt Vector Table (IVT), which in x86 is called Interrupt Descriptor Table (IDT), associate interrupts with handlers.
  - Trap: system call
  - Fault:
    - Faster than actively detecting faults. Modern OSes use VM faults for many functions (Debug, gc, copy-on-write)
    - Handing: fix and re-execute, notifying the process, kill the process.

- Synchronization: disable interrupts, atomic instructions