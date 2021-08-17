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
#ifdef DEBUG
    printf("RLC B");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rlc(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Rlc01(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLC C, Length: 2
#ifdef DEBUG
    printf("RLC C");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rlc(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Rlc02(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLC D, Length: 2
#ifdef DEBUG
    printf("RLC D");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rlc(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Rlc03(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLC E, Length: 2
#ifdef DEBUG
    printf("RLC E");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rlc(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Rlc04(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLC H, Length: 2
#ifdef DEBUG
    printf("RLC H");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rlc(&(*cpu).H, cpu);
    (*cpu).tick += 8;
}

void Rlc05(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLC L, Length: 2
#ifdef DEBUG
    printf("RLC L");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rlc(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Rlc06(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLC (HL), Length: 2
#ifdef DEBUG
    printf("RLC (HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 0 C
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Rlc(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Rlc07(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RLC A, Length: 2
#ifdef DEBUG
    printf("RLC A");
#endif
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
#ifdef DEBUG
    printf("RRC B");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rrc(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Rrc09(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRC C, Length: 2
#ifdef DEBUG
    printf("RRC C");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rrc(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Rrc0A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRC D, Length: 2
#ifdef DEBUG
    printf("RRC D");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rrc(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Rrc0B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRC E, Length: 2
#ifdef DEBUG
    printf("RRC E");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rrc(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Rrc0C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRC H, Length: 2
#ifdef DEBUG
    printf("RRC H");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rrc(&(*cpu).H, cpu);
    (*cpu).tick += 8;
}

void Rrc0D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRC L, Length: 2
#ifdef DEBUG
    printf("RRC L");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rrc(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Rrc0E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRC (HL), Length: 2
#ifdef DEBUG
    printf("RRC (HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 0 C
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Rlc(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Rrc0F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RRC A, Length: 2
#ifdef DEBUG
    printf("RRC A");
#endif
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
#ifdef DEBUG
    printf("RL B");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rl(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Rl11(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RL C, Length: 2
#ifdef DEBUG
    printf("RL C");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rl(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Rl12(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RL D, Length: 2
#ifdef DEBUG
    printf("RL D");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rl(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Rl13(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RL E, Length: 2
#ifdef DEBUG
    printf("RL E");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rl(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Rl14(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RL H, Length: 2
#ifdef DEBUG
    printf("RL H");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rl(&(*cpu).H, cpu);
    (*cpu).tick += 8;
}

void Rl15(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RL L, Length: 2
#ifdef DEBUG
    printf("RL L");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rl(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Rl16(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RL (HL), Length: 2
#ifdef DEBUG
    printf("RL (HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 0 C
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Rl(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Rl17(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RL A, Length: 2
#ifdef DEBUG
    printf("RL A");
#endif
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
#ifdef DEBUG
    printf("RR B");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rr(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Rr19(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RR C, Length: 2
#ifdef DEBUG
    printf("RR C");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rr(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Rr1A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RR D, Length: 2
#ifdef DEBUG
    printf("RR D");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rr(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Rr1B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RR E, Length: 2
#ifdef DEBUG
    printf("RR E");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rr(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Rr1C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RR H, Length: 2
#ifdef DEBUG
    printf("RR H");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rr(&(*cpu).H, cpu);
    (*cpu).tick += 8;
}

void Rr1D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RR L, Length: 2
#ifdef DEBUG
    printf("RR L");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Rr(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Rr1E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RR (HL), Length: 2
#ifdef DEBUG
    printf("RR (HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 0 C
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Rr(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Rr1F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RR A, Length: 2
#ifdef DEBUG
    printf("RR A");
#endif
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
#ifdef DEBUG
    printf("SLA B");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sla(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Sla21(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SLA C, Length: 2
#ifdef DEBUG
    printf("SLA C");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sla(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Sla22(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SLA D, Length: 2
#ifdef DEBUG
    printf("SLA D");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sla(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Sla23(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SLA E, Length: 2
#ifdef DEBUG
    printf("SLA E");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sla(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Sla24(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SLA H, Length: 2
#ifdef DEBUG
    printf("SLA H");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sla(&(*cpu).H, cpu);
    (*cpu).tick += 8;
}

void Sla25(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SLA L, Length: 2
#ifdef DEBUG
    printf("SLA L");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sla(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Sla26(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SLA (HL), Length: 2
#ifdef DEBUG
    printf("SLA (HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 0 C
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Sla(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Sla27(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SLA A, Length: 2
#ifdef DEBUG
    printf("SLA A");
#endif
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
#ifdef DEBUG
    printf("SRA B");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sra(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Sra29(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRA C, Length: 2
#ifdef DEBUG
    printf("SRA C");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sra(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Sra2A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRA D, Length: 2
#ifdef DEBUG
    printf("SRA D");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Sra(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Sra2B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRA E, Length: 2
#ifdef DEBUG
    printf("SRA E");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 0
    Sra(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Sra2C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRA H, Length: 2
#ifdef DEBUG
    printf("SRA H");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 0
    Sra(&(*cpu).H, cpu);
    (*cpu).tick += 8;
}

void Sra2D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRA L, Length: 2
#ifdef DEBUG
    printf("SRA L");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 0
    Sra(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Sra2E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRA (HL), Length: 2
#ifdef DEBUG
    printf("SRA (HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 0 0
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Sra(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Sra2F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRA A, Length: 2
#ifdef DEBUG
    printf("SRA A");
#endif
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
#ifdef DEBUG
    printf("SWAP B");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 0
    Swap(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Swap31(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SWAP C, Length: 2
#ifdef DEBUG
    printf("SWAP C");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 0
    Swap(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Swap32(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SWAP D, Length: 2
#ifdef DEBUG
    printf("SWAP D");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 0
    Swap(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Swap33(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SWAP E, Length: 2
#ifdef DEBUG
    printf("SWAP E");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 0
    Swap(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Swap34(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SWAP H, Length: 2
#ifdef DEBUG
    printf("SWAP H");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 0
     Swap(&(*cpu).H, cpu);
     (*cpu).tick += 8;
}

void Swap35(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SWAP L, Length: 2
#ifdef DEBUG
    printf("SWAP L");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 0
    Swap(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Swap36(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SWAP (HL), Length: 2
#ifdef DEBUG
    printf("SWAP (HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 0 0
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Swap(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Swap37(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SWAP A, Length: 2
#ifdef DEBUG
    printf("SWAP A");
#endif
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
#ifdef DEBUG
    printf("SRL B");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Srl(&(*cpu).B, cpu);
    (*cpu).tick += 8;
}

void Srl39(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRL C, Length: 2
#ifdef DEBUG
    printf("SRL C");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Srl(&(*cpu).C, cpu);
    (*cpu).tick += 8;
}

void Srl3A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRL D, Length: 2
#ifdef DEBUG
    printf("SRL D");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Srl(&(*cpu).D, cpu);
    (*cpu).tick += 8;
}

void Srl3B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRL E, Length: 2
#ifdef DEBUG
    printf("SRL E");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Srl(&(*cpu).E, cpu);
    (*cpu).tick += 8;
}

void Srl3C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRL H, Length: 2
#ifdef DEBUG
    printf("SRL H");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Srl(&(*cpu).H, cpu);
    (*cpu).tick += 8;
}

void Srl3D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRL L, Length: 2
#ifdef DEBUG
    printf("SRL L");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Srl(&(*cpu).L, cpu);
    (*cpu).tick += 8;
}

void Srl3E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRL (HL), Length: 2
#ifdef DEBUG
    printf("SRL (HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 0 C
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Srl(&read_byte, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 8;
}

void Srl3F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SRL A, Length: 2
#ifdef DEBUG
    printf("SRL A");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 C
    Srl(&(*cpu).A, cpu);
    (*cpu).tick += 8;
}

void Bit(unsigned char* reg, unsigned char n, struct CPU* cpu)
{
    unsigned char zero = Z_flag;
    if ((*reg) & (1<<n)){
         zero = 0x00;
    }

    (*cpu).F = zero | ((*cpu).F & C_flag) | H_flag;
}

void Bit40(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,B, Length: 2
#ifdef DEBUG
    printf("BIT 0,B");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).B, 0,cpu);
    (*cpu).tick += 8;
}

void Bit41(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,C, Length: 2
#ifdef DEBUG
    printf("BIT 0,C");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).C, 0,cpu);
    (*cpu).tick += 8;
}

void Bit42(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,D, Length: 2
#ifdef DEBUG
    printf("BIT 0,D");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).D, 0,cpu);
    (*cpu).tick += 8;
}

void Bit43(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,E, Length: 2
#ifdef DEBUG
    printf("BIT 0,E");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).E, 0,cpu);
    (*cpu).tick += 8;
}

void Bit44(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,H, Length: 2
#ifdef DEBUG
    printf("BIT 0,H");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).H, 0,cpu);
    (*cpu).tick += 8;
}

void Bit45(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,L, Length: 2
#ifdef DEBUG
    printf("BIT 0,L");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).L, 0,cpu);
    (*cpu).tick += 8;
}

void Bit46(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,(HL), Length: 2
#ifdef DEBUG
    printf("BIT 0,(HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 1 -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Bit(&read_byte,0, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Bit47(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 0,A, Length: 2
#ifdef DEBUG
    printf("BIT 0,A");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).B,0, cpu);
    (*cpu).tick += 8;
}

void Bit48(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,B, Length: 2
#ifdef DEBUG
    printf("BIT 1,B");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).B, 1,cpu);
    (*cpu).tick += 8;
}

void Bit49(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,C, Length: 2
#ifdef DEBUG
    printf("BIT 1,C");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).C, 1,cpu);
    (*cpu).tick += 8;
}

void Bit4A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,D, Length: 2
#ifdef DEBUG
    printf("BIT 1,D");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).D, 1,cpu);
    (*cpu).tick += 8;
}

void Bit4B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,E, Length: 2
#ifdef DEBUG
    printf("BIT 1,E");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).E, 1,cpu);
    (*cpu).tick += 8;
}

void Bit4C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,H, Length: 2
#ifdef DEBUG
    printf("BIT 1,H");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).H, 1,cpu);
    (*cpu).tick += 8;
}

void Bit4D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,L, Length: 2
#ifdef DEBUG
    printf("BIT 1,L");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).L, 1,cpu);
    (*cpu).tick += 8;
}

void Bit4E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,(HL), Length: 2
#ifdef DEBUG
    printf("BIT 1,(HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 1 -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Bit(&read_byte,1, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Bit4F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 1,A, Length: 2
#ifdef DEBUG
    printf("BIT 1,A");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).A, 1,cpu);
    (*cpu).tick += 8;
}

void Bit50(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,B, Length: 2
#ifdef DEBUG
    printf("BIT 2,B");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).B, 2,cpu);
    (*cpu).tick += 8;
}

void Bit51(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,C, Length: 2
#ifdef DEBUG
    printf("BIT 2,C");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).C, 2,cpu);
    (*cpu).tick += 8;
}

void Bit52(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,D, Length: 2
#ifdef DEBUG
    printf("BIT 2,D");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).D, 2,cpu);
    (*cpu).tick += 8;
}

void Bit53(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,E, Length: 2
#ifdef DEBUG
    printf("BIT 2,E");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).E, 2,cpu);
    (*cpu).tick += 8;
}

void Bit54(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,H, Length: 2
#ifdef DEBUG
    printf("BIT 2,H");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).H, 2,cpu);
    (*cpu).tick += 8;
}

void Bit55(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,L, Length: 2
#ifdef DEBUG
    printf("BIT 2,L");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).L, 2,cpu);
    (*cpu).tick += 8;
}

void Bit56(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,(HL), Length: 2
#ifdef DEBUG
    printf("BIT 2,(HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 1 -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Bit(&read_byte, 2, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Bit57(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 2,A, Length: 2
#ifdef DEBUG
    printf("BIT 2,A");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).A, 2,cpu);
    (*cpu).tick += 8;
}

void Bit58(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,B, Length: 2
#ifdef DEBUG
    printf("BIT 3,B");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).B, 3,cpu);
    (*cpu).tick += 8;
}

void Bit59(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,C, Length: 2
#ifdef DEBUG
    printf("BIT 3,C");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).C, 3,cpu);
    (*cpu).tick += 8;
}

void Bit5A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,D, Length: 2
#ifdef DEBUG
    printf("BIT 3,D");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).D, 3,cpu);
    (*cpu).tick += 8;
}

void Bit5B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,E, Length: 2
#ifdef DEBUG
    printf("BIT 3,E");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).E, 3,cpu);
    (*cpu).tick += 8;
}

void Bit5C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,H, Length: 2
#ifdef DEBUG
    printf("BIT 3,H");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).H, 3,cpu);
    (*cpu).tick += 8;
}

void Bit5D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,L, Length: 2
#ifdef DEBUG
    printf("BIT 3,L");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).L, 3,cpu);
    (*cpu).tick += 8;
}

void Bit5E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,(HL), Length: 2
#ifdef DEBUG
    printf("BIT 3,(HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 1 -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Bit(&read_byte,3, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Bit5F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 3,A, Length: 2
#ifdef DEBUG
    printf("BIT 3,A");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).A, 3,cpu);
    (*cpu).tick += 8;
}

void Bit60(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,B, Length: 2
#ifdef DEBUG
    printf("BIT 4,B");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).B, 4,cpu);
    (*cpu).tick += 8;
}

void Bit61(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,C, Length: 2
#ifdef DEBUG
    printf("BIT 4,C");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).C, 4,cpu);
    (*cpu).tick += 8;
}

void Bit62(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,D, Length: 2
#ifdef DEBUG
    printf("BIT 4,D");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).D, 4,cpu);
    (*cpu).tick += 8;
}

