#include "aritmetic.h"
#include <stdint.h>

void Inc(unsigned char* reg, CPU* cpu, MMU* mmu){
     // Generic INC operation
     unsigned char hilow_bit = *reg & (1 << 3);

     (*reg)++;

     // update timer
     (*cpu).tick+=4;

     // update flags
     unsigned char zero = 0x0;
     if (*reg == 0x0){
          zero = Z_flag;
     }
     unsigned char half_carry = 0x0;
     if (hilow_bit == 1<<3){
          // verificar si ha cambiado de estado
          if ((*reg & (1 << 3)) == 0x0)
               half_carry = H_flag;
     }
     (*cpu).F = ((*cpu).F & C_flag) | zero | half_carry;
}

void Inc03(CPU* cpu, MMU* mmu)
{
    // Mnemonic: INC BC, Length: 1
#ifdef DEBUG
    printf("INC BC");
#endif
    // Cycles: 8, (Z N H C): - - - -
    (*cpu).BC++;

    // update timer
    (*cpu).tick+=8;
}

void Inc04(CPU* cpu, MMU* mmu)
{
    // Mnemonic: INC B, Length: 1
#ifdef DEBUG
    printf("INC B");
#endif
    // Cycles: 4, (Z N H C): Z 0 H -
    Inc(&(*cpu).B, cpu, mmu);
}

void Inc0C(CPU* cpu, MMU* mmu)
{
    // Mnemonic: INC C, Length: 1
#ifdef DEBUG
    printf("INC C");
#endif
    // Cycles: 4, (Z N H C): Z 0 H -
    Inc(&(*cpu).C, cpu, mmu);
}

void Inc13(CPU* cpu, MMU* mmu)
{
    // Mnemonic: INC DE, Length: 1
#ifdef DEBUG
    printf("INC DE");
#endif
    // Cycles: 8, (Z N H C): - - - -
   (*cpu).ED++;

   // update timer
   (*cpu).tick+=8;
}

void Inc14(CPU* cpu, MMU* mmu)
{
    // Mnemonic: INC D, Length: 1
#ifdef DEBUG
    printf("INC D");
#endif
    // Cycles: 4, (Z N H C): Z 0 H -
    Inc(&(*cpu).D, cpu, mmu);
}

void Inc1C(CPU* cpu, MMU* mmu)
{
    // Mnemonic: INC E, Length: 1
#ifdef DEBUG
    printf("INC E");
#endif
    // Cycles: 4, (Z N H C): Z 0 H -
    Inc(&(*cpu).E, cpu, mmu);
}

void Inc23(CPU* cpu, MMU* mmu)
{
    // Mnemonic: INC HL, Length: 1
#ifdef DEBUG
    printf("INC HL");
#endif
    // Cycles: 8, (Z N H C): - - - -
    (*cpu).HL++;

    // update timer
    (*cpu).tick+=8;
}

void Inc24(CPU* cpu, MMU* mmu)
{
    // Mnemonic: INC H, Length: 1
#ifdef DEBUG
    printf("INC H");
#endif
    // Cycles: 4, (Z N H C): Z 0 H -
    Inc(&(*cpu).H, cpu, mmu);
}

void Inc2C(CPU* cpu, MMU* mmu)
{
    // Mnemonic: INC L, Length: 1
#ifdef DEBUG
    printf("INC L");
#endif
    // Cycles: 4, (Z N H C): Z 0 H -
    Inc(&(*cpu).L, cpu, mmu);
}

void Inc33(CPU* cpu, MMU* mmu)
{
    // Mnemonic: INC SP, Length: 1
#ifdef DEBUG
    printf("INC SP");
#endif
    // Cycles: 8, (Z N H C): - - - -
    (*cpu).SP++;

    // update timer
    (*cpu).tick+=8;
}

void Inc34(CPU* cpu, MMU* mmu)
{
    // Mnemonic: INC (HL), Length: 1
#ifdef DEBUG
    printf("INC (HL)");
#endif
    // Cycles: 12, (Z N H C): Z 0 H -

    unsigned char read_byte = mmu_read(mmu, (*cpu).HL);
    Inc(&read_byte, cpu, mmu);

    mmu_write(mmu, (*cpu).HL, read_byte);
}

void Inc3C(CPU* cpu, MMU* mmu)
{
    // Mnemonic: INC A, Length: 1
#ifdef DEBUG
    printf("INC A");
#endif
    // Cycles: 4, (Z N H C): Z 0 H -
    Inc(&(*cpu).A, cpu, mmu);
}

