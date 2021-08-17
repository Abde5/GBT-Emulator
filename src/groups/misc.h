#ifndef MISC_H
#define MISC_H

#include "../cpu.h"
#include "../mmu.h"

/*
 * NOP operation.
 */
void Nop00(CPU* cpu, MMU* mmu);

/*
 * Rotate register A left by adding carry flag.
 */
void Rlca07(CPU* cpu, MMU* mmu);

/*
 * Rotate register A right by adding carry flag.
 */
void Rrca0F(CPU* cpu, MMU* mmu);

/*
 * STOP command -> halts gameboy proc + screen until button pressed.
 */
void Stop10(CPU* cpu, MMU* mmu);

/*
 * Rotate register A left to carry flag.
 */
void Rla17(CPU* cpu, MMU* mmu);

/*
 * Rotate register A right to carry flag.
 */
void Rra1F(CPU* cpu, MMU* mmu);

/*
 * Stops CPU until interrupts occurs.
 */
void Halt76(CPU* cpu, MMU* mmu);

/*
 * Disable interrupts after next operation.
 */
void DiF3(CPU* cpu, MMU* mmu);

/*
 * Enable interrupts after next operation.
 */
void EiFB(CPU* cpu, MMU* mmu);

/*
 * Next instruction is prefixed.
 */
void PrefCB(CPU* cpu, MMU* mmu);


#endif // MISC_H
