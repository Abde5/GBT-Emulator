#include "misc.h"
#include "prefix.h"
#include "../cpu.h"

void Nop00(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: NOP, Length: 1
#ifdef DEBUG
    printf("NOP");
#endif
    // Cycles: 4, (Z N H C): - - - -
    printf("Not implemented! (Nop00)");
}

void Rlca07(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLCA, Length: 1
#ifdef DEBUG
    printf("RLCA");
#endif
    // Cycles: 4, (Z N H C): 0 0 0 C
    Rlc(&(*cpu).A, cpu);
    (*cpu).tick += 4;
}

void Rrca0F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRCA, Length: 1
#ifdef DEBUG
    printf("RRCA");
#endif
    // Cycles: 4, (Z N H C): 0 0 0 C
    Rrc(&(*cpu).A, cpu);
    (*cpu).tick += 4;
}

void Stop10(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: STOP 0, Length: 2
#ifdef DEBUG
    printf("STOP 0");
#endif
    // Cycles: 4, (Z N H C): - - - -
    printf("Not implemented! (Stop10)");
}

void Rla17(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLA, Length: 1
#ifdef DEBUG
    printf("RLA");
#endif
    // Cycles: 4, (Z N H C): 0 0 0 C
    Rl(&(*cpu).A, cpu);
    (*cpu).tick += 4;
}

void Rra1F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRA, Length: 1
#ifdef DEBUG
    printf("RRA");
#endif
    // Cycles: 4, (Z N H C): 0 0 0 C
    Rr(&(*cpu).A, cpu);
    (*cpu).tick += 4;
}

void Halt76(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: HALT, Length: 1
#ifdef DEBUG
    printf("HALT");
#endif
    // Cycles: 4, (Z N H C): - - - -
    printf("Not implemented! (Halt76)");
}

void DiF3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DI, Length: 1
#ifdef DEBUG
    printf("DI");
#endif
    // Cycles: 4, (Z N H C): - - - -
    printf("Not implemented! (DiF3)");
}

void EiFB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: EI, Length: 1
#ifdef DEBUG
    printf("EI");
#endif
    // Cycles: 4, (Z N H C): - - - -
    printf("Not implemented! (EiFB)");
}

void PrefCB(struct CPU* cpu, struct MMU* mmu){
     unsigned char read_byte = mmu_read(mmu,(*cpu).PC++);
     CPU_decode_execute_prefix(read_byte, cpu,  mmu);
}
