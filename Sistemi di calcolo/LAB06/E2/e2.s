.globl list_equal
list_equal:					# int list_equal(const node_t *l1, const node_t *l2)
	movl 4(%esp), %ecx		# 	const node_t *ecx = l1;
	movl 8(%esp), %edx		# 	const node_t *edx = l2;

L:	testl %ecx, %ecx		#	if (ecx == NULL)
	jz E					# 		goto E;
	testl %edx, %edx		# 	if (edx == NULL)
	jz E					# 		goto E;
	movw (%ecx), %ax	 	#	ax = ecx->elem
	cmpw %ax, (%edx)		# 	if (eax != edx->elem)
	jne E1					# 		goto D;
	movl 4(%ecx), %ecx		# 	ecx = ecx->next;
	movl 4(%edx), %edx		# 	edx = edx->next;
	jmp L					# 	goto L;
E:	
	testl %ecx, %ecx
	setz %al				# 	al = ecx == NULL;
	testl %edx, %edx
	setz %ah				# 	ah = edx == NULL;
	andb %ah, %al			# 	eax = eax && ebx;
	movzbl %al, %eax
	ret						# 	return eax;
E1:	
	xorl %eax, %eax			# 	eax = 0;
	ret						# 	return eax;