void Bit63(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,E, Length: 2
#ifdef DEBUG
    printf("BIT 4,E");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).E, 4,cpu);
    (*cpu).tick += 8;
}

void Bit64(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,H, Length: 2
#ifdef DEBUG
    printf("BIT 4,H");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).H, 4,cpu);
    (*cpu).tick += 8;
}

void Bit65(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,L, Length: 2
#ifdef DEBUG
    printf("BIT 4,L");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).L, 4,cpu);
    (*cpu).tick += 8;
}

void Bit66(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,(HL), Length: 2
#ifdef DEBUG
    printf("BIT 4,(HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 1 -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Bit(&read_byte,4, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Bit67(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 4,A, Length: 2
#ifdef DEBUG
    printf("BIT 4,A");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).A, 4,cpu);
    (*cpu).tick += 8;
}

void Bit68(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,B, Length: 2
#ifdef DEBUG
    printf("BIT 5,B");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).B, 5,cpu);
    (*cpu).tick += 8;
}

void Bit69(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,C, Length: 2
#ifdef DEBUG
    printf("BIT 5,C");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).C, 5,cpu);
    (*cpu).tick += 8;
}

void Bit6A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,D, Length: 2
#ifdef DEBUG
    printf("BIT 5,D");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).D, 5,cpu);
    (*cpu).tick += 8;
}

