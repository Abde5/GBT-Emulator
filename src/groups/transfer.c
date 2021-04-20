#include "transfer.h"

void Ld_8(unsigned char * A, unsigned char * B, struct CPU* cpu){
    // Generic function to LD B into A.
    (*A) = (*B);
    (*cpu).tick += 4;
}

void Ld_16(unsigned short * A, unsigned short * B, struct CPU* cpu){
     // Generic function to LD B into A.
     (*A) = (*B);
     (*cpu).tick += 8;
}

void Ld01(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD BC,d16, Length: 3
    // Cycles: 12, (Z N H C): - - - -
    unsigned short d16 = mmu_read_16(mmu,(*cpu).PC);
    (*cpu).PC += 2;
    Ld_16(&(*cpu).BC,&d16, cpu);

    (*cpu).tick += 4;
}

void Ld02(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD (BC),A, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    mmu_write(mmu,(*cpu).BC, (*cpu).A);
    (*cpu).tick += 8;
}

void Ld06(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD B,d8, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).PC++);
    Ld_8(&(*cpu).B,&d8, cpu);

    (*cpu).tick += 4;
}

void Ld08(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD (a16),SP, Length: 3
    // Cycles: 20, (Z N H C): - - - -

    unsigned short d16 = mmu_read_16(mmu,(*cpu).PC);
    (*cpu).PC += 2;

    mmu_write(mmu,d16, (*cpu).SP);
    (*cpu).tick += 20;
}

void Ld0A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD A,(BC), Length: 1
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).BC);
    Ld_8(&(*cpu).A,&d8, cpu);

    (*cpu).tick += 4;
}

void Ld0E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD C,d8, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).PC++);
    Ld_8(&(*cpu).C,&d8, cpu);

    (*cpu).tick += 4;
}

void Ld11(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD DE,d16, Length: 3
    // Cycles: 12, (Z N H C): - - - -
    unsigned short d16 = mmu_read_16(mmu,(*cpu).PC);
    (*cpu).PC += 2;
    Ld_16(&(*cpu).DE,&d16, cpu);

    (*cpu).tick += 4;
}

void Ld12(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD (DE),A, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    mmu_write(mmu,(*cpu).DE, (*cpu).A);
    (*cpu).tick += 8;
}

void Ld16(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD D,d8, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).PC++);
    Ld_8(&(*cpu).D,&d8, cpu);

    (*cpu).tick += 4;
}

void Ld1A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD A,(DE), Length: 1
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).DE);
    Ld_8(&(*cpu).A,&d8, cpu);

    (*cpu).tick += 4;
}

void Ld1E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD E,d8, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).PC++);
    Ld_8(&(*cpu).E,&d8, cpu);

    (*cpu).tick += 4;
}

void Ld21(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD HL,d16, Length: 3
    // Cycles: 12, (Z N H C): - - - -
     unsigned short d16 = mmu_read_16(mmu,(*cpu).PC);
     (*cpu).PC += 2;
     Ld_16(&(*cpu).HL,&d16, cpu);

     (*cpu).tick += 4;
}

void Ld22(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD (HL+),A, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    mmu_write(mmu,(*cpu).HL++, (*cpu).A);
    (*cpu).tick += 8;
}

void Ld26(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD H,d8, Length: 2
    // Cycles: 8, (Z N H C): - - - -
     unsigned char d8 = mmu_read(mmu,(*cpu).PC++);
     Ld_8(&(*cpu).H,&d8, cpu);

     (*cpu).tick += 4;
}

void Ld2A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD A,(HL+), Length: 1
    // Cycles: 8, (Z N H C): - - - -
     unsigned char d8 = mmu_read(mmu,(*cpu).HL++);
     Ld_8(&(*cpu).A,&d8, cpu);

     (*cpu).tick += 4;
}

void Ld2E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD L,d8, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).PC++);
    Ld_8(&(*cpu).L,&d8, cpu);

    (*cpu).tick += 4;
}

void Ld31(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD SP,d16, Length: 3
    // Cycles: 12, (Z N H C): - - - -
     unsigned short d16 = mmu_read_16(mmu,(*cpu).PC);
     (*cpu).PC += 2;
     Ld_16(&(*cpu).SP,&d16, cpu);

     (*cpu).tick += 4;
}

void Ld32(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD (HL-),A, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    mmu_write(mmu,(*cpu).HL--, (*cpu).A);
    (*cpu).tick += 8;
}

