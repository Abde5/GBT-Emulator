#include "aritmetic.h"

void Inc(unsigned char* A){
    // Generic INC operation

    (*A)++;
}

void Inc03(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC BC, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    (*cpu).BC++;

    // update timer
    (*cpu).tick+=8;
}

void Inc04(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC B, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H -
    unsigned char hilow_bit = (*cpu).B & (1 << 3);
    Inc(&(*cpu).B);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).B == 0x0){
            zero = Z_flag;
    }
    unsigned char half_carry = 0x0;
    if (hilow_bit == 1<<3){
        // verificar si ha cambiado de estado
        if (((*cpu).B & (1 << 3)) == 0x0)
            half_carry = H_flag;
    }

    (*cpu).F = ((*cpu).F & C_flag) | zero | half_carry;
}

void Inc0C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC C, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H -
    unsigned char hilow_bit = (*cpu).C & (1 << 3);
    Inc(&(*cpu).C);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).C == 0x0){
            zero = Z_flag;
    }
    unsigned char half_carry = 0x0;
    if (hilow_bit == 1<<3){
            // verificar si ha cambiado de estado
            if (((*cpu).C & (1 << 3)) == 0x0)
                    half_carry = H_flag;
    }

    (*cpu).F = ((*cpu).F & C_flag) | zero | half_carry;
}

void Inc13(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC DE, Length: 1
    // Cycles: 8, (Z N H C): - - - -
   (*cpu).DE++;

   // update timer
   (*cpu).tick+=8;
}

void Inc14(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC D, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H -
     unsigned char hilow_bit = (*cpu).D & (1 << 3);
     Inc(&(*cpu).D);

     // update timer
     (*cpu).tick+=4;

     // update flags
     unsigned char zero = 0x0;
     if ((*cpu).D == 0x0){
          zero = Z_flag;
     }
     unsigned char half_carry = 0x0;
     if (hilow_bit == 1<<3){
          // verificar si ha cambiado de estado
          if (((*cpu).D & (1 << 3)) == 0x0)
               half_carry = H_flag;
     }

     (*cpu).F = ((*cpu).F & C_flag) | zero | half_carry;
}

void Inc1C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC E, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H -
    unsigned char hilow_bit = (*cpu).E & (1 << 3);
    Inc(&(*cpu).E);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).E == 0x0){
         zero = Z_flag;
    }
    unsigned char half_carry = 0x0;
    if (hilow_bit == 1<<3){
         // verificar si ha cambiado de estado
         if (((*cpu).E & (1 << 3)) == 0x0)
              half_carry = H_flag;
    }

    (*cpu).F = ((*cpu).F & C_flag) | zero | half_carry;
}

void Inc23(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC HL, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    (*cpu).HL++;

    // update timer
    (*cpu).tick+=8;
}

void Inc24(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC H, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H -
    unsigned char hilow_bit = (*cpu).H & (1 << 3);
    Inc(&(*cpu).H);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).H == 0x0){
         zero = Z_flag;
    }
    unsigned char half_carry = 0x0;
    if (hilow_bit == 1<<3){
         // verificar si ha cambiado de estado
         if (((*cpu).H & (1 << 3)) == 0x0)
              half_carry = H_flag;
    }

    (*cpu).F = ((*cpu).F & C_flag) | zero | half_carry;
}

void Inc2C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC L, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H -
    unsigned char hilow_bit = (*cpu).L & (1 << 3);
    Inc(&(*cpu).L);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).L == 0x0){
         zero = Z_flag;
    }
    unsigned char half_carry = 0x0;
    if (hilow_bit == 1<<3){
         // verificar si ha cambiado de estado
         if (((*cpu).L & (1 << 3)) == 0x0)
              half_carry = H_flag;
    }

    (*cpu).F = ((*cpu).F & C_flag) | zero | half_carry;
}

void Inc33(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC SP, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    (*cpu).SP++;

    // update timer
    (*cpu).tick+=8;
}