void Dec(unsigned char* reg, CPU* cpu, MMU* mmu){
     // Generic DEC operation

     unsigned char hilow_bit = *reg & (1 << 4);
     (*reg)--;

     // update timer
     (*cpu).tick+=4;

     // update flags
     unsigned char zero = 0x0;
     if (*reg == 0x0){
          zero = Z_flag;
     }
     unsigned char half_carry = 0x0;
     if (hilow_bit == 1<<4){
          // verificar si ha cambiado de estado
          if ((*reg & (1 << 4)) == 0x0)
               half_carry = H_flag;
     }

     (*cpu).F = ((*cpu).F & C_flag) | N_flag | zero | half_carry;
}

void Dec05(CPU* cpu, MMU* mmu)
{
    // Mnemonic: DEC B, Length: 1
#ifdef DEBUG
    printf("DEC B");
#endif
    // Cycles: 4, (Z N H C): Z 1 H -
    Dec(&(*cpu).B, cpu, mmu);
}

void Dec0B(CPU* cpu, MMU* mmu)
{
    // Mnemonic: DEC BC, Length: 1
#ifdef DEBUG
    printf("DEC BC");
#endif
    // Cycles: 8, (Z N H C): - - - -
    (*cpu).BC--;

    // update timer
    (*cpu).tick+=8;
}

void Dec0D(CPU* cpu, MMU* mmu)
{
    // Mnemonic: DEC C, Length: 1
#ifdef DEBUG
    printf("DEC C");
#endif
    // Cycles: 4, (Z N H C): Z 1 H -
    Dec(&(*cpu).C, cpu, mmu);
}

void Dec15(CPU* cpu, MMU* mmu)
{
    // Mnemonic: DEC D, Length: 1
#ifdef DEBUG
    printf("DEC D");
#endif
    // Cycles: 4, (Z N H C): Z 1 H -
    Dec(&(*cpu).D, cpu, mmu);
}

void Dec1B(CPU* cpu, MMU* mmu)
{
    // Mnemonic: DEC DE, Length: 1
#ifdef DEBUG
    printf("DEC DE");
#endif
    // Cycles: 8, (Z N H C): - - - -
    (*cpu).ED--;

    // update timer
    (*cpu).tick+=8;
}

void Dec1D(CPU* cpu, MMU* mmu)
{
    // Mnemonic: DEC E, Length: 1
#ifdef DEBUG
    printf("DEC E");
#endif
    // Cycles: 4, (Z N H C): Z 1 H -
    Dec(&(*cpu).E, cpu, mmu);
}

void Dec25(CPU* cpu, MMU* mmu)
{
    // Mnemonic: DEC H, Length: 1
#ifdef DEBUG
    printf("DEC H");
#endif
    // Cycles: 4, (Z N H C): Z 1 H -
    Dec(&(*cpu).H, cpu, mmu);
}

void Dec2B(CPU* cpu, MMU* mmu)
{
    // Mnemonic: DEC HL, Length: 1
#ifdef DEBUG
    printf("DEC HL");
#endif
    // Cycles: 8, (Z N H C): - - - -
    (*cpu).HL--;

    // update timer
    (*cpu).tick+=8;
}

void Dec2D(CPU* cpu, MMU* mmu)
{
    // Mnemonic: DEC L, Length: 1
#ifdef DEBUG
    printf("DEC L");
#endif
    // Cycles: 4, (Z N H C): Z 1 H -
    Dec(&(*cpu).L, cpu, mmu);
}

void Dec35(CPU* cpu, MMU* mmu)
{
    // Mnemonic: DEC (HL), Length: 1
#ifdef DEBUG
    printf("DEC (HL)");
#endif
    // Cycles: 12, (Z N H C): Z 1 H -
    unsigned char read_byte = mmu_read(mmu, (*cpu).HL);
    Dec(&read_byte, cpu, mmu);

    mmu_write(mmu, (*cpu).HL, read_byte);
}

void Dec3B(CPU* cpu, MMU* mmu)
{
    // Mnemonic: DEC SP, Length: 1
#ifdef DEBUG
    printf("DEC SP");
#endif
    // Cycles: 8, (Z N H C): - - - -
    (*cpu).SP--;

    // update timer
    (*cpu).tick+=8;
}

void Dec3D(CPU* cpu, MMU* mmu)
{
    // Mnemonic: DEC A, Length: 1
#ifdef DEBUG
    printf("DEC A");
#endif
    // Cycles: 4, (Z N H C): Z 1 H -
    Dec(&(*cpu).A, cpu, mmu);
}

void Add_16(unsigned short* A, unsigned short* B, CPU* cpu) {
     // convert to unsigned short -> 16 bits
     unsigned int A_32 = *A;
     unsigned int B_32 = *B;

     A_32 += B_32;

     // bytes with only 12 lower bits
     unsigned short A_12 = *A & 0x0FFF;
     unsigned short B_12 = *B & 0x0FFF;

     A_12 += B_12;

     // update timer
     (*cpu).tick+=8;

     // update flags
     unsigned char carry = 0x0;
     if ((A_32 & (1 << 16)) == (1 << 16)){
          carry = C_flag;
     }
     unsigned char half_carry = 0x0;
     if ((A_12 & (1 << 12)) == (1 << 12)){
          half_carry = H_flag;
     }

     *A += *B;

     (*cpu).F = carry | half_carry | ((*cpu).F & Z_flag);
}

