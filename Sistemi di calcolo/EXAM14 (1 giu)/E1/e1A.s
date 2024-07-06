.globl init_matrix

init_matrix:
	pushl %esi
	pushl %edi
	pushl %ebx
	pushl %ebp
	subl $8, %esp

	// +24

	xorl %esi, %esi
	movl 28(%esp), %ebx
	movl 32(%esp), %ebp

L1:	cmpl %ebp, %esi
	jae E1
	
	xorl %edi, %edi

L2:	cmpl %ebp, %edi
	jae E2

	movl %esi, (%esp)
	movl %edi, 4(%esp)
	call value

	movl (%ebx, %esi, 4), %ecx
	movw %ax, (%ecx, %edi, 2)

	incl %edi
	jmp L2

E2:
	incl %esi
	jmp L1

E1:
	addl $8, %esp
	popl %ebp
	popl %ebx
	popl %edi
	popl %esi
	ret
