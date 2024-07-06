.globl strings_are_upper

strings_are_upper:
	pushl %ebx
	pushl %edi
	pushl %esi
	pushl %ebp
	subl $4, %esp
	// + 20

	xorl %ebp, %ebp		
	movl 24(%esp), %esi	# const char** esi = array;

	cmpl $0, %esi		# if (esi == NULL) return NULL;
	je E1

	cmpl $0, 28(%esp)	# if (n <= 0) return NULL;
	jle E1

	movl 28(%esp), %ebp
	imull $4, %ebp
	movl %ebp, (%esp)
	call malloc			# int* ebp = malloc(sizeof(int) * n);
	movl %eax, %ebp

	xorl %ebx, %ebx		# int ebx = 0;

L1:	cmpl 28(%esp), %ebx	# if (ebx >= n) 
	jge E1

	movl (%esi, %ebx, 4), %edi	# const char* edi = esi[ebx];

	movl $1, (%ebp, %ebx, 4)	# ebp[ebx] = 1;

L2:	cmpb $0, (%edi)		# if (*edi == 0)
	je E2

	movsbl (%edi), %eax	# char eax = *edi;
	movl %eax, (%esp)
	call isupper		# int eax = isupper(eax);

	cmpl $0, %eax		# if (eax != 0) 
	jne S

	movl $0, (%ebp, %ebx, 4)		# ebp[ebx] = 0;
	jmp E2

S:	incl %edi			# edi += 1;
	jmp L2

E2:
	incl %ebx			# ebx++;
	jmp L1

E1:
	movl %ebp, %eax
	addl $4, %esp
	popl %ebp
	popl %esi
	popl %edi
	popl %ebx
	ret