void Add09(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADD HL,BC, Length: 1
#ifdef DEBUG
    printf("ADD HL,BC");
#endif
    // Cycles: 8, (Z N H C): - 0 H C
    Add_16(&(*cpu).HL, &(*cpu).BC, cpu);
}

void Add19(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADD HL,DE, Length: 1
#ifdef DEBUG
    printf("ADD HL,DE");
#endif
    // Cycles: 8, (Z N H C): - 0 H C
    Add_16(&(*cpu).HL, &(*cpu).ED, cpu);
}

void Add29(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADD HL,HL, Length: 1
#ifdef DEBUG
    printf("ADD HL,HL");
#endif
    // Cycles: 8, (Z N H C): - 0 H C
    Add_16(&(*cpu).HL, &(*cpu).HL, cpu);
}

void Add39(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADD HL,SP, Length: 1
#ifdef DEBUG
    printf("ADD HL,SP");
#endif
    // Cycles: 8, (Z N H C): - 0 H C
    Add_16(&(*cpu).HL, &(*cpu).SP, cpu);
}


void Add_8(unsigned char* A, unsigned char* B, CPU* cpu) {
     // convert to unsigned short -> 16 bits
     unsigned short A_16 = *A;
     unsigned short B_16 = *B;

     A_16 += B_16;

     // bytes with only 4 lower bits
     unsigned char A_4 = *A & 0x0F;
     unsigned char B_4 = *B & 0x0F;

     A_4 += B_4;

     // update timer
     (*cpu).tick+=4;

     // update flags
     unsigned char carry = 0x0;
     if ((A_16 & (1 << 8)) == (1 << 8)){
          carry = C_flag;
     }
     unsigned char half_carry = 0x0;
     if ((A_4 & (1 << 4)) == (1 << 4)){
          half_carry = H_flag;
     }

     *A += *B;

     unsigned char zero = 0x0;
     if (!(*A)){
          zero = Z_flag;
     }

     (*cpu).F = carry | half_carry | zero;
}

void Add80(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADD A,B, Length: 1
#ifdef DEBUG
    printf("ADD A,B");
#endif
    // Cycles: 4, (Z N H C): Z 0 H C
    Add_8(&(*cpu).A, &(*cpu).B, cpu);
}

void Add81(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADD A,C, Length: 1
#ifdef DEBUG
    printf("ADD A,C");
#endif
    // Cycles: 4, (Z N H C): Z 0 H C
    Add_8(&(*cpu).A, &(*cpu).C, cpu);
}

void Add82(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADD A,D, Length: 1
#ifdef DEBUG
    printf("ADD A,D");
#endif
    // Cycles: 4, (Z N H C): Z 0 H C
    Add_8(&(*cpu).A, &(*cpu).D, cpu);
}

void Add83(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADD A,E, Length: 1
#ifdef DEBUG
    printf("ADD A,E");
#endif
    // Cycles: 4, (Z N H C): Z 0 H C
    Add_8(&(*cpu).A, &(*cpu).D, cpu);
}

void Add84(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADD A,H, Length: 1
#ifdef DEBUG
    printf("ADD A,H");
#endif
    // Cycles: 4, (Z N H C): Z 0 H C
    Add_8(&(*cpu).A, &(*cpu).D, cpu);
}

void Add85(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADD A,L, Length: 1
#ifdef DEBUG
    printf("ADD A,L");
#endif
    // Cycles: 4, (Z N H C): Z 0 H C
    Add_8(&(*cpu).A, &(*cpu).D, cpu);
}

void Add86(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADD A,(HL), Length: 1
#ifdef DEBUG
    printf("ADD A,(HL)");
#endif
    // Cycles: 8, (Z N H C): Z 0 H C
    unsigned char membyte = mmu_read(mmu,(*cpu).HL);
    Add_8(&(*cpu).A, &membyte, cpu);

    (*cpu).tick += 4;
}

void Add87(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADD A,A, Length: 1
#ifdef DEBUG
    printf("ADD A,A");
#endif
    // Cycles: 4, (Z N H C): Z 0 H C
    Add_8(&(*cpu).A, &(*cpu).A, cpu);
}

void AddC6(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADD A,d8, Length: 2
#ifdef DEBUG
    printf("ADD A,d8");
#endif
    // Cycles: 8, (Z N H C): Z 0 H C
    unsigned char membyte = mmu_read(mmu,(*cpu).PC++);
    Add_8(&(*cpu).A, &membyte, cpu);

    (*cpu).tick += 4;
}

