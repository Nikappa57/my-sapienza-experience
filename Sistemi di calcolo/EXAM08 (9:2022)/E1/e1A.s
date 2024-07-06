.globl div_vectors

div_vectors:
	pushl %ebx
	pushl %edi
	pushl %esi
	pushl %ebp
	subl $4, %esp
	
	// +20

	xorl %ebp, %ebp

	movl 24(%esp), %edi # a
	movl 28(%esp), %esi	# b

	testl %edi, %edi
	jz E
	testl %esi, %esi
	jz E
	cmpl $0, 32(%esp)
	jz E				# if (a == NULL || b == NULL || n == 0)

	movl 32(%esp), %eax		#	    int _eax = n;
    imull $4, %eax		#	_eax *= 4;
    movl %eax, (%esp)
	call malloc		#	ecx = malloc(_eax);
	movl %eax, %ebp
	xorl %ebx, %ebx		#	int ebx = 0;

L:  cmpl 32(%esp), %ebx		#	 if (ebx >= n) goto E;
	jge E
			
	movl (%edi, %ebx, 4), %eax	#	unsigned int __eax = a[ebx];

    xorl %edx, %edx		#	unsigned int __edx = 0;

	movl (%esi, %ebx, 4), %ecx
    idivl %ecx		#	__eax = __eax / b[ebx];
    movl %eax, (%ebp, %ebx, 4)		#	ecx[ebx] = __eax;  // usare idiv, attenzione a edx! edx : eax / S

    incl %ebx		#	ebx++;
    jmp L		#	goto L;

E:
	movl %ebp, %eax
	addl $4, %esp
	popl %ebp
	popl %esi
	popl %edi
	popl %ebx
	ret
