.globl check_quiz


check_quiz:		# int* check_quiz(char** answers, char* solution, int n) {
	pushl %ebx
	pushl %edi
	pushl %esi
	pushl %ebp
	subl $4, %esp

	# + 20

	movl 24(%esp), %edx		# 	char	**edx = answers;
	movl 26(%esp), %ebx		# 	char	*ebx = solution;
	movl 30(%esp), %edi		# int		edi = n;

	xorl %eax, %eax
	cmpl $0, %edx		# 	if (edx == NULL) return NULL;
	jz E1
	cmpl $0, %ebx		# if (ebx == NULL) return NULL;
	jz E1
	cmpl $0, %edi					# if (edi <= 0) return NULL;
	jle E1

	movl %edi, %eax		# int	_eax = edi;
	imull $4, %eax		# _eax = _eax * 4;
	
	movl %eax, (%esp)
	call malloc		# int	*eax = malloc(_eax);
	xorl %esi, %esi 		# 	esi = 0;
L1:	cmpl %edi, %esi		# L1: if (esi >= edi) goto E1;
	jge E1
	movl $0, (%eax, %esi, 4) # 	eax[esi] = 0;
	xorl %ebp, %ebp		# 	ebp = 0;

L2:	cmpl $4, %ebp			# L2: if (ebp >= 4) goto E2;
	jge E2

	movl (%edx, %esi, 4), %ecx		# char	*ecx = edx[esi]; // attenzione: e' un puntatore!
	movb (%ecx, %ebp, 1), %ch		# char	ch = ecx[ebp]
	cmpb (%ebx, %ebp), %ch		# if (ch == ebx[ebp]) // attenzione: confronto di caratteri!
	jne S
	incl (%eax, %esi, 4)		# 	eax[esi] += 1;
S:	incl %ebp		# ebp++;
	jmp L2		# goto L2;
E2:	
	incl %esi		# 	esi++;
	jmp L1		# 	goto L1;
E1:	
	addl $4, %esp
	popl %ebp
	popl %esi
	popl %edi
	popl %ebx
	ret