void Inc34(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC (HL), Length: 1
    // Cycles: 12, (Z N H C): Z 0 H -

    unsigned char read_byte = mmu_read(mmu, (*cpu).HL);
    unsigned char hilow_bit = read_byte & (1 << 3);
    Inc(&read_byte);

    // update timer
    (*cpu).tick+=12;

    // update flags
    unsigned char zero = 0x0;
    if (read_byte == 0x0){
         zero = Z_flag;
    }
    unsigned char half_carry = 0x0;
    if (hilow_bit == 1<<3){
         // verificar si ha cambiado de estado
         if ((read_byte & (1 << 3)) == 0x0)
              half_carry = H_flag;
    }

    (*cpu).F = ((*cpu).F & C_flag) | zero | half_carry;

    mmu_write(mmu, (*cpu).HL, read_byte);
}

void Inc3C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC A, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H -
    unsigned char hilow_bit = (*cpu).A & (1 << 3);
    Inc(&(*cpu).A);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0){
         zero = Z_flag;
    }
    unsigned char half_carry = 0x0;
    if (hilow_bit == 1<<3){
         // verificar si ha cambiado de estado
         if (((*cpu).A & (1 << 3)) == 0x0)
              half_carry = H_flag;
    }

    (*cpu).F = ((*cpu).F & C_flag) | zero | half_carry;
}

void Dec(unsigned char* A){
     // Generic DEC operation

     (*A)--;
}

void Dec05(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC B, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H -
    unsigned char hilow_bit = (*cpu).B & (1 << 4);
    Dec(&(*cpu).B);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).B == 0x0){
         zero = Z_flag;
    }
    unsigned char half_carry = 0x0;
    if (hilow_bit == 1<<4){
         // verificar si ha cambiado de estado
         if (((*cpu).B & (1 << 4)) == 0x0)
              half_carry = H_flag;
    }

    (*cpu).F = ((*cpu).F & C_flag) | N_flag | zero | half_carry;
}

void Dec0B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC BC, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    (*cpu).BC--;

    // update timer
    (*cpu).tick+=8;
}

void Dec0D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC C, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H -
    unsigned char hilow_bit = (*cpu).C & (1 << 4);
    Dec(&(*cpu).C);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).C == 0x0){
         zero = Z_flag;
    }
    unsigned char half_carry = 0x0;
    if (hilow_bit == 1<<4){
         // verificar si ha cambiado de estado
         if (((*cpu).C & (1 << 4)) == 0x0)
              half_carry = H_flag;
    }

    (*cpu).F = ((*cpu).F & C_flag) | N_flag | zero | half_carry;
}

void Dec15(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC D, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H -
    unsigned char hilow_bit = (*cpu).D & (1 << 4);
    Dec(&(*cpu).D);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).D == 0x0){
         zero = Z_flag;
    }
    unsigned char half_carry = 0x0;
    if (hilow_bit == 1<<4){
         // verificar si ha cambiado de estado
         if (((*cpu).D & (1 << 4)) == 0x0)
              half_carry = H_flag;
    }

    (*cpu).F = ((*cpu).F & C_flag) | N_flag | zero | half_carry;
}

void Dec1B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC DE, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    (*cpu).DE--;

    // update timer
    (*cpu).tick+=8;
}

void Dec1D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC E, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H -
    unsigned char hilow_bit = (*cpu).E & (1 << 4);
    Dec(&(*cpu).E);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).E == 0x0){
         zero = Z_flag;
    }
    unsigned char half_carry = 0x0;
    if (hilow_bit == 1<<4){
         // verificar si ha cambiado de estado
         if (((*cpu).E & (1 << 4)) == 0x0)
              half_carry = H_flag;
    }

    (*cpu).F = ((*cpu).F & C_flag) | N_flag | zero | half_carry;
}

void Dec25(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC H, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H -
    unsigned char hilow_bit = (*cpu).H & (1 << 4);
    Dec(&(*cpu).H);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).H == 0x0){
         zero = Z_flag;
    }
    unsigned char half_carry = 0x0;
    if (hilow_bit == 1<<4){
         // verificar si ha cambiado de estado
         if (((*cpu).H & (1 << 4)) == 0x0)
              half_carry = H_flag;
    }

    (*cpu).F = ((*cpu).F & C_flag) | N_flag | zero | half_carry;
}

void Dec2B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC HL, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    (*cpu).HL--;

    // update timer
    (*cpu).tick+=8;
}

void Dec2D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC L, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H -
    unsigned char hilow_bit = (*cpu).L & (1 << 4);
    Dec(&(*cpu).L);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).L == 0x0){
         zero = Z_flag;
    }
    unsigned char half_carry = 0x0;
    if (hilow_bit == 1<<4){
         // verificar si ha cambiado de estado
         if (((*cpu).L & (1 << 4)) == 0x0)
              half_carry = H_flag;
    }

    (*cpu).F = ((*cpu).F & C_flag) | N_flag | zero | half_carry;
}

