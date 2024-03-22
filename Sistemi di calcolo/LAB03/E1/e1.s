.globl min

min:
	movl 4(%esp), %eax
	cmpl 8(%esp), %eax
	jge L
	cmpl 12(%esp), %eax
	jge E
	ret

E:
	movl 12(%esp), %eax
	ret
L:
	movl 8(%esp), %eax
	cmpl 12(%esp), %eax
	jge I
	ret
I:
	movl 12(%esp), %eax
	ret
