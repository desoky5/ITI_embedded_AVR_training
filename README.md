# ITI AVR Embedded Systems Diploma

Daily labs, exercises, and projects from the ITI 1-Month AVR Embedded Systems Diploma (Alexandria, Group 1), completed in C on Ubuntu/Linux.

## Why This Diploma Matters for Robotics Engineering

Every mobile robot, manipulator, or autonomous system is built on two layers: a high-level "brain" (ROS2, planning, perception) and a low-level "nervous system" that actually reads sensors and drives actuators in real time. This diploma is entirely about the second layer — and it's the layer most robotics engineers are weakest in, because bootcamps and CS-heavy curricula skip straight to ROS2 without ever making you debug a register, a race condition, or a timer interrupt by hand.

This repo documents that gap being closed, module by module:

- **C Programming fundamentals → firmware-grade C.** Pointers, dynamic memory, modifiers, and preprocessor macros aren't academic here — they're what a bare-metal HAL is built from. This is the same skill set behind writing an STM32 real-time control layer without a framework doing the work for you.
- **Embedded Systems Concepts → the mental model for hard real-time constraints.** Understanding what a system *can't* do (blocking calls, unbounded loops, dynamic allocation on a control loop) is what separates code that works on a bench from code that fails on a moving robot.
- **AVR Interfacing (DIO, LCD, Keypad, Motors, ADC, Timers/PWM, Interrupts, UART, SPI, I2C, EEPROM) → the actual toolkit of robotics hardware I/O.** This maps directly onto real subsystems I already work with: PWM → motor/servo control, ADC → analog sensor fusion (e.g. LDC1614 metal detection), UART/SPI/I2C → sensor and MCU-to-MCU communication (STM32 ↔ Raspberry Pi bridges), Timers/Input Capture → encoder feedback and PID loops, Watchdog → fault recovery on a system that can't afford to hang mid-mission.
- **RTOS Concepts → the bridge from "one big loop" to scheduled, multi-task firmware.** This is the conceptual foundation for scaling from a single AVR project to the kind of task-scheduled real-time systems used in production robotics controllers.
- **AI-Assisted Embedded Development (Vibe Coding, Prompt Engineering, AI Ethics & Verification) → using AI tools responsibly for firmware work**, where correctness and verification matter far more than in typical software because bugs manifest as physical hardware failures, not just crashed processes.
- **Graduation Project → a full closed-loop embedded system**, capstone-style, applying everything above end to end.

## How This Fits the Bigger Picture

I already work at the systems-integration level — STM32 firmware talking to ROS2 over UART, encoder-based PID control, EKF localization, sensor fusion — for projects like a closed-loop DC motor controller, a mobile manipulator (STM32F411 + Pi 5 + YOLOv8), and an in-progress Minesweeper robot (STM32F401 HAL + Pi 5/ROS2 Jazzy + Nav2). This diploma reinforces the layer underneath all of that: the register-level, interrupt-driven, timing-critical AVR fundamentals that make the STM32/ROS2 work *reliable* instead of just *functional*. It's also directly relevant to graduate program applications (ETH Zurich, TU Delft, KAUST) and industry roles where hardware-software integration is the differentiator, not just ROS2 fluency.

## Repository Structure

```
01-c-programming/           # Intro through Dynamic Memory Allocation
02-embedded-systems-concepts/
03-avr-interfacing/         # DIO, LCD, Keypad, Motors, Timers, ADC, UART, SPI, I2C, EEPROM...
04-rtos-concepts/
05-ai-assisted-embedded-dev/
06-graduation-project/
```

Each lab folder contains source (`.c`/`.h`), a Makefile (avr-gcc based), and notes where relevant.

## Toolchain

- **MCU:** ATmega32
- **Compiler/Programmer:** avr-gcc, avrdude, USBasp
- **Simulation:** SimulIDE
- **OS:** Ubuntu (zsh)
- **Build:** Makefile per lab

## Status

In progress — updated as each day/module is completed. See folder structure for current coverage.
