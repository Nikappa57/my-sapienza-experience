.globl crc32b

crc32b:
	pushl %ebx
	pushl %esi
	pushl %edi
	subl $12, %esp

	// +24

	xorl %ebx, %ebx
	notl %ebx

	movl 28(%esp), %edi
	movl 32(%esp), %esi

L:	testl %esi, %esi
	jz E

	decl %esi
	movsbl (%edi), %eax
	incl %edi
	xorl %ebx, %eax
	andl $0xFF, %eax
	movl %eax, 4(%esp)
	leal 8(%esp), %eax
	movl %eax, (%esp)
	call get_constant

	movl 8(%esp), %ecx
	sarl $8, %ebx
	xorl %ecx, %ebx
	jmp L

E:
	xorl %eax, %eax
	notl %eax
	xorl %ebx, %eax

	addl $12, %esp
	popl %edi
	popl %esi
	popl %ebx

	ret
