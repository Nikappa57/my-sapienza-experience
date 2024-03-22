.globl fib

fib:
	movl $1, %eax
	xorl %ecx, %ecx
	movl 4(%esp), %edx

	testl %edx, %edx ; cmpl $0, %edx
	jne E

	xorl %eax, %eax
	ret

E:
	cmpl $1, %edx
	jne L
	ret

L:
	cmpl $1, %edx
	jle J
	addl %eax, %ecx
	addl %eax, %ecx
	subl %ecx, %eax
	negl %eax
	subl %eax, %ecx
	decl %edx
	jmp L

J:
	ret