void Dec35(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC (HL), Length: 1
    // Cycles: 12, (Z N H C): Z 1 H -
     unsigned char read_byte = mmu_read(mmu, (*cpu).HL);
     unsigned char hilow_bit = read_byte & (1 << 4);
     Dec(&read_byte);

     // update timer
     (*cpu).tick+=12;

     // update flags
     unsigned char zero = 0x0;
     if (read_byte == 0x0){
          zero = Z_flag;
     }
     unsigned char half_carry = 0x0;
     if (hilow_bit == 1<<4){
          // verificar si ha cambiado de estado
          if ((read_byte & (1 << 4)) == 0x0)
               half_carry = H_flag;
     }

     (*cpu).F = ((*cpu).F & C_flag) | N_flag | zero | half_carry;

     mmu_write(mmu, (*cpu).HL, read_byte);
}

void Dec3B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC SP, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    (*cpu).SP--;

    // update timer
    (*cpu).tick+=8;
}

void Dec3D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC A, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H -
    unsigned char hilow_bit = (*cpu).A & (1 << 4);
    Dec(&(*cpu).A);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0){
         zero = Z_flag;
    }
    unsigned char half_carry = 0x0;
    if (hilow_bit == 1<<4){
         // verificar si ha cambiado de estado
         if (((*cpu).A & (1 << 4)) == 0x0)
              half_carry = H_flag;
    }

    (*cpu).F = ((*cpu).F & C_flag) | N_flag | zero | half_carry;
}

void Add09(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADD HL,BC, Length: 1
    // Cycles: 8, (Z N H C): - 0 H C
    printf("Not implemented! (Add09)");
}

void Add19(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADD HL,DE, Length: 1
    // Cycles: 8, (Z N H C): - 0 H C
    printf("Not implemented! (Add19)");
}

void Add29(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADD HL,HL, Length: 1
    // Cycles: 8, (Z N H C): - 0 H C
    printf("Not implemented! (Add29)");
}

void Add39(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADD HL,SP, Length: 1
    // Cycles: 8, (Z N H C): - 0 H C
    printf("Not implemented! (Add39)");
}


void Add_8(unsigned char* A, unsigned char* B) {
     (*A) += (*B);
}

void Add80(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADD A,B, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H C
    /*
    //unsigned char hilow_bit = (*cpu).L & (1 << 4);
    Add_8(&(*CPU).A,&(*CPU).B);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).L == 0x0){
         zero = Z_flag;
    }

    unsigned char half_carry = 0x0;
    if (hilow_bit == 1<<4){
         // verificar si ha cambiado de estado
         if (((*cpu).L & (1 << 4)) == 0x0)
              half_carry = H_flag;
    }

    (*cpu).F = ((*cpu).F & C_flag) | N_flag | zero | half_carry;
    */
}

void Add81(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADD A,C, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H C
    printf("Not implemented! (Add81)");
}

void Add82(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADD A,D, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H C
    printf("Not implemented! (Add82)");
}

void Add83(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADD A,E, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H C
    printf("Not implemented! (Add83)");
}

void Add84(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADD A,H, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H C
    printf("Not implemented! (Add84)");
}

void Add85(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADD A,L, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H C
    printf("Not implemented! (Add85)");
}

void Add86(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADD A,(HL), Length: 1
    // Cycles: 8, (Z N H C): Z 0 H C
    printf("Not implemented! (Add86)");
}

void Add87(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADD A,A, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H C
    printf("Not implemented! (Add87)");
}

void AddC6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADD A,d8, Length: 2
    // Cycles: 8, (Z N H C): Z 0 H C
    printf("Not implemented! (AddC6)");
}

void AddE8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADD SP,r8, Length: 2
    // Cycles: 16, (Z N H C): 0 0 H C
    printf("Not implemented! (AddE8)");
}

void Daa27(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DAA, Length: 1
    // Cycles: 4, (Z N H C): Z - 0 C
    printf("Not implemented! (Daa27)");
}

