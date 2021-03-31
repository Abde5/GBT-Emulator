#ifndef ARITMETIC_H
#define ARITMETIC_H

#include "../cpu.h"
#include "../mmu.h"

/*
 * Increment operations.
 */
void Inc03(struct CPU* cpu, struct MMU* mmu);
void Inc04(struct CPU* cpu, struct MMU* mmu);
void Inc0C(struct CPU* cpu, struct MMU* mmu);
void Inc13(struct CPU* cpu, struct MMU* mmu);
void Inc14(struct CPU* cpu, struct MMU* mmu);
void Inc1C(struct CPU* cpu, struct MMU* mmu);
void Inc23(struct CPU* cpu, struct MMU* mmu);
void Inc24(struct CPU* cpu, struct MMU* mmu);
void Inc2C(struct CPU* cpu, struct MMU* mmu);
void Inc33(struct CPU* cpu, struct MMU* mmu);
void Inc34(struct CPU* cpu, struct MMU* mmu);
void Inc3C(struct CPU* cpu, struct MMU* mmu);

/*
 * Decrement operations.
 */
void Dec05(struct CPU* cpu, struct MMU* mmu);
void Dec0B(struct CPU* cpu, struct MMU* mmu);
void Dec0D(struct CPU* cpu, struct MMU* mmu);
void Dec15(struct CPU* cpu, struct MMU* mmu);
void Dec1B(struct CPU* cpu, struct MMU* mmu);
void Dec1D(struct CPU* cpu, struct MMU* mmu);
void Dec25(struct CPU* cpu, struct MMU* mmu);
void Dec2B(struct CPU* cpu, struct MMU* mmu);
void Dec2D(struct CPU* cpu, struct MMU* mmu);
void Dec35(struct CPU* cpu, struct MMU* mmu);
void Dec3B(struct CPU* cpu, struct MMU* mmu);
void Dec3D(struct CPU* cpu, struct MMU* mmu);

/*
 * Addition operations.
 */
void Add09(struct CPU* cpu, struct MMU* mmu);
void Add19(struct CPU* cpu, struct MMU* mmu);
void Add29(struct CPU* cpu, struct MMU* mmu);
void Add39(struct CPU* cpu, struct MMU* mmu);
void Add80(struct CPU* cpu, struct MMU* mmu);
void Add81(struct CPU* cpu, struct MMU* mmu);
void Add82(struct CPU* cpu, struct MMU* mmu);
void Add83(struct CPU* cpu, struct MMU* mmu);
void Add84(struct CPU* cpu, struct MMU* mmu);
void Add85(struct CPU* cpu, struct MMU* mmu);
void Add86(struct CPU* cpu, struct MMU* mmu);
void Add87(struct CPU* cpu, struct MMU* mmu);
void AddC6(struct CPU* cpu, struct MMU* mmu);
void AddE8(struct CPU* cpu, struct MMU* mmu);

/*
 * DAA instruction -> https://ehaskins.com/2018-01-30%20Z80%20DAA/
 */
void Daa27(struct CPU* cpu, struct MMU* mmu);

/*
 * Complement register A.
 */
void Cpl2F(struct CPU* cpu, struct MMU* mmu);

/*
 * Set carry flag.
 */
void Scf37(struct CPU* cpu, struct MMU* mmu);

/*
 * Complement carry flag.
 */
void Ccf3F(struct CPU* cpu, struct MMU* mmu);

/*
 * Add + carry flag.
 */
void Adc88(struct CPU* cpu, struct MMU* mmu);
void Adc89(struct CPU* cpu, struct MMU* mmu);
void Adc8A(struct CPU* cpu, struct MMU* mmu);
void Adc8B(struct CPU* cpu, struct MMU* mmu);
void Adc8C(struct CPU* cpu, struct MMU* mmu);
void Adc8D(struct CPU* cpu, struct MMU* mmu);
void Adc8E(struct CPU* cpu, struct MMU* mmu);
void Adc8F(struct CPU* cpu, struct MMU* mmu);
void AdcCE(struct CPU* cpu, struct MMU* mmu);