void Ld36(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD (HL),d8, Length: 2
    // Cycles: 12, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).PC++);
    mmu_write(mmu,(*cpu).HL, d8);
    (*cpu).tick += 8;
}

void Ld3A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD A,(HL-), Length: 1
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).HL--);
    Ld_8(&(*cpu).A,&d8, cpu);

    (*cpu).tick += 4;
}

void Ld3E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD A,d8, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).PC++);
    Ld_8(&(*cpu).A,&d8, cpu);

    (*cpu).tick += 4;
}

void Ld40(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD B,B, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).B,&(*cpu).B, cpu);
}

void Ld41(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD B,C, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).B,&(*cpu).C, cpu);
}

void Ld42(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD B,D, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).B,&(*cpu).D, cpu);
}

void Ld43(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD B,E, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).B,&(*cpu).E, cpu);
}

void Ld44(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD B,H, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).B,&(*cpu).H, cpu);
}

void Ld45(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD B,L, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).B,&(*cpu).L, cpu);
}

void Ld46(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD B,(HL), Length: 1
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).HL);
    Ld_8(&(*cpu).B,&d8, cpu);

    (*cpu).tick += 4;
}

void Ld47(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD B,A, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).B,&(*cpu).A, cpu);
}

void Ld48(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD C,B, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).C,&(*cpu).B, cpu);
}

void Ld49(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD C,C, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).C,&(*cpu).C, cpu);
}

void Ld4A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD C,D, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).C,&(*cpu).D, cpu);
}

void Ld4B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD C,E, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).C,&(*cpu).E, cpu);
}

void Ld4C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD C,H, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).C,&(*cpu).H, cpu);
}

void Ld4D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD C,L, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).C,&(*cpu).L, cpu);
}

void Ld4E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD C,(HL), Length: 1
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).HL);
    Ld_8(&(*cpu).C,&d8, cpu);

    (*cpu).tick += 4;
}

void Ld4F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD C,A, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).C,&(*cpu).A, cpu);
}

void Ld50(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD D,B, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).D,&(*cpu).B, cpu);
}

void Ld51(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD D,C, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).D,&(*cpu).C, cpu);
}

void Ld52(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD D,D, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).D,&(*cpu).D, cpu);
}

void Ld53(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD D,E, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).D,&(*cpu).E, cpu);
}

void Ld54(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD D,H, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).D,&(*cpu).H, cpu);
}

void Ld55(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD D,L, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).D,&(*cpu).L, cpu);
}

void Ld56(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD D,(HL), Length: 1
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).HL);
    Ld_8(&(*cpu).D,&d8, cpu);

    (*cpu).tick += 4;
}

void Ld57(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD D,A, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).D,&(*cpu).A, cpu);
}

void Ld58(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD E,B, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).E,&(*cpu).B, cpu);
}

void Ld59(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD E,C, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).E,&(*cpu).C, cpu);
}

void Ld5A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD E,D, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).E,&(*cpu).D, cpu);
}

void Ld5B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD E,E, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).E,&(*cpu).E, cpu);
}

void Ld5C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD E,H, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).E,&(*cpu).H, cpu);
}

void Ld5D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD E,L, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).E,&(*cpu).L, cpu);
}

void Ld5E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD E,(HL), Length: 1
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).HL);
    Ld_8(&(*cpu).E,&d8, cpu);

    (*cpu).tick += 4;

}

void Ld5F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD E,A, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).E,&(*cpu).A, cpu);
}

void Ld60(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD H,B, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).H,&(*cpu).B, cpu);
}

void Ld61(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD H,C, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).H,&(*cpu).C, cpu);
}

void Ld62(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD H,D, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).H,&(*cpu).D, cpu);
}

void Ld63(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD H,E, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).H,&(*cpu).E, cpu);
}

void Ld64(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD H,H, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).H,&(*cpu).H, cpu);
}

void Ld65(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD H,L, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).H,&(*cpu).L, cpu);
}

void Ld66(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD H,(HL), Length: 1
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).HL);
    Ld_8(&(*cpu).H,&d8, cpu);

    (*cpu).tick += 4;
}

void Ld67(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD H,A, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).H,&(*cpu).A, cpu);
}

void Ld68(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD L,B, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).L,&(*cpu).B, cpu);
}

void Ld69(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD L,C, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).L,&(*cpu).C, cpu);
}

void Ld6A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD L,D, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).L,&(*cpu).D, cpu);
}

void Ld6B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD L,E, Length: 1
    // Cycles: 4, (Z N H C): - - - -
     Ld_8(&(*cpu).L,&(*cpu).E, cpu);
}