void AddE8(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADD SP,r8, Length: 2
#ifdef DEBUG
    printf("ADD SP,r8");
#endif
    // Cycles: 16, (Z N H C): 0 0 H C
    // TODO -> next time
    printf("Not implemented! (AddE8)");
}

void Daa27(CPU* cpu, MMU* mmu)
{
    // Mnemonic: DAA, Length: 1
#ifdef DEBUG
    printf("DAA");
#endif
    // Cycles: 4, (Z N H C): Z - 0 C
    printf("Not implemented! (Daa27)");
}

void Cpl2F(CPU* cpu, MMU* mmu)
{
    // Mnemonic: CPL, Length: 1
#ifdef DEBUG
    printf("CPL");
#endif
    // Cycles: 4, (Z N H C): - 1 1 -
    (*cpu).A = ~(*cpu).A;

    // update timer
    (*cpu).tick+=4;

    // update flags
    (*cpu).F = (N_flag | H_flag) | ((*cpu).F & (Z_flag | C_flag));
}

void Scf37(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SCF, Length: 1
#ifdef DEBUG
    printf("SCF");
#endif
    // Cycles: 4, (Z N H C): - 0 0 1

    // update timer
    (*cpu).tick+=4;

    (*cpu).F = ((*cpu).F & Z_flag) | C_flag;
}

void Ccf3F(CPU* cpu, MMU* mmu)
{
    // Mnemonic: CCF, Length: 1
#ifdef DEBUG
    printf("CCF");
#endif
    // Cycles: 4, (Z N H C): - 0 0 C

    // update timer
    (*cpu).tick+=4;

    unsigned char inv_Cflag = (~((*cpu).F & C_flag) & C_flag);
    (*cpu).F = ((*cpu).F & Z_flag) | inv_Cflag;
}

void Adc_8(unsigned char* A, unsigned char* B, CPU* cpu) {
     unsigned char carry_bit = ((*cpu).F & C_flag) >> 4;
     // convert to unsigned short -> 16 bits
     unsigned short A_16 = *A;
     unsigned short B_16 = *B;

     A_16 += B_16 + carry_bit;

     // bytes with only 4 lower bits
     unsigned char A_4 = *A & 0x0F;
     unsigned char B_4 = *B & 0x0F;

     A_4 += B_4 + carry_bit;

     // update timer
     (*cpu).tick+=4;

     // update flags
     unsigned char carry = 0x0;
     if ((A_16 & (1 << 8)) == (1 << 8)){
          carry = C_flag;
     }
     unsigned char half_carry = 0x0;
     if ((A_4 & (1 << 4)) == (1 << 4)){
          half_carry = H_flag;
     }

     *A += *B + carry_bit;

     unsigned char zero = 0x0;
     if (!(*A)){
          zero = Z_flag;
     }

     (*cpu).F = carry | half_carry | zero;
}

void Adc88(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADC A,B, Length: 1
#ifdef DEBUG
    printf("ADC A,B");
#endif
    // Cycles: 4, (Z N H C): Z 0 H C
    Adc_8(&(*cpu).A, &(*cpu).B, cpu);
}

void Adc89(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADC A,C, Length: 1
#ifdef DEBUG
    printf("ADC A,C");
#endif
    // Cycles: 4, (Z N H C): Z 0 H C
    Adc_8(&(*cpu).A, &(*cpu).C, cpu);
}

void Adc8A(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADC A,D, Length: 1
#ifdef DEBUG
    printf("ADC A,D");
#endif
    // Cycles: 4, (Z N H C): Z 0 H C
     Adc_8(&(*cpu).A, &(*cpu).D, cpu);
}

void Adc8B(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADC A,E, Length: 1
#ifdef DEBUG
    printf("ADC A,E");
#endif
    // Cycles: 4, (Z N H C): Z 0 H C
    Adc_8(&(*cpu).A, &(*cpu).E, cpu);
}

void Adc8C(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADC A,H, Length: 1
#ifdef DEBUG
    printf("ADC A,H");
#endif
    // Cycles: 4, (Z N H C): Z 0 H C
    Adc_8(&(*cpu).A, &(*cpu).H, cpu);
}

void Adc8D(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADC A,L, Length: 1
#ifdef DEBUG
    printf("ADC A,L");
#endif
    // Cycles: 4, (Z N H C): Z 0 H C
    Adc_8(&(*cpu).A, &(*cpu).L, cpu);
}

void Adc8E(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADC A,(HL), Length: 1
#ifdef DEBUG
    printf("ADC A,(HL)");
#endif
    // Cycles: 8, (Z N H C): Z 0 H C
    unsigned char membyte = mmu_read(mmu,(*cpu).HL);
    Adc_8(&(*cpu).A, &membyte, cpu);
    (*cpu).tick += 4;
}

