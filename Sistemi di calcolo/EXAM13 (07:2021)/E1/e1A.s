.globl suffix

suffix:
	pushl %ebx
	pushl %edi
	pushl %esi
	subl $4, %esp

	// + 16

	movl 20(%esp), %esi
	movl 24(%esp), %ebx

	movl %esi, (%esp)
	call strlen
	movl %eax, %edi

	movl %ebx, (%esp)
	call strlen

	cmpl %edi, %eax
	jg E0

	movl %edi, %ecx
	subl %eax, %ecx

L:	cmpl %edi, %ecx
	jge E

	movb (%ebx), %dh
	incl %ebx

	cmpb %dh, (%esi, %ecx)
	jne E0

	incl %ecx
	jmp L

E:
	movl $1, %eax
	jmp P
E0:
	xorl %eax, %eax

P:	addl $4, %esp
	popl %esi
	popl %edi
	popl %ebx
	ret