void Cpl2F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CPL, Length: 1
    // Cycles: 4, (Z N H C): - 1 1 -
    (*cpu).A = ~(*cpu).A;

    // update timer
    (*cpu).tick+=4;

    // update flags
    (*cpu).F = (N_flag | H_flag) | ((*cpu).F & (Z_flag | C_flag));
}

void Scf37(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SCF, Length: 1
    // Cycles: 4, (Z N H C): - 0 0 1
    printf("Not implemented! (Scf37)");
}

void Ccf3F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CCF, Length: 1
    // Cycles: 4, (Z N H C): - 0 0 C
    printf("Not implemented! (Ccf3F)");
}

void Adc88(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADC A,B, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H C
    printf("Not implemented! (Adc88)");
}

void Adc89(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADC A,C, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H C
    printf("Not implemented! (Adc89)");
}

void Adc8A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADC A,D, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H C
    printf("Not implemented! (Adc8A)");
}

void Adc8B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADC A,E, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H C
    printf("Not implemented! (Adc8B)");
}

void Adc8C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADC A,H, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H C
    printf("Not implemented! (Adc8C)");
}

void Adc8D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADC A,L, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H C
    printf("Not implemented! (Adc8D)");
}

void Adc8E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADC A,(HL), Length: 1
    // Cycles: 8, (Z N H C): Z 0 H C
    printf("Not implemented! (Adc8E)");
}

void Adc8F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADC A,A, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H C
    printf("Not implemented! (Adc8F)");
}

void AdcCE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADC A,d8, Length: 2
    // Cycles: 8, (Z N H C): Z 0 H C
    printf("Not implemented! (AdcCE)");
}

void Sub90(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SUB B, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (Sub90)");
}

void Sub91(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SUB C, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (Sub91)");
}

void Sub92(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SUB D, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (Sub92)");
}

void Sub93(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SUB E, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (Sub93)");
}

void Sub94(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SUB H, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (Sub94)");
}

void Sub95(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SUB L, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (Sub95)");
}

void Sub96(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SUB (HL), Length: 1
    // Cycles: 8, (Z N H C): Z 1 H C
    printf("Not implemented! (Sub96)");
}

void Sub97(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SUB A, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (Sub97)");
}

void SubD6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SUB d8, Length: 2
    // Cycles: 8, (Z N H C): Z 1 H C
    printf("Not implemented! (SubD6)");
}

void Sbc98(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SBC A,B, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (Sbc98)");
}

void Sbc99(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SBC A,C, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (Sbc99)");
}

void Sbc9A(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SBC A,D, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (Sbc9A)");
}

void Sbc9B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SBC A,E, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (Sbc9B)");
}

void Sbc9C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SBC A,H, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (Sbc9C)");
}

void Sbc9D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SBC A,L, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (Sbc9D)");
}

void Sbc9E(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SBC A,(HL), Length: 1
    // Cycles: 8, (Z N H C): Z 1 H C
    printf("Not implemented! (Sbc9E)");
}

void Sbc9F(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SBC A,A, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (Sbc9F)");
}

void SbcDE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: SBC A,d8, Length: 2
    // Cycles: 8, (Z N H C): Z 1 H C
    printf("Not implemented! (SbcDE)");
}


void And(unsigned char* A, unsigned char* B){
    // Generic AND operation

    (*A) = (*A) & (*B);
}

void AndA0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND B, Length: 1
    // Cycles: 4, (Z N H C): Z 0 1 0

    And(&(*cpu).A,&(*cpu).B);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
        zero = Z_flag;

    (*cpu).F = zero | H_flag;
}

void AndA1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND C, Length: 1
    // Cycles: 4, (Z N H C): Z 0 1 0
    And(&(*cpu).A,&(*cpu).C);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero | H_flag;
}

void AndA2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND D, Length: 1
    // Cycles: 4, (Z N H C): Z 0 1 0
    And(&(*cpu).A,&(*cpu).D);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero | H_flag;
}

void AndA3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND E, Length: 1
    // Cycles: 4, (Z N H C): Z 0 1 0
    And(&(*cpu).A,&(*cpu).E);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero | H_flag;
}

void AndA4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND H, Length: 1
    // Cycles: 4, (Z N H C): Z 0 1 0
    And(&(*cpu).A,&(*cpu).H);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero | H_flag;
}

void AndA5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND L, Length: 1
    // Cycles: 4, (Z N H C): Z 0 1 0
    And(&(*cpu).A,&(*cpu).L);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero | H_flag;
}