void Adc8F(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADC A,A, Length: 1
#ifdef DEBUG
    printf("ADC A,A");
#endif
    // Cycles: 4, (Z N H C): Z 0 H C
    Adc_8(&(*cpu).A, &(*cpu).A, cpu);
}

void AdcCE(CPU* cpu, MMU* mmu)
{
    // Mnemonic: ADC A,d8, Length: 2
#ifdef DEBUG
    printf("ADC A,d8");
#endif
    // Cycles: 8, (Z N H C): Z 0 H C
    unsigned char membyte = mmu_read(mmu,(*cpu).PC++);
    Adc_8(&(*cpu).A, &membyte, cpu);
    (*cpu).tick += 4;
}

void Sub_8(unsigned char* A, unsigned char* B, CPU* cpu) {
    // bytes with only 4 lower bits
    unsigned char A_4 = *A & 0x0F;
    unsigned char B_4 = *B & 0x0F;

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char carry = 0x0;
    if ((*B) > (*A)){
        carry = C_flag;
    }
    unsigned char half_carry = 0x0;
    if (B_4 > A_4){
        half_carry = H_flag;
    }

    *A -= *B;

    unsigned char zero = 0x0;
    if (!(*A)){
        zero = Z_flag;
    }

    (*cpu).F = carry | half_carry | zero | N_flag;
}

void Sub90(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SUB B, Length: 1
#ifdef DEBUG
    printf("SUB B");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Sub_8(&(*cpu).A, &(*cpu).B, cpu);
}


void Sub91(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SUB C, Length: 1
#ifdef DEBUG
    printf("SUB C");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Sub_8(&(*cpu).A, &(*cpu).C, cpu);
}

void Sub92(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SUB D, Length: 1
#ifdef DEBUG
    printf("SUB D");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Sub_8(&(*cpu).A, &(*cpu).D, cpu);
}

void Sub93(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SUB E, Length: 1
#ifdef DEBUG
    printf("SUB E");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Sub_8(&(*cpu).A, &(*cpu).E, cpu);
}

void Sub94(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SUB H, Length: 1
#ifdef DEBUG
    printf("SUB H");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Sub_8(&(*cpu).A, &(*cpu).H, cpu);
}

void Sub95(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SUB L, Length: 1
#ifdef DEBUG
    printf("SUB L");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Sub_8(&(*cpu).A, &(*cpu).L, cpu);
}

void Sub96(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SUB (HL), Length: 1
#ifdef DEBUG
    printf("SUB (HL)");
#endif
    // Cycles: 8, (Z N H C): Z 1 H C
    unsigned char membyte = mmu_read(mmu,(*cpu).HL);
    Sub_8(&(*cpu).A, &membyte, cpu);
    (*cpu).tick += 4;
}

void Sub97(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SUB A, Length: 1
#ifdef DEBUG
    printf("SUB A");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Sub_8(&(*cpu).A, &(*cpu).A, cpu);
}

void SubD6(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SUB d8, Length: 2
#ifdef DEBUG
    printf("SUB d8");
#endif
    // Cycles: 8, (Z N H C): Z 1 H C
    unsigned char membyte = mmu_read(mmu,(*cpu).PC++);
    Sub_8(&(*cpu).A, &membyte, cpu);
    (*cpu).tick += 4;
}

void Sbc_8(unsigned char* A, unsigned char* B, CPU* cpu) {
     // B with carry
     unsigned char B_wc = *B + (((*cpu).F & C_flag) >> 4) ;

     // bytes with only 4 lower bits
     unsigned char A_4 = *A & 0x0F;
     unsigned char B_4 = B_wc & 0x0F;

     // update timer
     (*cpu).tick+=4;

     // update flags
     unsigned char carry = 0x0;
     if (B_wc > (*A)){
          carry = C_flag;
     }
     unsigned char half_carry = 0x0;
     if (B_4 > A_4){
          half_carry = H_flag;
     }

     *A -= B_wc;

     unsigned char zero = 0x0;
     if (!(*A)){
          zero = Z_flag;
     }

     (*cpu).F = carry | half_carry | zero | N_flag;
}

void Sbc98(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SBC A,B, Length: 1
#ifdef DEBUG
    printf("SBC A,B");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Sbc_8(&(*cpu).A, &(*cpu).B, cpu);
}

void Sbc99(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SBC A,C, Length: 1
#ifdef DEBUG
    printf("SBC A,C");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Sbc_8(&(*cpu).A, &(*cpu).C, cpu);
}

void Sbc9A(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SBC A,D, Length: 1
#ifdef DEBUG
    printf("SBC A,D");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Sbc_8(&(*cpu).A, &(*cpu).D, cpu);
}

void Sbc9B(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SBC A,E, Length: 1
#ifdef DEBUG
    printf("SBC A,E");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Sbc_8(&(*cpu).A, &(*cpu).E, cpu);
}

