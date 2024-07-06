.globl init_matrix

init_matrix:
	pushl %esi
	pushl %edi
	subl $8, %esp
	xorl %esi, %esi

L1:	cmpl 24(%esp), %esi
	jae E1

	xorl %edi, %edi
L2:	cmpl 24(%esp), %edi
	jae E2

	movl %esi, (%esp)
	movl %edi, 4(%esp)
	call value
	movl 20(%esp), %ecx
	movl (%ecx, %esi, 4), %ecx
	movw %ax, (%ecx, %edi, 2)

	incl %edi
	jmp L2
E2:
	incl %esi
	jmp L1

E1:
	addl $8, %esp
	popl %edi
	popl %esi

	ret
