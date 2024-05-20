.globl binsearch

binsearch:
	pushl %ebx
	pushl %edi

	movl 12(%esp), %ebx
	movl 20(%esp), %edi
	xorl %eax, %eax
	movl 16(%esp), %ecx

L:	cmpl %ecx, %eax
	jge E0
	movl %eax, %edx
	addl %ecx, %edx
	shrl $1, %edx
	movl (%ebx, %edx, 4), %eax
	cmpl %edi, %eax
	je E1
	jg F
	movl %edx, %eax
	incl %eax
	jmp L

F:	movl %edx, %ecx
	jmp L

E1:	movl $1, %eax
	jmp E

E0:	xorl %eax, %eax
	jmp E

E:	popl %edi
	popl %ebx
	ret