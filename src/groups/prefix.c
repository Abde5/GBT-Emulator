#include "prefix.h"

void Rlc(unsigned char* reg, struct CPU* cpu){
     unsigned char msb = (*reg) & 0x80;
     *reg = (*reg) << 1;

     unsigned char carry = 0x00;
     unsigned char zero = 0x00;

     if (msb){
          carry = C_flag;
          *reg = (*reg) | 0x01;
     }

     if (*reg == 0){
          zero = Z_flag;
     }

     (*cpu).F = zero | carry;
}

void Rlc00(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLC B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rlc(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Rlc01(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLC C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rlc(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Rlc02(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLC D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rlc(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Rlc03(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLC E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rlc(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Rlc04(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLC H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rlc(&(*cpu).H, cpu);
    (*cpu).tick += 8;
}

void Rlc05(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLC L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rlc(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Rlc06(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLC (HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 0 C
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Rlc(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Rlc07(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLC A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rlc(&(*cpu).A, cpu);
    (*cpu).tick += 8;
}

void Rrc(unsigned char* reg, struct CPU* cpu){
     unsigned char lsb = (*reg) & 0x01;
     *reg = (*reg) >> 1;

     unsigned char carry = 0x00;
     unsigned char zero = 0x00;

     if (lsb){
          carry = C_flag;
          *reg = (*reg) | 0x80;
     }

     if (*reg == 0){
          zero = Z_flag;
     }

     (*cpu).F = zero | carry;
}

void Rrc08(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRC B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rrc(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Rrc09(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRC C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rrc(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Rrc0A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRC D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rrc(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Rrc0B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRC E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rrc(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Rrc0C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRC H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rrc(&(*cpu).H, cpu);
    (*cpu).tick += 8;
}

void Rrc0D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRC L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rrc(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Rrc0E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRC (HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 0 C
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Rlc(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Rrc0F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRC A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rrc(&(*cpu).A, cpu);
    (*cpu).tick += 8;
}

void Rl(unsigned char* reg, struct CPU* cpu){
     unsigned char msb = (*reg) & 0x80;
     *reg = (*reg) << 1;

     unsigned char carry = 0x00;
     unsigned char zero = 0x00;

     if (msb){
         carry = C_flag;
     }

     if((*cpu).F & C_flag){
         *reg = (*reg) | 0x01;
     }

     if (*reg == 0){
         zero = Z_flag;
     }

     (*cpu).F = zero | carry;
}

void Rl10(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RL B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rl(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Rl11(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RL C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rl(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Rl12(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RL D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rl(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Rl13(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RL E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rl(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Rl14(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RL H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rl(&(*cpu).H, cpu);
    (*cpu).tick += 8;
}

void Rl15(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RL L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rl(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Rl16(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RL (HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 0 C
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Rl(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Rl17(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RL A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rl(&(*cpu).A, cpu);
    (*cpu).tick += 8;
}

void Rr(unsigned char* reg, struct CPU* cpu){
    unsigned char lsb = (*reg) & 0x01;
    *reg = (*reg) >> 1;

    unsigned char carry = 0x00;
    unsigned char zero = 0x00;

    if (lsb){
         carry = C_flag;
    }

    if((*cpu).F & C_flag){
         *reg = (*reg) | 0x80;
    }

    if (*reg == 0){
         zero = Z_flag;
    }

    (*cpu).F = zero | carry;
}

void Rr18(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RR B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rr(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Rr19(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RR C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rr(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Rr1A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RR D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rr(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Rr1B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RR E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rr(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Rr1C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RR H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rr(&(*cpu).H, cpu);
    (*cpu).tick += 8;
}

void Rr1D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RR L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rr(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Rr1E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RR (HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 0 C
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Rr(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Rr1F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RR A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rr(&(*cpu).A, cpu);
    (*cpu).tick += 8;
}

void Sla(unsigned char* reg, struct CPU* cpu){
     unsigned char msb = (*reg) & 0x80;
     *reg = (*reg) << 1;

     unsigned char carry = 0x00;
     unsigned char zero = 0x00;

     if (*reg == 0){
          zero = Z_flag;
     }

     if (msb){
          carry = C_flag;
     }

     (*cpu).F = zero | carry;
}

void Sla20(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SLA B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sla(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Sla21(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SLA C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sla(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Sla22(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SLA D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sla(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Sla23(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SLA E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sla(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Sla24(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SLA H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sla(&(*cpu).H, cpu);
    (*cpu).tick += 8;
}

void Sla25(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SLA L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sla(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Sla26(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SLA (HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 0 C
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Sla(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Sla27(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SLA A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sla(&(*cpu).A, cpu);
    (*cpu).tick += 8;
}

void Sra(unsigned char* reg, struct CPU* cpu){
     unsigned char lsb = (*reg) & 0x01;
     unsigned char msb = (*reg) & 0x80;
     *reg = ((*reg) >> 1) | msb;

     unsigned char carry = 0x00;
     unsigned char zero = 0x00;

     if (*reg == 0){
          zero = Z_flag;
     }

     if (lsb){
          carry = C_flag;
     }

     (*cpu).F = zero | carry;
}

void Sra28(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRA B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sra(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Sra29(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRA C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sra(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Sra2A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRA D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sra(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Sra2B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRA E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 0
    Sra(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Sra2C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRA H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 0
    Sra(&(*cpu).H, cpu);
    (*cpu).tick += 8;
}

void Sra2D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRA L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 0
    Sra(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Sra2E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRA (HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 0 0
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Sra(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Sra2F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRA A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 0
    Sra(&(*cpu).A, cpu);
    (*cpu).tick += 8;
}

void Swap(unsigned char* reg, struct CPU* cpu){
     unsigned char zero = 0x00;
     *reg = (*reg) << 4 | (*reg) >> 4;

     if (*reg == 0){
          zero = Z_flag;
     }

     (*cpu).F = zero ;
}

void Swap30(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SWAP B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 0
    Swap(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Swap31(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SWAP C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 0
    Swap(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Swap32(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SWAP D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 0
    Swap(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Swap33(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SWAP E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 0
    Swap(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Swap34(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SWAP H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 0
     Swap(&(*cpu).H, cpu);
     (*cpu).tick += 8;
}

void Swap35(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SWAP L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 0
    Swap(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Swap36(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SWAP (HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 0 0
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Swap(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Swap37(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SWAP A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 0
    Swap(&(*cpu).A, cpu);
    (*cpu).tick += 8;
}

void Srl(unsigned char* reg, struct CPU* cpu){
    unsigned char lsb = (*reg) & 0x01;
    *reg = (*reg) >> 1;

    unsigned char carry = 0x00;
    unsigned char zero = 0x00;

    if (*reg == 0){
         zero = Z_flag;
    }

    if (lsb){
         carry = C_flag;
    }

    (*cpu).F = zero | carry;
}

void Srl38(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRL B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Srl(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Srl39(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRL C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Srl(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Srl3A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRL D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Srl(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Srl3B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRL E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Srl(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Srl3C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRL H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Srl(&(*cpu).H, cpu);
    (*cpu).tick += 8;
}

void Srl3D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRL L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Srl(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Srl3E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRL (HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 0 C
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Srl(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 8;
}

void Srl3F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRL A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 C
    Srl(&(*cpu).A, cpu);
    (*cpu).tick += 8;
}

void Bit40(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit40)");
}

void Bit41(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit41)");
}

void Bit42(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit42)");
}

void Bit43(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit43)");
}

void Bit44(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit44)");
}

void Bit45(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit45)");
}

void Bit46(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,(HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit46)");
}

void Bit47(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit47)");
}

void Bit48(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit48)");
}

void Bit49(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit49)");
}

void Bit4A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit4A)");
}

void Bit4B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit4B)");
}

void Bit4C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit4C)");
}

void Bit4D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit4D)");
}

void Bit4E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,(HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit4E)");
}

void Bit4F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit4F)");
}

void Bit50(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit50)");
}

void Bit51(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit51)");
}

void Bit52(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit52)");
}

void Bit53(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit53)");
}

void Bit54(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit54)");
}

void Bit55(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit55)");
}

void Bit56(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,(HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit56)");
}

void Bit57(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit57)");
}

void Bit58(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit58)");
}

void Bit59(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit59)");
}

void Bit5A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit5A)");
}

void Bit5B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit5B)");
}

void Bit5C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit5C)");
}

void Bit5D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit5D)");
}

void Bit5E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,(HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit5E)");
}

void Bit5F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit5F)");
}

void Bit60(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit60)");
}

void Bit61(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit61)");
}

void Bit62(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit62)");
}

void Bit63(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit63)");
}

void Bit64(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit64)");
}

void Bit65(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit65)");
}

void Bit66(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,(HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit66)");
}

void Bit67(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit67)");
}

void Bit68(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit68)");
}

void Bit69(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit69)");
}

void Bit6A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit6A)");
}

void Bit6B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit6B)");
}

void Bit6C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit6C)");
}

void Bit6D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit6D)");
}

void Bit6E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,(HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit6E)");
}

void Bit6F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit6F)");
}

void Bit70(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit70)");
}

void Bit71(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit71)");
}

void Bit72(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit72)");
}

void Bit73(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit73)");
}

void Bit74(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit74)");
}

void Bit75(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit75)");
}

void Bit76(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,(HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit76)");
}

void Bit77(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit77)");
}

void Bit78(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,B, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit78)");
}

void Bit79(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,C, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit79)");
}

void Bit7A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,D, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit7A)");
}

void Bit7B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,E, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit7B)");
}

void Bit7C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,H, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit7C)");
}

void Bit7D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,L, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit7D)");
}

void Bit7E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,(HL), Length: 2
    // Cycles: 16, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit7E)");
}

void Bit7F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,A, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 -
    printf("Not implemented! (Bit7F)");
}

