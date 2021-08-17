#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "mmu.h"

/* Structure that represents the internal state of the CPU
 */
typedef struct CPU CPU;
struct CPU {
	/* General usage registers with the option to access 
	 * the full reg or low/high part 
	 */
	// NOTE(cdecompilador): Here your are using anonymous structs which are a 
	// C11 extension, son in the CMakeLists.txt is declered as required
	union {
		struct { uint8_t F; uint8_t A; };
		uint16_t AF;
	};
	union {
		struct { uint8_t C; uint8_t B; };
		uint16_t BC;
	};
	// FIXME(cdecompilador): In the original source instead of ED is DE, was
	// that intended or an error?
	union { 
		struct { uint8_t D; uint8_t E; };
		uint16_t ED;
	};
	union {
		struct { uint8_t L; uint8_t H; };
		uint16_t HL;
	};

	/* Stack pointer register */
	uint16_t SP;

	/* Program counter register */
	uint16_t PC;

	bool interrupt;

	uint16_t tick;
};

// NOTE(cdecompilador): Constants that are used across multriple units shouldn't
// be declared as constants (in c) beacuse they get duplicated in the units, in
// some compilers this is an error in other it isn't, the solution is to use 
// macros or extern keyword.

/* Flags */
#define Z_flag (1 << 7)
#define N_flag (1 << 6)
#define H_flag (1 << 5)
#define C_flag (1 << 4)

/* Retieves an instructions/immediate, the MMU is constant because no 
 * write to it is needed */
uint8_t CPU_fetch(CPU* cpu, const MMU* mmu);

/* Executes the instructions */
void CPU_decode_execute(uint8_t opcode, CPU* cpu, MMU* mmu);
void CPU_decode_execute_prefix(uint8_t opcode, CPU* cpu, MMU* mmu);

#endif
