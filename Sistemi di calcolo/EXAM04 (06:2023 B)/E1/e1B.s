.globl rc4_encrypt_rev

rc4_encrypt_rev:
	pushl %esi
	pushl %ebx
	pushl %edi
	pushl %ebp
	subl $12, %esp

	# + 28

	xorl %esi, %esi
	xorb %bh, %bh
	movl 40(%esp), %edi # unsigned char *edi = ct;
	movl 36(%esp), %ebp # unsigned char *ebp = pt;
	movl %ebp, (%esp)
	call strlen			# int eax = strlen(ebp);
	decl %eax			# eax--;
	addl %eax, %ebp		# ebp += eax;

L:	cmpl 36(%esp), %ebp	# if (ebp < pt) goto E;
	jl E

	incl %esi			# esi++;
	andl $255, %esi		# esi = esi & 255;
	movl 32(%esp), %eax	# unsigned char *_eax = sbox;
	addb (%eax, %esi), %bh	# bh += _eax[esi];
	
	movl %eax, (%esp)
	movl %esi, 4(%esp)
	movb %bh, 8(%esp)
	call rc4_helper		# unsigned char al = rc4_helper(_eax, esi, bh);

	xorb (%ebp), %al	# al = al ^ *ebp;
	movb %al, (%edi)	# *edi = al;
	decl %ebp			#  *ebp--;
	incl %edi			# edi++;
	jmp L				# goto L;

E:	
	addl $12, %esp
	popl %ebp
	popl %edi
	popl %ebx
	popl %esi
	ret
