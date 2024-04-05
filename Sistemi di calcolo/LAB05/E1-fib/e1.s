.globl fib

fib:					# int fib(int n)
	pushl %esi
	pushl %edi
	subl $4, %esp
	movl 16(%esp), %esi	# 	int esi = n;
	cmpl $2, %esi		# 	if (esi < 2)
	jl E1				# 		goto E1;
	decl %esi			# 	esi--;
	movl %esi, (%esp)
	call fib
	movl %eax, %edi		# 	int edi = fib(esi);
	decl (%esp)			# 	esi--;
	call fib			# 	eax = fib(esi);
	addl %edi, %eax		# 	eax += edi;
	jmp E2				# 	goto E2;
E1:
	movl $1, %eax		# 	eax = 1;
E2:
	addl $4, %esp
	popl %edi
	popl %esi
	ret					# 	return eax;