void Res80(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res80)");
}

void Res81(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res81)");
}

void Res82(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res82)");
}

void Res83(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res83)");
}

void Res84(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res84)");
}

void Res85(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res85)");
}

void Res86(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (Res86)");
}

void Res87(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res87)");
}

void Res88(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res88)");
}

void Res89(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res89)");
}

void Res8A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res8A)");
}

void Res8B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res8B)");
}

void Res8C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res8C)");
}

void Res8D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res8D)");
}

void Res8E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (Res8E)");
}

void Res8F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res8F)");
}

void Res90(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res90)");
}

void Res91(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res91)");
}

void Res92(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res92)");
}

void Res93(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res93)");
}

void Res94(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res94)");
}

void Res95(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res95)");
}

void Res96(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (Res96)");
}

void Res97(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res97)");
}

void Res98(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res98)");
}

void Res99(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res99)");
}

void Res9A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res9A)");
}

void Res9B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res9B)");
}

void Res9C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res9C)");
}

void Res9D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res9D)");
}

void Res9E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (Res9E)");
}

void Res9F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Res9F)");
}

void ResA0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResA0)");
}

void ResA1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResA1)");
}

void ResA2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResA2)");
}

void ResA3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResA3)");
}

void ResA4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResA4)");
}

