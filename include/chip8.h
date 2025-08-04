#ifndef CHIP8_H
#define CHIP8_H

#include <stdint.h>

#define V_REGISTER_COUNT 16
#define CHIP_MEMORY_SIZE 4096
#define STACK_DEPTH 16

// Implementing the CPU of chip 8
struct CPU_Chip8 {
    uint8_t V[V_REGISTER_COUNT];
    uint16_t I;
    uint16_t PC; 
    uint16_t STACK[STACK_DEPTH];
    uint8_t SP; 
    uint8_t DELAY_TIMER;
    uint8_t SOUND_TIMER; 
    uint8_t MEMORY[CHIP_MEMORY_SIZE];
} CPU_Chip8;

#endif