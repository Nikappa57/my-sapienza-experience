.globl count_matching_vars

count_matching_vars:
	pushl %ebx
	pushl %esi
	pushl %edi
	subl $8, %esp

	// + 20

	movl $-1, %ebx
	movl 24(%esp), %esi
	movl 28(%esp), %edi

	testl %esi, %esi
	jz E
	testl %edi, %edi
	jz E

	xorl %ebx, %ebx

L:	cmpl $0, (%esi)
	jz E

	movl (%esi), %eax
	movl %eax, (%esp)
	call getenv

	testl %eax, %eax
	jz S

	movl %eax, (%esp)
	movl %edi, 4(%esp)
	call strstr

	testl %eax, %eax
	jz S

	incl %ebx

S:	addl $4, %esi

	jmp L

E:
	movl %ebx, %eax
	addl $8, %esp
	popl %edi
	popl %esi
	popl %ebx
	ret
	