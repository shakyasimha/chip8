#include <string.h>
#include <stdlib.h>

#include "chip8.h"

cpu_t* init_cpu(cpu_t *cpu) {
    // Allocating memory for CPU
    cpu_t *cpu = malloc(sizeof(cpu_t)); 

    // Return null if it cannot allocate CPU
    if (!cpu) return NULL;

    // Clearing registers and memory
    memset(cpu->V, 0, sizeof(cpu->V));
    cpu->I = 0;
    cpu->PC = 0x200;    // CHIP8 programs start at 0x200 
    memset(cpu->STACK, 0, sizeof(cpu->STACK));
    cpu->SP = 0;
    cpu->DELAY_TIMER = 0;
    cpu->SOUND_TIMER = 0;
    memset(cpu->MEMORY, 0, sizeof(cpu->MEMORY));

    return cpu;
}

void free_cpu(cpu_t *cpu) {
    free(cpu);
}