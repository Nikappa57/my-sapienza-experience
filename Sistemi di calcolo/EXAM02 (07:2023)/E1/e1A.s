.globl adler32

adler32:
	pushl %ebx
	pushl %ebp
	pushl %esi
	subl $8, %esp

	xorl %eax, %eax 	# unsigned eax = 0

	cmpl $0, 24(%esp)	# if (data == NULL)
	je F				# goto F;

	cmpl $0, 28(%esp)	# if (len == 0)
	je F				# goto F;

	leal 4(%esp), %edx
	movl %edx, (%esp)
	call get_adler_constant	# get_adler_constant(&k);

	movl $1, %ebp		# ebp = 1
	xorl %ebx, %ebx		# ebx = 0
	xorl %esi, %esi		# esi = 0
	movl 4(%esp), %ecx	#  ecx = k

L:	cmpl 28(%esp), %esi	# if (esi >= len)
	jae E				# goto E;

	xorl %edx, %edx				# edx = 0;
	movl 24(%esp), %eax			# eax = data
	movzbl (%eax, %esi, 1), %eax	# eax = eax[esi];
	addl %ebp, %eax
	divl %ecx
	movl %edx, %ebp

	xorl %edx, %edx
	movl %ebx, %eax
	addl %ebp, %eax
	divl %ecx
	movl %edx, %ebx

	incl %esi
	jmp L
E:
	movl %ebx, %eax
	shll $16, %eax
	orl %ebp, %eax

F:	addl $8, %esp
	popl %esi
	popl %ebp
	popl %ebx

	ret