void Bit6B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,E, Length: 2
#ifdef DEBUG
    printf("BIT 5,E");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).E, 5,cpu);
    (*cpu).tick += 8;
}

void Bit6C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,H, Length: 2
#ifdef DEBUG
    printf("BIT 5,H");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).H, 5,cpu);
    (*cpu).tick += 8;
}

void Bit6D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,L, Length: 2
#ifdef DEBUG
    printf("BIT 5,L");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).L, 5,cpu);
    (*cpu).tick += 8;
}

void Bit6E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,(HL), Length: 2
#ifdef DEBUG
    printf("BIT 5,(HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 1 -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Bit(&read_byte,5, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Bit6F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 5,A, Length: 2
#ifdef DEBUG
    printf("BIT 5,A");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).A, 5,cpu);
    (*cpu).tick += 8;
}

void Bit70(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,B, Length: 2
#ifdef DEBUG
    printf("BIT 6,B");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).B, 6,cpu);
    (*cpu).tick += 8;
}

void Bit71(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,C, Length: 2
#ifdef DEBUG
    printf("BIT 6,C");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).C, 6,cpu);
    (*cpu).tick += 8;
}

void Bit72(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,D, Length: 2
#ifdef DEBUG
    printf("BIT 6,D");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).D, 6,cpu);
    (*cpu).tick += 8;
}