/*
 * Substraction operations.
 */
void Sub90(struct CPU* cpu, struct MMU* mmu);
void Sub91(struct CPU* cpu, struct MMU* mmu);
void Sub92(struct CPU* cpu, struct MMU* mmu);
void Sub93(struct CPU* cpu, struct MMU* mmu);
void Sub94(struct CPU* cpu, struct MMU* mmu);
void Sub95(struct CPU* cpu, struct MMU* mmu);
void Sub96(struct CPU* cpu, struct MMU* mmu);
void Sub97(struct CPU* cpu, struct MMU* mmu);
void SubD6(struct CPU* cpu, struct MMU* mmu);

/*
 * Substract with carry.
 */
void Sbc98(struct CPU* cpu, struct MMU* mmu);
void Sbc99(struct CPU* cpu, struct MMU* mmu);
void Sbc9A(struct CPU* cpu, struct MMU* mmu);
void Sbc9B(struct CPU* cpu, struct MMU* mmu);
void Sbc9C(struct CPU* cpu, struct MMU* mmu);
void Sbc9D(struct CPU* cpu, struct MMU* mmu);
void Sbc9E(struct CPU* cpu, struct MMU* mmu);
void Sbc9F(struct CPU* cpu, struct MMU* mmu);
void SbcDE(struct CPU* cpu, struct MMU* mmu);

/*
 * Binary AND operations.
 */
void AndA0(struct CPU* cpu, struct MMU* mmu);
void AndA1(struct CPU* cpu, struct MMU* mmu);
void AndA2(struct CPU* cpu, struct MMU* mmu);
void AndA3(struct CPU* cpu, struct MMU* mmu);
void AndA4(struct CPU* cpu, struct MMU* mmu);
void AndA5(struct CPU* cpu, struct MMU* mmu);
void AndA6(struct CPU* cpu, struct MMU* mmu);
void AndA7(struct CPU* cpu, struct MMU* mmu);
void AndE6(struct CPU* cpu, struct MMU* mmu);

/*
 * Binary XOR operations.
 */
void XorA8(struct CPU* cpu, struct MMU* mmu);
void XorA9(struct CPU* cpu, struct MMU* mmu);
void XorAA(struct CPU* cpu, struct MMU* mmu);
void XorAB(struct CPU* cpu, struct MMU* mmu);
void XorAC(struct CPU* cpu, struct MMU* mmu);
void XorAD(struct CPU* cpu, struct MMU* mmu);
void XorAE(struct CPU* cpu, struct MMU* mmu);
void XorAF(struct CPU* cpu, struct MMU* mmu);
void XorEE(struct CPU* cpu, struct MMU* mmu);

/*
 * Binary OR operations.
 */
void OrB0(struct CPU* cpu, struct MMU* mmu);
void OrB1(struct CPU* cpu, struct MMU* mmu);
void OrB2(struct CPU* cpu, struct MMU* mmu);
void OrB3(struct CPU* cpu, struct MMU* mmu);
void OrB4(struct CPU* cpu, struct MMU* mmu);
void OrB5(struct CPU* cpu, struct MMU* mmu);
void OrB6(struct CPU* cpu, struct MMU* mmu);
void OrB7(struct CPU* cpu, struct MMU* mmu);
void OrF6(struct CPU* cpu, struct MMU* mmu);

/*
 * Comparison operations.
 */
void CpB8(struct CPU* cpu, struct MMU* mmu);
void CpB9(struct CPU* cpu, struct MMU* mmu);
void CpBA(struct CPU* cpu, struct MMU* mmu);
void CpBB(struct CPU* cpu, struct MMU* mmu);
void CpBC(struct CPU* cpu, struct MMU* mmu);
void CpBD(struct CPU* cpu, struct MMU* mmu);
void CpBE(struct CPU* cpu, struct MMU* mmu);
void CpBF(struct CPU* cpu, struct MMU* mmu);
void CpFE(struct CPU* cpu, struct MMU* mmu);

#endif // ARITMETIC_H
