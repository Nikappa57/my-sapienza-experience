.globl lcm

lcm:					# int lcm(int x, int y) {
	pushl %ebx
	pushl %edi
	movl 12(%esp), %ebx	# int ebx = x;
	movl 16(%esp), %edi # int edi = y;
	movl %edi, %ecx		# int ecx = edi;

	cmpl %ecx, %ebx		#     if (ebx > ecx)
	cmovgl %ebx, %ecx	#         ecx = ebx;
L:
	movl %ecx, %eax		# 	eax = ecx;
	xorl %edx, %edx			# int edx = 0;
	idivl %ebx
	testl %edx, %edx	#     if (eax % ebx != 0)
	jne E				# 		goto E;
	movl %ecx, %eax		# 	eax = ecx;
	xorl %edx, %edx			# int edx = 0;
	idivl %edi
	testl %edx, %edx	# 	if (eax % edi != 0)
	jne E				# 		goto E;

	popl %edi
	popl %ebx
	movl %ecx, %eax
	ret				#     return ecx;

E:	incl %ecx			# ecx++;
	jmp L 				# 	goto L;