void Bit73(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,E, Length: 2
#ifdef DEBUG
    printf("BIT 6,E");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).E, 6,cpu);
    (*cpu).tick += 8;
}

void Bit74(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,H, Length: 2
#ifdef DEBUG
    printf("BIT 6,H");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).H, 6,cpu);
    (*cpu).tick += 8;
}

void Bit75(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,L, Length: 2
#ifdef DEBUG
    printf("BIT 6,L");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).L, 6,cpu);
    (*cpu).tick += 8;
}

void Bit76(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,(HL), Length: 2
#ifdef DEBUG
    printf("BIT 6,(HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 1 -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Bit(&read_byte,6, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Bit77(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 6,A, Length: 2
#ifdef DEBUG
    printf("BIT 6,A");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).A, 6,cpu);
    (*cpu).tick += 8;
}

void Bit78(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,B, Length: 2
#ifdef DEBUG
    printf("BIT 7,B");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).B, 7,cpu);
    (*cpu).tick += 8;
}

void Bit79(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,C, Length: 2
#ifdef DEBUG
    printf("BIT 7,C");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).C, 7,cpu);
    (*cpu).tick += 8;
}

void Bit7A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,D, Length: 2
#ifdef DEBUG
    printf("BIT 7,D");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).D, 7,cpu);
    (*cpu).tick += 8;
}

void Bit7B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,E, Length: 2
#ifdef DEBUG
    printf("BIT 7,E");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).E, 7,cpu);
    (*cpu).tick += 8;
}

void Bit7C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,H, Length: 2
#ifdef DEBUG
    printf("BIT 7,H");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).H, 7,cpu);
    (*cpu).tick += 8;
}

void Bit7D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,L, Length: 2
#ifdef DEBUG
    printf("BIT 7,L");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).L, 7,cpu);
    (*cpu).tick += 8;
}

void Bit7E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,(HL), Length: 2
#ifdef DEBUG
    printf("BIT 7,(HL)");
#endif
    // Cycles: 16, (Z N H C): Z 0 1 -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Bit(&read_byte,7, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Bit7F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: BIT 7,A, Length: 2
#ifdef DEBUG
    printf("BIT 7,A");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 -
    Bit(&(*cpu).A, 7,cpu);
    (*cpu).tick += 8;
}

void Res(unsigned char* reg, unsigned char n, struct CPU* cpu)
{
     (*reg) &= ~(1<<n);
}


