.globl main
.text
main:
L0_1: push %rbp
L0_2: movq %rsp, %rbp
L0_3: subq $64, %rsp

#L1: t1 = y + 3

L1_1: movq -16(%rbp), %rax
L1_2: movq $3, %rbx
L1_3: addq %rbx, %rax
L1_4: movq %rax, -32(%rbp)

#L2: t2 = t1 + 5

L2_1: movq -32(%rbp), %rax
L2_2: movq $5, %rbx
L2_3: addq %rbx, %rax
L2_4: movq %rax, -48(%rbp)

#L3: x = t2

L3_1: movq -48(%rbp), %rax
L3_2: movq %rax, -64(%rbp)

#L4: param x

L4_1: movq -64(%rbp), %rdi

#L5: param x

L5_2: movq -64(%rbp), %rsi

#L6: param x

L6_3: movq -64(%rbp), %rdx

#L7: call "printf", 3

L7_1: call printf

#L8: halt

L8_1: addq $64, %rsp
L8_2: pop %rbp
L8_3: ret