void Sbc9C(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SBC A,H, Length: 1
#ifdef DEBUG
    printf("SBC A,H");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Sbc_8(&(*cpu).A, &(*cpu).H, cpu);
}

void Sbc9D(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SBC A,L, Length: 1
#ifdef DEBUG
    printf("SBC A,L");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Sbc_8(&(*cpu).A, &(*cpu).L, cpu);
}

void Sbc9E(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SBC A,(HL), Length: 1
#ifdef DEBUG
    printf("SBC A,(HL)");
#endif
    // Cycles: 8, (Z N H C): Z 1 H C
    unsigned char membyte = mmu_read(mmu,(*cpu).HL);
    Sbc_8(&(*cpu).A, &membyte, cpu);
    (*cpu).tick += 4;
}

void Sbc9F(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SBC A,A, Length: 1
#ifdef DEBUG
    printf("SBC A,A");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Sbc_8(&(*cpu).A, &(*cpu).A, cpu);
}

void SbcDE(CPU* cpu, MMU* mmu)
{
    // Mnemonic: SBC A,d8, Length: 2
#ifdef DEBUG
    printf("SBC A,d8");
#endif
    // Cycles: 8, (Z N H C): Z 1 H C
    unsigned char membyte = mmu_read(mmu,(*cpu).PC++);
    Sbc_8(&(*cpu).A, &membyte, cpu);
    (*cpu).tick += 4;
}


void And(unsigned char* A, unsigned char* B, CPU* cpu, MMU* mmu){
    // Generic AND operation

    (*A) = (*A) & (*B);
    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
         zero = Z_flag;

    (*cpu).F = zero | H_flag;
}

void AndA0(CPU* cpu, MMU* mmu)
{
    // Mnemonic: AND B, Length: 1
#ifdef DEBUG
    printf("AND B");
#endif
    // Cycles: 4, (Z N H C): Z 0 1 0

     And(&(*cpu).A,&(*cpu).B,cpu,mmu);
}

void AndA1(CPU* cpu, MMU* mmu)
{
    // Mnemonic: AND C, Length: 1
#ifdef DEBUG
    printf("AND C");
#endif
    // Cycles: 4, (Z N H C): Z 0 1 0
     And(&(*cpu).A,&(*cpu).C,cpu,mmu);
}

void AndA2(CPU* cpu, MMU* mmu)
{
    // Mnemonic: AND D, Length: 1
#ifdef DEBUG
    printf("AND D");
#endif
    // Cycles: 4, (Z N H C): Z 0 1 0
    And(&(*cpu).A,&(*cpu).D,cpu,mmu);
}

void AndA3(CPU* cpu, MMU* mmu)
{
    // Mnemonic: AND E, Length: 1
#ifdef DEBUG
    printf("AND E");
#endif
    // Cycles: 4, (Z N H C): Z 0 1 0
    And(&(*cpu).A,&(*cpu).E,cpu,mmu);
}

void AndA4(CPU* cpu, MMU* mmu)
{
    // Mnemonic: AND H, Length: 1
#ifdef DEBUG
    printf("AND H");
#endif
    // Cycles: 4, (Z N H C): Z 0 1 0
    And(&(*cpu).A,&(*cpu).H,cpu,mmu);
}

void AndA5(CPU* cpu, MMU* mmu)
{
    // Mnemonic: AND L, Length: 1
#ifdef DEBUG
    printf("AND L");
#endif
    // Cycles: 4, (Z N H C): Z 0 1 0
     And(&(*cpu).A,&(*cpu).L,cpu,mmu);
}

void AndA6(CPU* cpu, MMU* mmu)
{
    // Mnemonic: AND (HL), Length: 1
#ifdef DEBUG
    printf("AND (HL)");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 0
    unsigned char mem_byte = mmu_read(mmu,(*cpu).HL);
    // fetch from memory
    And(&(*cpu).A,&mem_byte,cpu,mmu);
}

void AndA7(CPU* cpu, MMU* mmu)
{
    // Mnemonic: AND A, Length: 1
#ifdef DEBUG
    printf("AND A");
#endif
    // Cycles: 4, (Z N H C): Z 0 1 0
     And(&(*cpu).A,&(*cpu).A,cpu,mmu);
}

void AndE6(CPU* cpu, MMU* mmu)
{
    // Mnemonic: AND d8, Length: 2
#ifdef DEBUG
    printf("AND d8");
#endif
    // Cycles: 8, (Z N H C): Z 0 1 0
    unsigned char mem_byte = mmu_read(mmu,(*cpu).PC++);
    // fetch from memory
    And(&(*cpu).A,&mem_byte,cpu,mmu);
}

void Xor(unsigned char* A, unsigned char* B, CPU* cpu, MMU* mmu){
    // Generic XOR operation

    (*A) = (*A) ^ (*B);
    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
         zero = Z_flag;

    (*cpu).F = zero;
}

