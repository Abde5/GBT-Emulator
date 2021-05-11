#ifndef MISC_H
#define MISC_H

#include "../cpu.h"
#include "../mmu.h"

/*
 * NOP operation.
 */
void Nop00(struct CPU* cpu, struct MMU* mmu);

/*
 * Rotate register A left by adding carry flag.
 */
void Rlca07(struct CPU* cpu, struct MMU* mmu);

/*
 * Rotate register A right by adding carry flag.
 */
void Rrca0F(struct CPU* cpu, struct MMU* mmu);

/*
 * STOP command -> halts gameboy proc + screen until button pressed.
 */
void Stop10(struct CPU* cpu, struct MMU* mmu);

/*
 * Rotate register A left to carry flag.
 */
void Rla17(struct CPU* cpu, struct MMU* mmu);

/*
 * Rotate register A right to carry flag.
 */
void Rra1F(struct CPU* cpu, struct MMU* mmu);

/*
 * Stops CPU until interrupts occurs.
 */
void Halt76(struct CPU* cpu, struct MMU* mmu);

/*
 * Disable interrupts after next operation.
 */
void DiF3(struct CPU* cpu, struct MMU* mmu);

/*
 * Enable interrupts after next operation.
 */
void EiFB(struct CPU* cpu, struct MMU* mmu);

/*
 * Next instruction is prefixed.
 */
void PrefCB(struct CPU* cpu, struct MMU* mmu);


#endif // MISC_H
