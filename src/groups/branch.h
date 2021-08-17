#ifndef BRANCH_H
#define BRANCH_H

#include "../cpu.h"
#include "../mmu.h"

/*
 * Offset jumps operations.
 */
void Jr18(struct CPU* cpu, struct MMU* mmu);
void Jr20(struct CPU* cpu, struct MMU* mmu);
void Jr28(struct CPU* cpu, struct MMU* mmu);
void Jr30(struct CPU* cpu, struct MMU* mmu);
void Jr38(struct CPU* cpu, struct MMU* mmu);

/*
 * Return operations.
 */
void RetC0(struct CPU* cpu, struct MMU* mmu);
void RetC8(struct CPU* cpu, struct MMU* mmu);
void RetC9(struct CPU* cpu, struct MMU* mmu);
void RetD0(struct CPU* cpu, struct MMU* mmu);
void RetD8(struct CPU* cpu, struct MMU* mmu);

/*
 * Jump operations.
 */
void JpC2(struct CPU* cpu, struct MMU* mmu);
void JpC3(struct CPU* cpu, struct MMU* mmu);
void JpCA(struct CPU* cpu, struct MMU* mmu);
void JpD2(struct CPU* cpu, struct MMU* mmu);
void JpDA(struct CPU* cpu, struct MMU* mmu);
void JpE9(struct CPU* cpu, struct MMU* mmu);

/*
 * Call subroutine operations.
 */
void CallC4(struct CPU* cpu, struct MMU* mmu);
void CallCC(struct CPU* cpu, struct MMU* mmu);
void CallCD(struct CPU* cpu, struct MMU* mmu);
void CallD4(struct CPU* cpu, struct MMU* mmu);
void CallDC(struct CPU* cpu, struct MMU* mmu);

/*
 * Restart operations:
 *     - Push address onto stack.
 *     - Jump to address 'n' -> 'n' defined by opcode operation.
 */
void RstC7(struct CPU* cpu, struct MMU* mmu);
void RstCF(struct CPU* cpu, struct MMU* mmu);
void RstD7(struct CPU* cpu, struct MMU* mmu);
void RstDF(struct CPU* cpu, struct MMU* mmu);
void RstE7(struct CPU* cpu, struct MMU* mmu);
void RstEF(struct CPU* cpu, struct MMU* mmu);
void RstF7(struct CPU* cpu, struct MMU* mmu);
void RstFF(struct CPU* cpu, struct MMU* mmu);

/*
 * Return + interrupt operations:
 *     - POP two bytes from stack.
 *     - Jump to address from popped bytes.
 *     - Enable interrupts.
 */
void RetiD9(struct CPU* cpu, struct MMU* mmu);

#endif // BRANCH_H
