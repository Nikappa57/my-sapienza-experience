.globl list_add_first

list_add_first:				# int list_add_first(node_t **arg1, short arg2) 
	pushl %edi
	pushl %ebx
	subl $4, %esp 			# +12

	movl 16(%esp), %edi		# 	node_t **edi = arg1;
	movl (%edi), %ebx		# 	node_t *ebx = *edi;
	movl $8, (%esp)
	call malloc 			# 	node_t *eax = malloc(sizeof(node_t));
	testl %eax, %eax		# 	if (eax == NULL)
	jz A					# 		return -1;
	movw 20(%esp), %cx		#	cx = arg2;
	movw %cx, (%eax)		# 	eax->elem = cx;
	movl %ebx, 4(%eax)		# 	eax->next = ebx;
	movl %eax, (%edi)		# 	*edi = eax;

	addl $4, %esp
	popl %ebx
	popl %edi
	xorl %eax, %eax
	ret						# 	return 0;

A:
	movl $-1, %eax
	ret
