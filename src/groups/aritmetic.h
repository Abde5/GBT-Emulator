#ifndef ARITMETIC_H
#define ARITMETIC_H

#include "../cpu.h"
#include "../mmu.h"

/*
 * Increment operations.
 */
void Inc03(CPU* cpu, MMU* mmu);
void Inc04(CPU* cpu, MMU* mmu);
void Inc0C(CPU* cpu, MMU* mmu);
void Inc13(CPU* cpu, MMU* mmu);
void Inc14(CPU* cpu, MMU* mmu);
void Inc1C(CPU* cpu, MMU* mmu);
void Inc23(CPU* cpu, MMU* mmu);
void Inc24(CPU* cpu, MMU* mmu);
void Inc2C(CPU* cpu, MMU* mmu);
void Inc33(CPU* cpu, MMU* mmu);
void Inc34(CPU* cpu, MMU* mmu);
void Inc3C(CPU* cpu, MMU* mmu);

/*
 * Decrement operations.
 */
void Dec05(CPU* cpu, MMU* mmu);
void Dec0B(CPU* cpu, MMU* mmu);
void Dec0D(CPU* cpu, MMU* mmu);
void Dec15(CPU* cpu, MMU* mmu);
void Dec1B(CPU* cpu, MMU* mmu);
void Dec1D(CPU* cpu, MMU* mmu);
void Dec25(CPU* cpu, MMU* mmu);
void Dec2B(CPU* cpu, MMU* mmu);
void Dec2D(CPU* cpu, MMU* mmu);
void Dec35(CPU* cpu, MMU* mmu);
void Dec3B(CPU* cpu, MMU* mmu);
void Dec3D(CPU* cpu, MMU* mmu);

/*
 * Addition operations.
 */
void Add09(CPU* cpu, MMU* mmu);
void Add19(CPU* cpu, MMU* mmu);
void Add29(CPU* cpu, MMU* mmu);
void Add39(CPU* cpu, MMU* mmu);
void Add80(CPU* cpu, MMU* mmu);
void Add81(CPU* cpu, MMU* mmu);
void Add82(CPU* cpu, MMU* mmu);
void Add83(CPU* cpu, MMU* mmu);
void Add84(CPU* cpu, MMU* mmu);
void Add85(CPU* cpu, MMU* mmu);
void Add86(CPU* cpu, MMU* mmu);
void Add87(CPU* cpu, MMU* mmu);
void AddC6(CPU* cpu, MMU* mmu);
void AddE8(CPU* cpu, MMU* mmu);

/*
 * DAA instruction -> https://ehaskins.com/2018-01-30%20Z80%20DAA/
 */
void Daa27(CPU* cpu, MMU* mmu);

/*
 * Complement register A.
 */
void Cpl2F(CPU* cpu, MMU* mmu);

/*
 * Set carry flag.
 */
void Scf37(CPU* cpu, MMU* mmu);

/*
 * Complement carry flag.
 */
void Ccf3F(CPU* cpu, MMU* mmu);

/*
 * Add + carry flag.
 */
void Adc88(CPU* cpu, MMU* mmu);
void Adc89(CPU* cpu, MMU* mmu);
void Adc8A(CPU* cpu, MMU* mmu);
void Adc8B(CPU* cpu, MMU* mmu);
void Adc8C(CPU* cpu, MMU* mmu);
void Adc8D(CPU* cpu, MMU* mmu);
void Adc8E(CPU* cpu, MMU* mmu);
void Adc8F(CPU* cpu, MMU* mmu);
void AdcCE(CPU* cpu, MMU* mmu);

/*
 * Substraction operations.
 */
void Sub90(CPU* cpu, MMU* mmu);
void Sub91(CPU* cpu, MMU* mmu);
void Sub92(CPU* cpu, MMU* mmu);
void Sub93(CPU* cpu, MMU* mmu);
void Sub94(CPU* cpu, MMU* mmu);
void Sub95(CPU* cpu, MMU* mmu);
void Sub96(CPU* cpu, MMU* mmu);
void Sub97(CPU* cpu, MMU* mmu);
void SubD6(CPU* cpu, MMU* mmu);

/*
 * Substract with carry.
 */
void Sbc98(CPU* cpu, MMU* mmu);
void Sbc99(CPU* cpu, MMU* mmu);
void Sbc9A(CPU* cpu, MMU* mmu);
void Sbc9B(CPU* cpu, MMU* mmu);
void Sbc9C(CPU* cpu, MMU* mmu);
void Sbc9D(CPU* cpu, MMU* mmu);
void Sbc9E(CPU* cpu, MMU* mmu);
void Sbc9F(CPU* cpu, MMU* mmu);
void SbcDE(CPU* cpu, MMU* mmu);

/*
 * Binary AND operations.
 */
void AndA0(CPU* cpu, MMU* mmu);
void AndA1(CPU* cpu, MMU* mmu);
void AndA2(CPU* cpu, MMU* mmu);
void AndA3(CPU* cpu, MMU* mmu);
void AndA4(CPU* cpu, MMU* mmu);
void AndA5(CPU* cpu, MMU* mmu);
void AndA6(CPU* cpu, MMU* mmu);
void AndA7(CPU* cpu, MMU* mmu);
void AndE6(CPU* cpu, MMU* mmu);

/*
 * Binary XOR operations.
 */
void XorA8(CPU* cpu, MMU* mmu);
void XorA9(CPU* cpu, MMU* mmu);
void XorAA(CPU* cpu, MMU* mmu);
void XorAB(CPU* cpu, MMU* mmu);
void XorAC(CPU* cpu, MMU* mmu);
void XorAD(CPU* cpu, MMU* mmu);
void XorAE(CPU* cpu, MMU* mmu);
void XorAF(CPU* cpu, MMU* mmu);
void XorEE(CPU* cpu, MMU* mmu);

/*
 * Binary OR operations.
 */
void OrB0(CPU* cpu, MMU* mmu);
void OrB1(CPU* cpu, MMU* mmu);
void OrB2(CPU* cpu, MMU* mmu);
void OrB3(CPU* cpu, MMU* mmu);
void OrB4(CPU* cpu, MMU* mmu);
void OrB5(CPU* cpu, MMU* mmu);
void OrB6(CPU* cpu, MMU* mmu);
void OrB7(CPU* cpu, MMU* mmu);
void OrF6(CPU* cpu, MMU* mmu);

/*
 * Comparison operations.
 */
void CpB8(CPU* cpu, MMU* mmu);
void CpB9(CPU* cpu, MMU* mmu);
void CpBA(CPU* cpu, MMU* mmu);
void CpBB(CPU* cpu, MMU* mmu);
void CpBC(CPU* cpu, MMU* mmu);
void CpBD(CPU* cpu, MMU* mmu);
void CpBE(CPU* cpu, MMU* mmu);
void CpBF(CPU* cpu, MMU* mmu);
void CpFE(CPU* cpu, MMU* mmu);

#endif // ARITMETIC_H