void Ld6C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD L,H, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).L,&(*cpu).H, cpu);
}

void Ld6D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD L,L, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).L,&(*cpu).L, cpu);
}

void Ld6E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD L,(HL), Length: 1
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).HL);
    Ld_8(&(*cpu).L,&d8, cpu);

    (*cpu).tick += 4;
}

void Ld6F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD L,A, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).L,&(*cpu).A, cpu);
}

void Ld70(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD (HL),B, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    mmu_write(mmu,(*cpu).HL, (*cpu).B);
    (*cpu).tick += 8;
}

void Ld71(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD (HL),C, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    mmu_write(mmu,(*cpu).HL, (*cpu).C);
    (*cpu).tick += 8;
}

void Ld72(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD (HL),D, Length: 1
    // Cycles: 8, (Z N H C): - - - -
     mmu_write(mmu,(*cpu).HL, (*cpu).D);
     (*cpu).tick += 8;
}

void Ld73(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD (HL),E, Length: 1
    // Cycles: 8, (Z N H C): - - - -
     mmu_write(mmu,(*cpu).HL, (*cpu).E);
     (*cpu).tick += 8;
}

void Ld74(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD (HL),H, Length: 1
    // Cycles: 8, (Z N H C): - - - -
     mmu_write(mmu,(*cpu).HL, (*cpu).H);
     (*cpu).tick += 8;
}

void Ld75(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD (HL),L, Length: 1
    // Cycles: 8, (Z N H C): - - - -
     mmu_write(mmu,(*cpu).HL, (*cpu).L);
     (*cpu).tick += 8;
}

void Ld77(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD (HL),A, Length: 1
    // Cycles: 8, (Z N H C): - - - -
     mmu_write(mmu,(*cpu).HL, (*cpu).A);
     (*cpu).tick += 8;
}

void Ld78(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD A,B, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).A,&(*cpu).B, cpu);
}

void Ld79(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD A,C, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).A,&(*cpu).C, cpu);
}

void Ld7A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD A,D, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).A,&(*cpu).D, cpu);
}

void Ld7B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD A,E, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).A,&(*cpu).E, cpu);
}

void Ld7C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD A,H, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).A,&(*cpu).H, cpu);
}

void Ld7D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD A,L, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).A,&(*cpu).L, cpu);
}

void Ld7E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD A,(HL), Length: 1
    // Cycles: 8, (Z N H C): - - - -
    unsigned char d8 = mmu_read(mmu,(*cpu).HL);
    Ld_8(&(*cpu).A,&d8, cpu);

    (*cpu).tick += 4;
}

void Ld7F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD A,A, Length: 1
    // Cycles: 4, (Z N H C): - - - -
    Ld_8(&(*cpu).A,&(*cpu).A, cpu);
}

void LdE2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD (C),A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (LdE2)");
}

void LdEA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD (a16),A, Length: 3
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (LdEA)");
}

void LdF2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD A,(C), Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (LdF2)");
}

void LdF8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD HL,SP+r8, Length: 2
    // Cycles: 12, (Z N H C): 0 0 H C
    printf("Not implemented! (LdF8)");
}

void LdF9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD SP,HL, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (LdF9)");
}

void LdFA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LD A,(a16), Length: 3
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (LdFA)");
}

void PopC1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: POP BC, Length: 1
    // Cycles: 12, (Z N H C): - - - -
    printf("Not implemented! (PopC1)");
}

void PopD1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: POP DE, Length: 1
    // Cycles: 12, (Z N H C): - - - -
    printf("Not implemented! (PopD1)");
}

void PopE1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: POP HL, Length: 1
    // Cycles: 12, (Z N H C): - - - -
    printf("Not implemented! (PopE1)");
}

void PopF1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: POP AF, Length: 1
    // Cycles: 12, (Z N H C): Z N H C
    printf("Not implemented! (PopF1)");
}

void PushC5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: PUSH BC, Length: 1
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (PushC5)");
}

void PushD5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: PUSH DE, Length: 1
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (PushD5)");
}

void PushE5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: PUSH HL, Length: 1
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (PushE5)");
}

void PushF5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: PUSH AF, Length: 1
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (PushF5)");
}

void LdhE0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LDH (a8),A, Length: 2
    // Cycles: 12, (Z N H C): - - - -
    printf("Not implemented! (LdhE0)");
}

void LdhF0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: LDH A,(a8), Length: 2
    // Cycles: 12, (Z N H C): - - - -
    printf("Not implemented! (LdhF0)");
}

