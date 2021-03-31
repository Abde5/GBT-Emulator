#include "aritmetic.h"

void Inc03(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC BC, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Inc03)");
}

void Inc04(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC B, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H -
    printf("Not implemented! (Inc04)");
}

void Inc0C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC C, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H -
    printf("Not implemented! (Inc0C)");
}

void Inc13(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC DE, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Inc13)");
}

void Inc14(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC D, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H -
    printf("Not implemented! (Inc14)");
}

void Inc1C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC E, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H -
    printf("Not implemented! (Inc1C)");
}

void Inc23(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC HL, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Inc23)");
}

void Inc24(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC H, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H -
    printf("Not implemented! (Inc24)");
}

void Inc2C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC L, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H -
    printf("Not implemented! (Inc2C)");
}

void Inc33(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC SP, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Inc33)");
}

void Inc34(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC (HL), Length: 1
    // Cycles: 12, (Z N H C): Z 0 H -
    printf("Not implemented! (Inc34)");
}

void Inc3C(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: INC A, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H -
    printf("Not implemented! (Inc3C)");
}

void Dec05(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC B, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H -
    printf("Not implemented! (Dec05)");
}

void Dec0B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC BC, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Dec0B)");
}

void Dec0D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC C, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H -
    printf("Not implemented! (Dec0D)");
}

void Dec15(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC D, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H -
    printf("Not implemented! (Dec15)");
}

void Dec1B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC DE, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Dec1B)");
}

void Dec1D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC E, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H -
    printf("Not implemented! (Dec1D)");
}

void Dec25(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC H, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H -
    printf("Not implemented! (Dec25)");
}

void Dec2B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC HL, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Dec2B)");
}

void Dec2D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC L, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H -
    printf("Not implemented! (Dec2D)");
}

void Dec35(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC (HL), Length: 1
    // Cycles: 12, (Z N H C): Z 1 H -
    printf("Not implemented! (Dec35)");
}

void Dec3B(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC SP, Length: 1
    // Cycles: 8, (Z N H C): - - - -
    printf("Not implemented! (Dec3B)");
}

void Dec3D(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: DEC A, Length: 1
    // Cycles: 4, (Z N H C): Z 1 H -
    printf("Not implemented! (Dec3D)");
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

void Add80(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: ADD A,B, Length: 1
    // Cycles: 4, (Z N H C): Z 0 H C
    printf("Not implemented! (Add80)");
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
    printf("Not implemented! (Cpl2F)");
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

void AndA0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND B, Length: 1
    // Cycles: 4, (Z N H C): Z 0 1 0
    printf("Not implemented! (AndA0)");
}

void AndA1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND C, Length: 1
    // Cycles: 4, (Z N H C): Z 0 1 0
    printf("Not implemented! (AndA1)");
}

void AndA2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND D, Length: 1
    // Cycles: 4, (Z N H C): Z 0 1 0
    printf("Not implemented! (AndA2)");
}

void AndA3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND E, Length: 1
    // Cycles: 4, (Z N H C): Z 0 1 0
    printf("Not implemented! (AndA3)");
}

void AndA4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND H, Length: 1
    // Cycles: 4, (Z N H C): Z 0 1 0
    printf("Not implemented! (AndA4)");
}

void AndA5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND L, Length: 1
    // Cycles: 4, (Z N H C): Z 0 1 0
    printf("Not implemented! (AndA5)");
}

void AndA6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND (HL), Length: 1
    // Cycles: 8, (Z N H C): Z 0 1 0
    printf("Not implemented! (AndA6)");
}

void AndA7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND A, Length: 1
    // Cycles: 4, (Z N H C): Z 0 1 0
    printf("Not implemented! (AndA7)");
}

void AndE6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: AND d8, Length: 2
    // Cycles: 8, (Z N H C): Z 0 1 0
    printf("Not implemented! (AndE6)");
}

void XorA8(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR B, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    printf("Not implemented! (XorA8)");
}

void XorA9(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR C, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    printf("Not implemented! (XorA9)");
}

void XorAA(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR D, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    printf("Not implemented! (XorAA)");
}

void XorAB(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR E, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    printf("Not implemented! (XorAB)");
}

void XorAC(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR H, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    printf("Not implemented! (XorAC)");
}

void XorAD(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR L, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    printf("Not implemented! (XorAD)");
}

void XorAE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR (HL), Length: 1
    // Cycles: 8, (Z N H C): Z 0 0 0
    printf("Not implemented! (XorAE)");
}

void XorAF(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR A, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    printf("Not implemented! (XorAF)");
}

void XorEE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: XOR d8, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 0
    printf("Not implemented! (XorEE)");
}

void OrB0(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR B, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    printf("Not implemented! (OrB0)");
}

void OrB1(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR C, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    printf("Not implemented! (OrB1)");
}

void OrB2(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR D, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    printf("Not implemented! (OrB2)");
}

void OrB3(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR E, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    printf("Not implemented! (OrB3)");
}

void OrB4(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR H, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    printf("Not implemented! (OrB4)");
}

void OrB5(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR L, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    printf("Not implemented! (OrB5)");
}

void OrB6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR (HL), Length: 1
    // Cycles: 8, (Z N H C): Z 0 0 0
    printf("Not implemented! (OrB6)");
}

void OrB7(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR A, Length: 1
    // Cycles: 4, (Z N H C): Z 0 0 0
    printf("Not implemented! (OrB7)");
}

void OrF6(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: OR d8, Length: 2
    // Cycles: 8, (Z N H C): Z 0 0 0
    printf("Not implemented! (OrF6)");
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
    // Cycles: 4, (Z N H C): Z 1 H C
    printf("Not implemented! (CpBF)");
}

void CpFE(struct CPU* cpu, struct MMU* mmu)
{
    // Mnemonic: CP d8, Length: 2
    // Cycles: 8, (Z N H C): Z 1 H C
    printf("Not implemented! (CpFE)");
}

