#include "misc.h"
#include "prefix.h"

void Nop00(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: NOP, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    printf("Not implemented! (Nop00)");
}

void Rlca07(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLCA, Length: 1
    // Cycles: 4, (Z N H C): 0 0 0 C
    Rlc(&(*cpu).A, cpu);
    (*cpu).tick += 4;
}

void Rrca0F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRCA, Length: 1
    // Cycles: 4, (Z N H C): 0 0 0 C
    Rrc(&(*cpu).A, cpu);
    (*cpu).tick += 4;
}

void Stop10(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: STOP 0, Length: 2
    // Cycles: 4, (Z N H C): - - - -
    printf("Not implemented! (Stop10)");
}

void Rla17(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLA, Length: 1
    // Cycles: 4, (Z N H C): 0 0 0 C
    Rl(&(*cpu).A, cpu);
    (*cpu).tick += 4;
}

void Rra1F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRA, Length: 1
    // Cycles: 4, (Z N H C): 0 0 0 C
    Rr(&(*cpu).A, cpu);
    (*cpu).tick += 4;
}

void Halt76(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: HALT, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    printf("Not implemented! (Halt76)");
}

void DiF3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DI, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    printf("Not implemented! (DiF3)");
}

void EiFB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: EI, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    printf("Not implemented! (EiFB)");
}