void AndA6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND (HL), Length: 1
    // Cycles: 8, (Z N H C): Z 0 1 0


    unsigned char mem_byte = mmu_read(mmu,(*cpu).HL);
    // fetch from memory
    And(&(*cpu).A,&mem_byte);

    // update timer
    (*cpu).tick+=8;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero | H_flag;
}

void AndA7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND A, Length: 1
    // Cycles: 4, (Z N H C): Z 0 1 0
    And(&(*cpu).A,&(*cpu).A);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero | H_flag;
}

void AndE6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND d8, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 0
    unsigned char mem_byte = mmu_read(mmu,(*cpu).PC++);
    // fetch from memory
    And(&(*cpu).A,&mem_byte);

    // update timer
    (*cpu).tick+=8;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero | H_flag;
}

void Xor(unsigned char* A, unsigned char* B){
        // Generic XOR operation

        (*A) = (*A) ^ (*B);
}

void XorA8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR B, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    Xor(&(*cpu).A,&(*cpu).B);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void XorA9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR C, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    Xor(&(*cpu).A,&(*cpu).C);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void XorAA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR D, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    Xor(&(*cpu).A,&(*cpu).D);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void XorAB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR E, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    Xor(&(*cpu).A,&(*cpu).E);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void XorAC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR H, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    Xor(&(*cpu).A,&(*cpu).H);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void XorAD(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR L, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    Xor(&(*cpu).A,&(*cpu).L);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void XorAE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR (HL), Length: 1
    // Cycles: 8, (Z N H C): Z 0 0 0
    unsigned char mem_byte = mmu_read(mmu,(*cpu).HL);
    // fetch from memory
    Xor(&(*cpu).A,&mem_byte);

    // update timer
    (*cpu).tick+=8;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void XorAF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR A, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    Xor(&(*cpu).A,&(*cpu).A);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void XorEE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR d8, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 0
    unsigned char mem_byte = mmu_read(mmu,(*cpu).PC++);
    // fetch from memory
    Xor(&(*cpu).A,&mem_byte);

    // update timer
    (*cpu).tick+=8;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void Or(unsigned char* A, unsigned char* B){
        // Generic OR operation

        (*A) = (*A) | (*B);
}

void OrB0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR B, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    Or(&(*cpu).A,&(*cpu).B);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void OrB1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR C, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    Or(&(*cpu).A,&(*cpu).C);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void OrB2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR D, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    Or(&(*cpu).A,&(*cpu).D);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void OrB3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR E, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    Or(&(*cpu).A,&(*cpu).E);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void OrB4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR H, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    Or(&(*cpu).A,&(*cpu).H);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void OrB5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR L, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    Or(&(*cpu).A,&(*cpu).L);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void OrB6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR (HL), Length: 1
    // Cycles: 8, (Z N H C): Z 0 0 0
    unsigned char mem_byte = mmu_read(mmu,(*cpu).HL);
    // fetch from memory
    Or(&(*cpu).A,&mem_byte);

    // update timer
    (*cpu).tick+=8;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void OrB7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR A, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    Or(&(*cpu).A,&(*cpu).A);

    // update timer
    (*cpu).tick+=4;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void OrF6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR d8, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 0
    unsigned char mem_byte = mmu_read(mmu,(*cpu).PC++);
    // fetch from memory
    Or(&(*cpu).A,&mem_byte);

    // update timer
    (*cpu).tick+=8;

    // update flags
    unsigned char zero = 0x0;
    if ((*cpu).A == 0x0)
            zero = Z_flag;

    (*cpu).F = zero;
}

void CpB8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CP B, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (CpB8)");
}

void CpB9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CP C, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (CpB9)");
}

void CpBA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CP D, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (CpBA)");
}

void CpBB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CP E, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (CpBB)");
}

void CpBC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CP H, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (CpBC)");
}

void CpBD(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CP L, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (CpBD)");
}

void CpBE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CP (HL), Length: 1
    // Cycles: 8, (Z N H C): Z 1 H C
    printf("Not implemented! (CpBE)");
}

void CpBF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CP A, Length: 1
    printf("Not implemented! (CpBF)");
}

void CpFE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CP d8, Length: 2
    // Cycles: 8, (Z N H C): Z 1 H C
    printf("Not implemented! (CpFE)");
}

