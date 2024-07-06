.globl count_vars

count_vars:
	pushl %ebx
	pushl %edi
	pushl %esi
	subl $4, %esp

	// + 16

	xorl %ebx, %ebx

	movl 20(%esp), %edi
	
	testl %edi, %edi
	jz E

	movl 24(%esp), %eax

	cmpl $0, %eax
	jle E

	imull $4, %eax
	movl %eax, (%esp)
	call malloc
	movl %eax, %ebx
	xorl %esi, %esi

L:	cmpl 24(%esp), %esi
	jge E

	movl (%edi, %esi, 4), %eax
	movl %eax, (%esp)
	call getenv

	testl %eax, %eax
	setnz %al
	movsbl %al, %eax
	movl %eax, (%ebx, %esi, 4)

	incl %esi
	jmp L

E:
	movl %ebx, %eax

	addl $4, %esp
	popl %esi
	popl %edi
	popl %ebx

	ret
