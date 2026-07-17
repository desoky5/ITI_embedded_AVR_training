# C Programming

Foundational and embedded-relevant C, covered before moving into AVR interfacing. These sessions build the language fluency needed for register-level firmware work later in the diploma — direct memory manipulation, storage classes like `volatile` (critical for ISR-shared variables), and manual memory management, all of which show up constantly in bare-metal embedded C.

## Sessions

| # | Topic | Key Concepts |
|---|-------|---------------|
| 1 | [C Basics](./01-c-basics/) | Variables, data types, operators |
| 2 | [Conditional Statements](./02-conditional-statements/) | `if`, `switch-case` |
| 3 | [Loops](./03-loops/) | `for`, `while`, `do-while`, `break`, `continue` |
| 4 | [Functions](./04-functions/) | Prototypes, function architecture |
| 5 | [Pointers & Direct Memory Access](./05-pointers/) | Pointer arithmetic, dereferencing, direct memory access |
| 6 | [Data Modifiers & Storage Classes](./06-modifiers-storage-classes/) | `static`, `volatile` |
| 7 | [User-Defined Data Types](./07-user-defined-types/) | `struct`, `union`, `enum`, bit-fields |
| 8 | [C Build Process & Preprocessor](./08-build-process-preprocessor/) | `#define`, conditional compilation |
| 9 | [RAM Layout & Dynamic Memory Allocation](./09-dynamic-memory-allocation/) | `malloc`, `free`, linked lists |

## Why It Matters Here

- **Pointers & direct memory access** → this is how you'll read/write AVR registers directly (`*(volatile uint8_t*)0x24`) instead of relying on a HAL doing it for you.
- **`volatile`** → essential the moment interrupts show up later in the diploma; without it, the compiler can optimize away reads of a variable that an ISR changes behind its back.
- **Bit-fields, `struct`, `union`** → how register maps and packed sensor/communication data are modeled cleanly in embedded C.
- **RAM layout & dynamic memory** → understanding stack vs. heap matters even more on a microcontroller with a few KB of RAM, where a bad `malloc` pattern can silently corrupt the stack.

## Toolchain

- Compiler: gcc (for these general C exercises; AVR-specific labs use avr-gcc)
- OS: Ubuntu (zsh)