void Res80(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,B, Length: 2
#ifdef DEBUG
    printf("RES 0,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).B, 0,cpu);
    (*cpu).tick += 8;
}

void Res81(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,C, Length: 2
#ifdef DEBUG
    printf("RES 0,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).C, 0,cpu);
    (*cpu).tick += 8;
}

void Res82(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,D, Length: 2
#ifdef DEBUG
    printf("RES 0,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).D, 0,cpu);
    (*cpu).tick += 8;
}

void Res83(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,E, Length: 2
#ifdef DEBUG
    printf("RES 0,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).E, 0,cpu);
    (*cpu).tick += 8;
}

void Res84(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,H, Length: 2
#ifdef DEBUG
    printf("RES 0,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).H, 0,cpu);
    (*cpu).tick += 8;
}

void Res85(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,L, Length: 2
#ifdef DEBUG
    printf("RES 0,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).L, 0,cpu);
    (*cpu).tick += 8;
}

void Res86(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,(HL), Length: 2
#ifdef DEBUG
    printf("RES 0,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Res(&read_byte,0, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Res87(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 0,A, Length: 2
#ifdef DEBUG
    printf("RES 0,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).A, 0,cpu);
    (*cpu).tick += 8;
}

void Res88(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,B, Length: 2
#ifdef DEBUG
    printf("RES 1,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).B, 1, cpu);
    (*cpu).tick += 8;
}

void Res89(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,C, Length: 2
#ifdef DEBUG
    printf("RES 1,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).C, 1, cpu);
    (*cpu).tick += 8;
}

void Res8A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,D, Length: 2
#ifdef DEBUG
    printf("RES 1,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).D, 1, cpu);
    (*cpu).tick += 8;
}

void Res8B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,E, Length: 2
#ifdef DEBUG
    printf("RES 1,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).E, 1, cpu);
    (*cpu).tick += 8;
}

void Res8C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,H, Length: 2
#ifdef DEBUG
    printf("RES 1,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).H, 1, cpu);
    (*cpu).tick += 8;
}

void Res8D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,L, Length: 2
#ifdef DEBUG
    printf("RES 1,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).L, 1, cpu);
    (*cpu).tick += 8;
}

void Res8E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,(HL), Length: 2
#ifdef DEBUG
    printf("RES 1,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Res(&read_byte,1, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Res8F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 1,A, Length: 2
#ifdef DEBUG
    printf("RES 1,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).A, 1, cpu);
    (*cpu).tick += 8;
}

void Res90(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,B, Length: 2
#ifdef DEBUG
    printf("RES 2,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).B, 2, cpu);
    (*cpu).tick += 8;
}

void Res91(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,C, Length: 2
#ifdef DEBUG
    printf("RES 2,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).C, 2, cpu);
    (*cpu).tick += 8;
}

void Res92(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,D, Length: 2
#ifdef DEBUG
    printf("RES 2,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).D, 2, cpu);
    (*cpu).tick += 8;
}

void Res93(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,E, Length: 2
#ifdef DEBUG
    printf("RES 2,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).E, 2, cpu);
    (*cpu).tick += 8;
}

void Res94(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,H, Length: 2
#ifdef DEBUG
    printf("RES 2,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).H, 2, cpu);
    (*cpu).tick += 8;
}

void Res95(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,L, Length: 2
#ifdef DEBUG
    printf("RES 2,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).L, 2, cpu);
    (*cpu).tick += 8;
}

void Res96(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,(HL), Length: 2
#ifdef DEBUG
    printf("RES 2,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Res(&read_byte,2, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Res97(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 2,A, Length: 2
#ifdef DEBUG
    printf("RES 2,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).A, 2, cpu);
    (*cpu).tick += 8;
}

void Res98(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,B, Length: 2
#ifdef DEBUG
    printf("RES 3,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).B, 3, cpu);
    (*cpu).tick += 8;
}

void Res99(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,C, Length: 2
#ifdef DEBUG
    printf("RES 3,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).C, 3, cpu);
    (*cpu).tick += 8;
}

void Res9A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,D, Length: 2
#ifdef DEBUG
    printf("RES 3,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).D, 3, cpu);
    (*cpu).tick += 8;
}

void Res9B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,E, Length: 2
#ifdef DEBUG
    printf("RES 3,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).E, 3, cpu);
    (*cpu).tick += 8;
}

void Res9C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,H, Length: 2
#ifdef DEBUG
    printf("RES 3,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).H, 3, cpu);
    (*cpu).tick += 8;
}

void Res9D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,L, Length: 2
#ifdef DEBUG
    printf("RES 3,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).L, 3, cpu);
    (*cpu).tick += 8;
}

void Res9E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,(HL), Length: 2
#ifdef DEBUG
    printf("RES 3,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Res(&read_byte,3, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void Res9F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 3,A, Length: 2
#ifdef DEBUG
    printf("RES 3,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).A, 3, cpu);
    (*cpu).tick += 8;
}

void ResA0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,B, Length: 2
#ifdef DEBUG
    printf("RES 4,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).B, 4, cpu);
    (*cpu).tick += 8;
}

void ResA1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,C, Length: 2
#ifdef DEBUG
    printf("RES 4,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).C, 4, cpu);
    (*cpu).tick += 8;
}

void ResA2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,D, Length: 2
#ifdef DEBUG
    printf("RES 4,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).D, 4, cpu);
    (*cpu).tick += 8;
}

void ResA3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,E, Length: 2
#ifdef DEBUG
    printf("RES 4,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).E, 4, cpu);
    (*cpu).tick += 8;
}

void ResA4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,H, Length: 2
#ifdef DEBUG
    printf("RES 4,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).H, 4, cpu);
    (*cpu).tick += 8;
}

void ResA5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,L, Length: 2
#ifdef DEBUG
    printf("RES 4,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).L, 4, cpu);
    (*cpu).tick += 8;
}

void ResA6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,(HL), Length: 2
#ifdef DEBUG
    printf("RES 4,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Res(&read_byte,4, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void ResA7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 4,A, Length: 2
#ifdef DEBUG
    printf("RES 4,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).A, 4, cpu);
    (*cpu).tick += 8;
}

void ResA8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,B, Length: 2
#ifdef DEBUG
    printf("RES 5,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).B, 5,cpu);
    (*cpu).tick += 8;
}

void ResA9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,C, Length: 2
#ifdef DEBUG
    printf("RES 5,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).C, 5,cpu);
    (*cpu).tick += 8;
}

void ResAA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,D, Length: 2
#ifdef DEBUG
    printf("RES 5,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).D, 5,cpu);
    (*cpu).tick += 8;
}

void ResAB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,E, Length: 2
#ifdef DEBUG
    printf("RES 5,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).E, 5,cpu);
    (*cpu).tick += 8;
}

void ResAC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,H, Length: 2
#ifdef DEBUG
    printf("RES 5,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).H, 5,cpu);
    (*cpu).tick += 8;
}

void ResAD(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,L, Length: 2
#ifdef DEBUG
    printf("RES 5,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).L, 5,cpu);
    (*cpu).tick += 8;
}

void ResAE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,(HL), Length: 2
#ifdef DEBUG
    printf("RES 5,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Res(&read_byte,5, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void ResAF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 5,A, Length: 2
#ifdef DEBUG
    printf("RES 5,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).A, 5,cpu);
    (*cpu).tick += 8;
}

void ResB0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,B, Length: 2
#ifdef DEBUG
    printf("RES 6,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).B, 6,cpu);
    (*cpu).tick += 8;
}

void ResB1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,C, Length: 2
#ifdef DEBUG
    printf("RES 6,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).C, 6,cpu);
    (*cpu).tick += 8;
}

void ResB2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,D, Length: 2
#ifdef DEBUG
    printf("RES 6,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).D, 6,cpu);
    (*cpu).tick += 8;
}

void ResB3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,E, Length: 2
#ifdef DEBUG
    printf("RES 6,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).E, 6,cpu);
    (*cpu).tick += 8;
}

void ResB4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,H, Length: 2
#ifdef DEBUG
    printf("RES 6,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).H, 6,cpu);
    (*cpu).tick += 8;
}

void ResB5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,L, Length: 2
#ifdef DEBUG
    printf("RES 6,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).L, 6,cpu);
    (*cpu).tick += 8;
}

void ResB6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,(HL), Length: 2
#ifdef DEBUG
    printf("RES 6,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Res(&read_byte,6, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void ResB7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 6,A, Length: 2
#ifdef DEBUG
    printf("RES 6,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).A, 6,cpu);
    (*cpu).tick += 8;
}

void ResB8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,B, Length: 2
#ifdef DEBUG
    printf("RES 7,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).A, 7,cpu);
    (*cpu).tick += 8;
}

void ResB9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,C, Length: 2
#ifdef DEBUG
    printf("RES 7,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).C, 7,cpu);
    (*cpu).tick += 8;
}

void ResBA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,D, Length: 2
#ifdef DEBUG
    printf("RES 7,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).D, 7,cpu);
    (*cpu).tick += 8;
}

void ResBB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,E, Length: 2
#ifdef DEBUG
    printf("RES 7,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).E, 7,cpu);
    (*cpu).tick += 8;
}

void ResBC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,H, Length: 2
#ifdef DEBUG
    printf("RES 7,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).H, 7,cpu);
    (*cpu).tick += 8;
}

void ResBD(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,L, Length: 2
#ifdef DEBUG
    printf("RES 7,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).L, 7,cpu);
    (*cpu).tick += 8;
}

void ResBE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,(HL), Length: 2
#ifdef DEBUG
    printf("RES 7,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Res(&read_byte,7, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void ResBF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: RES 7,A, Length: 2
#ifdef DEBUG
    printf("RES 7,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Res(&(*cpu).A, 7,cpu);
    (*cpu).tick += 8;
}

void Set(unsigned char* reg, unsigned char n, struct CPU* cpu)
{
     (*reg) |= 1<<n;
}

void SetC0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,B, Length: 2
#ifdef DEBUG
    printf("SET 0,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).B, 0,cpu);
    (*cpu).tick += 8;
}

void SetC1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,C, Length: 2
#ifdef DEBUG
    printf("SET 0,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).C, 0,cpu);
    (*cpu).tick += 8;
}

void SetC2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,D, Length: 2
#ifdef DEBUG
    printf("SET 0,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).D, 0,cpu);
    (*cpu).tick += 8;
}

void SetC3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,E, Length: 2
#ifdef DEBUG
    printf("SET 0,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).E, 0,cpu);
    (*cpu).tick += 8;
}

void SetC4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,H, Length: 2
#ifdef DEBUG
    printf("SET 0,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).H, 0,cpu);
    (*cpu).tick += 8;
}

void SetC5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,L, Length: 2
#ifdef DEBUG
    printf("SET 0,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).L, 0,cpu);
    (*cpu).tick += 8;
}

void SetC6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,(HL), Length: 2
#ifdef DEBUG
    printf("SET 0,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Set(&read_byte,0, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void SetC7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 0,A, Length: 2
#ifdef DEBUG
    printf("SET 0,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).A, 0,cpu);
    (*cpu).tick += 8;
}

void SetC8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,B, Length: 2
#ifdef DEBUG
    printf("SET 1,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).B, 1,cpu);
    (*cpu).tick += 8;
}

void SetC9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,C, Length: 2
#ifdef DEBUG
    printf("SET 1,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).C, 1,cpu);
    (*cpu).tick += 8;
}

void SetCA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,D, Length: 2
#ifdef DEBUG
    printf("SET 1,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).D, 1,cpu);
    (*cpu).tick += 8;
}

void SetCB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,E, Length: 2
#ifdef DEBUG
    printf("SET 1,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).E, 1,cpu);
    (*cpu).tick += 8;
}

void SetCC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,H, Length: 2
#ifdef DEBUG
    printf("SET 1,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).H, 1,cpu);
    (*cpu).tick += 8;
}

void SetCD(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,L, Length: 2
#ifdef DEBUG
    printf("SET 1,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).L, 1,cpu);
    (*cpu).tick += 8;
}

void SetCE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,(HL), Length: 2
#ifdef DEBUG
    printf("SET 1,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Set(&read_byte,1, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void SetCF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 1,A, Length: 2
#ifdef DEBUG
    printf("SET 1,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).A, 1,cpu);
    (*cpu).tick += 8;
}

void SetD0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,B, Length: 2
#ifdef DEBUG
    printf("SET 2,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).B, 2,cpu);
    (*cpu).tick += 8;
}

void SetD1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,C, Length: 2
#ifdef DEBUG
    printf("SET 2,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).C, 2,cpu);
    (*cpu).tick += 8;
}

void SetD2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,D, Length: 2
#ifdef DEBUG
    printf("SET 2,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).D, 2,cpu);
    (*cpu).tick += 8;
}

void SetD3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,E, Length: 2
#ifdef DEBUG
    printf("SET 2,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).E, 2,cpu);
    (*cpu).tick += 8;
}

void SetD4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,H, Length: 2
#ifdef DEBUG
    printf("SET 2,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).H, 2,cpu);
    (*cpu).tick += 8;
}

void SetD5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,L, Length: 2
#ifdef DEBUG
    printf("SET 2,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).L, 2,cpu);
    (*cpu).tick += 8;
}

void SetD6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,(HL), Length: 2
#ifdef DEBUG
    printf("SET 2,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Set(&read_byte,2, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void SetD7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 2,A, Length: 2
#ifdef DEBUG
    printf("SET 2,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).A, 2,cpu);
    (*cpu).tick += 8;
}

void SetD8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,B, Length: 2
#ifdef DEBUG
    printf("SET 3,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).B, 3,cpu);
    (*cpu).tick += 8;
}

void SetD9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,C, Length: 2
#ifdef DEBUG
    printf("SET 3,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).C, 3,cpu);
    (*cpu).tick += 8;
}

void SetDA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,D, Length: 2
#ifdef DEBUG
    printf("SET 3,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).D, 3,cpu);
    (*cpu).tick += 8;
}

void SetDB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,E, Length: 2
#ifdef DEBUG
    printf("SET 3,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).E, 3,cpu);
    (*cpu).tick += 8;
}

void SetDC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,H, Length: 2
#ifdef DEBUG
    printf("SET 3,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).H, 3,cpu);
    (*cpu).tick += 8;
}

void SetDD(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,L, Length: 2
#ifdef DEBUG
    printf("SET 3,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).L, 3,cpu);
    (*cpu).tick += 8;
}

void SetDE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,(HL), Length: 2
#ifdef DEBUG
    printf("SET 3,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Set(&read_byte,3, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void SetDF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 3,A, Length: 2
#ifdef DEBUG
    printf("SET 3,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).A, 3,cpu);
    (*cpu).tick += 8;
}

void SetE0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,B, Length: 2
#ifdef DEBUG
    printf("SET 4,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).B, 4,cpu);
    (*cpu).tick += 8;
}

void SetE1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,C, Length: 2
#ifdef DEBUG
    printf("SET 4,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).C, 4,cpu);
    (*cpu).tick += 8;
}

void SetE2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,D, Length: 2
#ifdef DEBUG
    printf("SET 4,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).D, 4,cpu);
    (*cpu).tick += 8;
}

void SetE3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,E, Length: 2
#ifdef DEBUG
    printf("SET 4,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).E, 4,cpu);
    (*cpu).tick += 8;
}

void SetE4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,H, Length: 2
#ifdef DEBUG
    printf("SET 4,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).H, 4,cpu);
    (*cpu).tick += 8;
}

void SetE5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,L, Length: 2
#ifdef DEBUG
    printf("SET 4,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).L, 4,cpu);
    (*cpu).tick += 8;
}

void SetE6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,(HL), Length: 2
#ifdef DEBUG
    printf("SET 4,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Set(&read_byte,4, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void SetE7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 4,A, Length: 2
#ifdef DEBUG
    printf("SET 4,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).A, 4,cpu);
    (*cpu).tick += 8;
}

void SetE8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,B, Length: 2
#ifdef DEBUG
    printf("SET 5,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).B, 5,cpu);
    (*cpu).tick += 8;
}

void SetE9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,C, Length: 2
#ifdef DEBUG
    printf("SET 5,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).C, 5,cpu);
    (*cpu).tick += 8;
}

void SetEA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,D, Length: 2
#ifdef DEBUG
    printf("SET 5,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).D, 5,cpu);
    (*cpu).tick += 8;
}

void SetEB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,E, Length: 2
#ifdef DEBUG
    printf("SET 5,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).E, 5,cpu);
    (*cpu).tick += 8;
}

void SetEC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,H, Length: 2
#ifdef DEBUG
    printf("SET 5,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).H, 5,cpu);
    (*cpu).tick += 8;
}

void SetED(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,L, Length: 2
#ifdef DEBUG
    printf("SET 5,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).L, 5,cpu);
    (*cpu).tick += 8;
}

void SetEE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,(HL), Length: 2
#ifdef DEBUG
    printf("SET 5,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Set(&read_byte,5, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void SetEF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 5,A, Length: 2
#ifdef DEBUG
    printf("SET 5,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).A, 5,cpu);
    (*cpu).tick += 8;
}

void SetF0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,B, Length: 2
#ifdef DEBUG
    printf("SET 6,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).B, 6,cpu);
    (*cpu).tick += 8;
}

void SetF1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,C, Length: 2
#ifdef DEBUG
    printf("SET 6,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).C, 6,cpu);
    (*cpu).tick += 8;
}

void SetF2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,D, Length: 2
#ifdef DEBUG
    printf("SET 6,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).D, 6,cpu);
    (*cpu).tick += 8;
}

void SetF3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,E, Length: 2
#ifdef DEBUG
    printf("SET 6,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).E, 6,cpu);
    (*cpu).tick += 8;
}

void SetF4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,H, Length: 2
#ifdef DEBUG
    printf("SET 6,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).H, 6,cpu);
    (*cpu).tick += 8;
}

void SetF5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,L, Length: 2
#ifdef DEBUG
    printf("SET 6,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).L, 6,cpu);
    (*cpu).tick += 8;
}

void SetF6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,(HL), Length: 2
#ifdef DEBUG
    printf("SET 6,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Set(&read_byte,6, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void SetF7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 6,A, Length: 2
#ifdef DEBUG
    printf("SET 6,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).A, 6,cpu);
    (*cpu).tick += 8;
}

void SetF8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,B, Length: 2
#ifdef DEBUG
    printf("SET 7,B");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).B, 7,cpu);
    (*cpu).tick += 8;
}

void SetF9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,C, Length: 2
#ifdef DEBUG
    printf("SET 7,C");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).C, 7,cpu);
    (*cpu).tick += 8;
}

void SetFA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,D, Length: 2
#ifdef DEBUG
    printf("SET 7,D");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).D, 7,cpu);
    (*cpu).tick += 8;
}

void SetFB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,E, Length: 2
#ifdef DEBUG
    printf("SET 7,E");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).E, 7,cpu);
    (*cpu).tick += 8;
}

void SetFC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,H, Length: 2
#ifdef DEBUG
    printf("SET 7,H");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).H, 7,cpu);
    (*cpu).tick += 8;
}

void SetFD(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,L, Length: 2
#ifdef DEBUG
    printf("SET 7,L");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).L, 7,cpu);
    (*cpu).tick += 8;
}

void SetFE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,(HL), Length: 2
#ifdef DEBUG
    printf("SET 7,(HL)");
#endif
    // Cycles: 16, (Z N H C): - - - -
    unsigned char read_byte = mmu_read(mmu,(*cpu).HL);
    Set(&read_byte,7, cpu);
    mmu_write(mmu, (*cpu).HL, read_byte);
    (*cpu).tick += 16;
}

void SetFF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SET 7,A, Length: 2
#ifdef DEBUG
    printf("SET 7,A");
#endif
    // Cycles: 8, (Z N H C): - - - -
    Set(&(*cpu).A, 7,cpu);
    (*cpu).tick += 8;
}