void ResA5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResA5)");
}

void ResA6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (ResA6)");
}

void ResA7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResA7)");
}

void ResA8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResA8)");
}

void ResA9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResA9)");
}

void ResAA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResAA)");
}

void ResAB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResAB)");
}

void ResAC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResAC)");
}

void ResAD(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResAD)");
}

void ResAE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (ResAE)");
}

void ResAF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResAF)");
}

void ResB0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResB0)");
}

void ResB1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResB1)");
}

void ResB2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResB2)");
}

void ResB3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResB3)");
}

void ResB4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResB4)");
}

void ResB5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResB5)");
}

void ResB6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (ResB6)");
}

void ResB7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResB7)");
}

void ResB8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResB8)");
}

void ResB9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResB9)");
}

void ResBA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResBA)");
}

void ResBB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResBB)");
}

void ResBC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResBC)");
}

void ResBD(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResBD)");
}

void ResBE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (ResBE)");
}

void ResBF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (ResBF)");
}

void SetC0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetC0)");
}

void SetC1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetC1)");
}

void SetC2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetC2)");
}

void SetC3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetC3)");
}

void SetC4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetC4)");
}

void SetC5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetC5)");
}

void SetC6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (SetC6)");
}

void SetC7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetC7)");
}

void SetC8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetC8)");
}

void SetC9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetC9)");
}

void SetCA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetCA)");
}

void SetCB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetCB)");
}

void SetCC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetCC)");
}

void SetCD(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetCD)");
}

void SetCE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (SetCE)");
}

void SetCF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetCF)");
}

void SetD0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetD0)");
}

void SetD1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetD1)");
}

void SetD2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetD2)");
}

void SetD3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetD3)");
}

void SetD4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetD4)");
}

void SetD5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetD5)");
}

void SetD6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (SetD6)");
}

void SetD7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetD7)");
}

void SetD8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetD8)");
}

void SetD9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetD9)");
}

void SetDA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetDA)");
}

void SetDB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetDB)");
}

void SetDC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetDC)");
}

void SetDD(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetDD)");
}

void SetDE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (SetDE)");
}

void SetDF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetDF)");
}

void SetE0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetE0)");
}

void SetE1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetE1)");
}

void SetE2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetE2)");
}

void SetE3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetE3)");
}

void SetE4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetE4)");
}

void SetE5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetE5)");
}

void SetE6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (SetE6)");
}

void SetE7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetE7)");
}

void SetE8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetE8)");
}

void SetE9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetE9)");
}

void SetEA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetEA)");
}

void SetEB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetEB)");
}

void SetEC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetEC)");
}

void SetED(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetED)");
}

void SetEE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (SetEE)");
}

void SetEF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetEF)");
}

void SetF0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetF0)");
}

void SetF1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetF1)");
}

void SetF2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetF2)");
}

void SetF3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetF3)");
}

void SetF4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetF4)");
}

void SetF5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetF5)");
}

void SetF6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (SetF6)");
}

void SetF7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetF7)");
}

void SetF8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,B, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetF8)");
}

void SetF9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,C, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetF9)");
}

void SetFA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,D, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetFA)");
}

void SetFB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,E, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetFB)");
}

void SetFC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,H, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetFC)");
}

void SetFD(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,L, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetFD)");
}

void SetFE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,(HL), Length: 2
    // Cycles: 16, (Z N H C): - - - -
    printf("Not implemented! (SetFE)");
}

void SetFF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,A, Length: 2
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (SetFF)");
}