void XorA8(CPU* cpu, MMU* mmu)
{
    // Mnemonic: XOR B, Length: 1
#ifdef DEBUG
    printf("XOR B");
#endif
    // Cycles: 4, (Z N H C): Z 0 0 0
    Xor(&(*cpu).A,&(*cpu).B,cpu,mmu);
}

void XorA9(CPU* cpu, MMU* mmu)
{
    // Mnemonic: XOR C, Length: 1
#ifdef DEBUG
    printf("XOR C");
#endif
    // Cycles: 4, (Z N H C): Z 0 0 0
    Xor(&(*cpu).A,&(*cpu).C,cpu,mmu);
}

void XorAA(CPU* cpu, MMU* mmu)
{
    // Mnemonic: XOR D, Length: 1
#ifdef DEBUG
    printf("XOR D");
#endif
    // Cycles: 4, (Z N H C): Z 0 0 0
    Xor(&(*cpu).A,&(*cpu).D,cpu,mmu);
}

void XorAB(CPU* cpu, MMU* mmu)
{
    // Mnemonic: XOR E, Length: 1
#ifdef DEBUG
    printf("XOR E");
#endif
    // Cycles: 4, (Z N H C): Z 0 0 0
    Xor(&(*cpu).A,&(*cpu).E,cpu,mmu);
}

void XorAC(CPU* cpu, MMU* mmu)
{
    // Mnemonic: XOR H, Length: 1
#ifdef DEBUG
    printf("XOR H");
#endif
    // Cycles: 4, (Z N H C): Z 0 0 0
    Xor(&(*cpu).A,&(*cpu).H,cpu,mmu);
}

void XorAD(CPU* cpu, MMU* mmu)
{
    // Mnemonic: XOR L, Length: 1
#ifdef DEBUG
    printf("XOR L");
#endif
    // Cycles: 4, (Z N H C): Z 0 0 0
    Xor(&(*cpu).A,&(*cpu).L,cpu,mmu);
}

void XorAE(CPU* cpu, MMU* mmu)
{
    // Mnemonic: XOR (HL), Length: 1
#ifdef DEBUG
    printf("XOR (HL)");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 0
    unsigned char mem_byte = mmu_read(mmu,(*cpu).HL);
    // fetch from memory
    Xor(&(*cpu).A,&mem_byte,cpu,mmu);
}

void XorAF(CPU* cpu, MMU* mmu)
{
    // Mnemonic: XOR A, Length: 1
#ifdef DEBUG
    printf("XOR A");
#endif
    // Cycles: 4, (Z N H C): Z 0 0 0
    Xor(&(*cpu).A,&(*cpu).A,cpu,mmu);
}

void XorEE(CPU* cpu, MMU* mmu)
{
    // Mnemonic: XOR d8, Length: 2
#ifdef DEBUG
    printf("XOR d8");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 0
    unsigned char mem_byte = mmu_read(mmu,(*cpu).PC++);
    // fetch from memory
    Xor(&(*cpu).A,&mem_byte,cpu,mmu);
}

void Or(unsigned char* A, unsigned char* B, CPU* cpu, MMU* mmu){
    // Generic OR operation
    (*A) = (*A) | (*B);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
         zero = Z_flag;

    (*cpu).F = zero;
}

void OrB0(CPU* cpu, MMU* mmu)
{
    // Mnemonic: OR B, Length: 1
#ifdef DEBUG
    printf("OR B");
#endif
    // Cycles: 4, (Z N H C): Z 0 0 0
    Or(&(*cpu).A,&(*cpu).B, cpu, mmu);
}

void OrB1(CPU* cpu, MMU* mmu)
{
    // Mnemonic: OR C, Length: 1
#ifdef DEBUG
    printf("OR C");
#endif
    // Cycles: 4, (Z N H C): Z 0 0 0
    Or(&(*cpu).A,&(*cpu).C, cpu, mmu);
}

void OrB2(CPU* cpu, MMU* mmu)
{
    // Mnemonic: OR D, Length: 1
#ifdef DEBUG
    printf("OR D");
#endif
    // Cycles: 4, (Z N H C): Z 0 0 0
    Or(&(*cpu).A,&(*cpu).D, cpu, mmu);
}

void OrB3(CPU* cpu, MMU* mmu)
{
    // Mnemonic: OR E, Length: 1
#ifdef DEBUG
    printf("OR E");
#endif
    // Cycles: 4, (Z N H C): Z 0 0 0
    Or(&(*cpu).A,&(*cpu).E, cpu, mmu);
}

void OrB4(CPU* cpu, MMU* mmu)
{
    // Mnemonic: OR H, Length: 1
#ifdef DEBUG
    printf("OR H");
#endif
    // Cycles: 4, (Z N H C): Z 0 0 0
    Or(&(*cpu).A,&(*cpu).H, cpu, mmu);
}

