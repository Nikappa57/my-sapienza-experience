.globl count_digits

count_digits:
	xorl %eax, %eax
	movl 4(%esp), %ecx

L:	movb (%ecx), %dl
	testb %dl, %dl
	je E
	cmpb $48, %dl
	jl P
	cmpb $57, %dl
	jg P
	incl %eax

P:	incl %ecx
	jmp L

E:	ret

