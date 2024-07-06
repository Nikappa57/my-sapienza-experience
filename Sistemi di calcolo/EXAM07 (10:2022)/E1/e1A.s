.globl str_to_upper

str_to_upper:
	pushl %esi
	pushl %edi
	subl $4, %esp

	// +12

	xorl %esi, %esi

	movl 16(%esp), %eax
	testl %eax, %eax
	jz E

	movl %eax, (%esp)
	call strdup
	movl %eax, %esi

	movl %esi, %edi
L:	cmpb $0, (%edi)
	jz E

	movsbl (%edi), %eax
	movl %eax, (%esp)
	call toupper
	movb %al, (%edi)
	incl %edi

	jmp L

E:
	movl %esi, %eax
	addl $4, %esp
	popl %edi
	popl %esi
	ret
