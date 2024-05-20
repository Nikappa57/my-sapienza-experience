.globl crc32b

crc32b:
	pushl %ebx
	pushl %edi
	pushl %esi
	subl $12, %esp

	xorl %ebx, %ebx	# int ebx = 0;
	notl %ebx		# ebx = ~ebx;
	movl %ebx, %edi	# int edi = ebx;
	movl 32(%esp), %esi

L:	cmpl $0, %esi	# if (esi == 0)
	je E			# goto E;

	decl %esi			# esi--;
	movl 28(%esp), %eax	# char *eax_ = bytes;
	movl (%eax), %eax	# int eax = *eax_;
	incl 28(%esp)		# bytes++;
	movl %edi, %edx		# int edx = edi;
	xorl %eax, %edx		# edx = edx ^ eax;
	andl $0xFF, %edx	# edx = edx & 0xFF;
	leal 8(%esp), %eax	# int value;
	movl %eax, (%esp)
	movl %edx, 4(%esp)
	call get_constant	# get_constant(&value, edx);
	movl %edi, %eax		# eax = edi;
	sarl $8, %eax		# eax = eax >> 8;
	movl 8(%esp), %edi	# edi = value ^ eax;
	xorl %eax, %edi
	jmp L			# goto L;

E:	movl %edi, %eax
	xorl %ebx, %eax

	addl $12, %esp
	popl %esi
	popl %edi
	popl %ebx

	ret

