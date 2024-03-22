# scrivere la soluzione qui...

.globl find

find:
	xorl %eax, %eax
	movl 4(%esp), %ecx
	movl 12(%esp), %edx

L:	cmpl 8(%esp), %eax
	jge E0
	cmpl %edx, (%ecx, %eax, 4)
	je E1
	incl %eax
	jmp L

E0:	xorl %eax, %eax
	ret

E1:	movl $1, %eax
	ret
