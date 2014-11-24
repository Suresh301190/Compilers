#function main:
#L2: b = 5
#L3: t1 = b != 5
#L4: if t1 goto L6
#L5: ifFalse t1 goto L7
#L6: i = 9
#L7: i = 2
#L8: t2 = b + i
#L9: a = t2
#L10: "%d\n" = param (null)
#L11: a = param (null)
#L12: (null) = "printf" call 2
#L13: t3 = i == 2
#L14: if t3 goto L16
#L15: ifFalse t3 goto L17
#L16: b = 35
#L17: t4 = a + b
#L18: a = t4
#L19: "%d\n" = param (null)
#L20: a = param (null)
#L21: (null) = "printf" call 2
#L22: t5 = 4 * 1
#L23: x[t9] = 6
#L24: t7 = 4 * 1
#L25: t6 = x[t7]
#L26: t8 = t6 == 6
#L27: if t8 goto L29
#L28: ifFalse t8 goto L33
#L29: t9 = 4 * 1
#L30: t10 = a - a
#L31: t11 = t10 + 20
#L32: x[t9] = t11
#L33: t13 = 4 * 1
#L34: t12 = x[t13]
#L35: "%d\n" = param (null)
#L36: t12 = param (null)
#L37: (null) = "printf" call 2
#L38: "%s\n" = param (null)
#L39: "Working The End" = param (null)
#L40: (null) = "printf" call 2
#L41: halt


.globl main
.text
main:
L0_1: push %rbp
L0_2: movq %rsp, %rbp
L0_3: subq $288, %rsp
L2_1: movq $5, %rax
L2_2: movq %rax, -80(%rbp)
L4_1: movq -96(%rbp), %rax
L4_2: cmp $0, %rax
L4_3: jne L6_1
L5_1: movq -96(%rbp), %rax
L5_2: cmp $0, %rax
L5_3: je L7_1
L6_1: movq $9, %rax
L6_2: movq %rax, -16(%rbp)
L7_1: movq $2, %rax
L7_2: movq %rax, -16(%rbp)
L8_1: movq -80(%rbp), %rax
L8_2: movq -16(%rbp), %rbx
L8_3: addq %rbx, %rax
L8_4: movq %rax, -112(%rbp)
L9_1: movq -112(%rbp), %rax
L9_2: movq %rax, -64(%rbp)
L10_1: movq $format1, %rdi
L11_2: movq -64(%rbp), %rsi
L12_1: call printf
L14_1: movq -128(%rbp), %rax
L14_2: cmp $0, %rax
L14_3: jne L16_1
L15_1: movq -128(%rbp), %rax
L15_2: cmp $0, %rax
L15_3: je L17_1
L16_1: movq $35, %rax
L16_2: movq %rax, -80(%rbp)
L17_1: movq -64(%rbp), %rax
L17_2: movq -80(%rbp), %rbx
L17_3: addq %rbx, %rax
L17_4: movq %rax, -144(%rbp)
L18_1: movq -144(%rbp), %rax
L18_2: movq %rax, -64(%rbp)
L19_1: movq $format2, %rdi
L20_2: movq -64(%rbp), %rsi
L21_1: call printf
L22_1: movq $4, %rax
L22_2: movq $1, %rbx
L22_3: mulq %rbx
L22_4: movq %rax, -160(%rbp)
L23_1: movq $6, %rax
L23_2: movq %rax, -32(%rbp)
L24_1: movq $4, %rax
L24_2: movq $1, %rbx
L24_3: mulq %rbx
L24_4: movq %rax, -192(%rbp)
L25_1: movq -32(%rbp), %rax
L25_2: movq %rax, -176(%rbp)
L27_1: movq -208(%rbp), %rax
L27_2: cmp $0, %rax
L27_3: jne L29_1
L28_1: movq -208(%rbp), %rax
L28_2: cmp $0, %rax
L28_3: je L33_1
L29_1: movq $4, %rax
L29_2: movq $1, %rbx
L29_3: mulq %rbx
L29_4: movq %rax, -224(%rbp)
L30_1: movq -64(%rbp), %rax
L30_2: movq -64(%rbp), %rbx
L30_3: sub %rbx, %rax
L30_4: mov %rax, -240(%rbp)
L31_1: movq -240(%rbp), %rax
L31_2: movq $20, %rbx
L31_3: addq %rbx, %rax
L31_4: movq %rax, -256(%rbp)
L32_1: movq -256(%rbp), %rax
L32_2: movq %rax, -32(%rbp)
L33_1: movq $4, %rax
L33_2: movq $1, %rbx
L33_3: mulq %rbx
L33_4: movq %rax, -288(%rbp)
L34_1: movq -32(%rbp), %rax
L34_2: movq %rax, -272(%rbp)
L35_1: movq $format3, %rdi
L36_2: movq -272(%rbp), %rsi
L37_1: call printf
L38_1: movq $format4, %rdi
L39_2: movq $format5, %rsi
L40_1: call printf
L41_1: addq $288, %rsp
L41_2: pop %rbp
L41_3: ret
format1: .asciz "%d\n"
format2: .asciz "%d\n"
format3: .asciz "%d\n"
format4: .asciz "%s\n"
format5: .asciz "Working The End"

