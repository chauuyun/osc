# Bare metal OS kernel for Raspberry Pi 3B+

## Introduction
- Technologies Used: Raspberry Pi 3B+, C, Assembly, Ubuntu, QEMU
1. Developed a custom OS kernel in C and Assembly featuring UART and GPIO integration with a mailbox mechanism for efficient CPU–peripheral communication.
2. Engineered robust exception and interrupt handling—including ARMv8-A exception level transitions, vector table setup, core timer interrupts, and asynchronous mini UART I/O.
3. Designed and implemented a dynamic memory allocator based on the buddy system for efficient page frame management.
4. Built a lightweight thread scheduler and user process framework with context switching, system call interfaces, and preemptive multitasking, powering a multi-threaded shell environment.

## Requirements 
Using lab0/install_env.sh for the tools

* aarch64-linux-gnu-gcc
* qemu-system-aarch64

## Course Website
Operating System Capstone

https://nycu-caslab.github.io/OSC2024/

## Labs list

Lab0: Environment Setup

Lab1: Hello World

Lab2: Booting

Lab3: Exception and Interrupt

Lab4: Allocator

Lab5: Thread and User Process

Lab6: Virtual Memory

Lab7: Virtual File System

 git add .  
 git commit -m "some message"  
 git push  

## Disassembly command:  
llvm-objdump -d file.o