void OrB5(CPU* cpu, MMU* mmu)
{
    // Mnemonic: OR L, Length: 1
#ifdef DEBUG
    printf("OR L");
#endif
    // Cycles: 4, (Z N H C): Z 0 0 0
    Or(&(*cpu).A,&(*cpu).L, cpu, mmu);
}

void OrB6(CPU* cpu, MMU* mmu)
{
    // Mnemonic: OR (HL), Length: 1
#ifdef DEBUG
    printf("OR (HL)");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 0
    unsigned char mem_byte = mmu_read(mmu,(*cpu).HL);
    Or(&(*cpu).A,&mem_byte, cpu, mmu);
}

void OrB7(CPU* cpu, MMU* mmu)
{
    // Mnemonic: OR A, Length: 1
#ifdef DEBUG
    printf("OR A");
#endif
    // Cycles: 4, (Z N H C): Z 0 0 0
    Or(&(*cpu).A,&(*cpu).A, cpu, mmu);
}

void OrF6(CPU* cpu, MMU* mmu)
{
    // Mnemonic: OR d8, Length: 2
#ifdef DEBUG
    printf("OR d8");
#endif
    // Cycles: 8, (Z N H C): Z 0 0 0
    unsigned char mem_byte = mmu_read(mmu,(*cpu).PC++);
    Or(&(*cpu).A,&mem_byte, cpu, mmu);
}

void Cp_8(unsigned char* A, unsigned char* B, CPU* cpu) {
     // bytes with only 4 lower bits
     unsigned char A_4 = *A & 0x0F;
     unsigned char B_4 = *B & 0x0F;

     // update timer
     (*cpu).tick+=4;

     // update flags
     unsigned char carry = 0x0;
     if ((*B) > (*A)){
          carry = C_flag;
     }
     unsigned char half_carry = 0x0;
     if (B_4 > A_4){
          half_carry = H_flag;
     }

     // modify value of A
     unsigned char temp_A = (*A) - (*B);

     unsigned char zero = 0x0;
     if (!temp_A){
          zero = Z_flag;
     }

     (*cpu).F = carry | half_carry | zero | N_flag;
}

void CpB8(CPU* cpu, MMU* mmu)
{
    // Mnemonic: CP B, Length: 1
#ifdef DEBUG
    printf("CP B");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Cp_8(&(*cpu).A,&(*cpu).B, cpu);
}

void CpB9(CPU* cpu, MMU* mmu)
{
    // Mnemonic: CP C, Length: 1
#ifdef DEBUG
    printf("CP C");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Cp_8(&(*cpu).A,&(*cpu).C, cpu);
}

void CpBA(CPU* cpu, MMU* mmu)
{
    // Mnemonic: CP D, Length: 1
#ifdef DEBUG
    printf("CP D");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Cp_8(&(*cpu).A,&(*cpu).D, cpu);
}

void CpBB(CPU* cpu, MMU* mmu)
{
    // Mnemonic: CP E, Length: 1
#ifdef DEBUG
    printf("CP E");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Cp_8(&(*cpu).A,&(*cpu).E, cpu);
}

void CpBC(CPU* cpu, MMU* mmu)
{
    // Mnemonic: CP H, Length: 1
#ifdef DEBUG
    printf("CP H");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
     Cp_8(&(*cpu).A,&(*cpu).H, cpu);
}

void CpBD(CPU* cpu, MMU* mmu)
{
    // Mnemonic: CP L, Length: 1
#ifdef DEBUG
    printf("CP L");
#endif
    // Cycles: 4, (Z N H C): Z 1 H C
    Cp_8(&(*cpu).A,&(*cpu).L, cpu);
}

void CpBE(CPU* cpu, MMU* mmu)
{
    // Mnemonic: CP (HL), Length: 1
#ifdef DEBUG
    printf("CP (HL)");
#endif
    // Cycles: 8, (Z N H C): Z 1 H C
    unsigned char mem_byte = mmu_read(mmu,(*cpu).HL);
    Cp_8(&(*cpu).A,&mem_byte, cpu);
    (*cpu).tick+=4;
}

void CpBF(CPU* cpu, MMU* mmu)
{
    // Mnemonic: CP A, Length: 1
#ifdef DEBUG
    printf("CP A");
#endif
    Cp_8(&(*cpu).A,&(*cpu).A, cpu);
}

void CpFE(CPU* cpu, MMU* mmu)
{
    // Mnemonic: CP d8, Length: 2
#ifdef DEBUG
    printf("CP d8");
#endif
    // Cycles: 8, (Z N H C): Z 1 H C
    unsigned char mem_byte = mmu_read(mmu,(*cpu).PC++);
    Cp_8(&(*cpu).A,&mem_byte, cpu);
    (*cpu).tick+=4;
}

