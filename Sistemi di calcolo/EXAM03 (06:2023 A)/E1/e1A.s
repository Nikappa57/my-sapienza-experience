.globl rc4_encrypt

rc4_encrypt:
	pushl %ebx
	pushl %esi
	pushl %edi
	pushl %ebp
	subl $20, %esp

	# + 36

	# unsigned int ebx = 0, esi = 0;
    # unsigned char dh = 0, rnd, al;

	xorl %esi, %esi
	xorb %bh, %bh

	movl 48(%esp), %edi		# unsigned char *edi = ct;
	movl 44(%esp), %ebp		# unsigned char *ebp = pt;

L:	cmpb $0, (%ebp)		# if (*ebp == 0) goto E;
	je E

	incl %esi		# esi++;
	andl $255, %esi		# esi = esi & 255;
	movl 40(%esp), %eax		# unsigned char *eax = sbox;
	addb (%eax, %esi, 1), %bh		# dh = dh + eax[esi];
	
	movl %eax, (%esp)
	movl %esi, 4(%esp)
	movb %bh, 8(%esp)
	leal 16(%esp), %eax
	movl %eax, 12(%esp)
	call rc4_helper		# rc4_helper(sbox, esi, dh, &rnd);
	
	movb 16(%esp), %al		# al = rnd;
	xorb (%ebp), %al		# al = al ^ *ebp;
	incl %ebp		# ebp++;
	movb %al, (%edi)		# *edi = al;          // ^ e' l'operatore xor
	incl %edi		# edi++;
	jmp L		# goto L;
E:

	addl $20, %esp
	popl %ebp
	popl %edi
	popl %esi
	popl %ebx

	ret
