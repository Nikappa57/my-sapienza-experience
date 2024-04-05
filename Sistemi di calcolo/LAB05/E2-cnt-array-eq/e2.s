
.globl counteq
counteq:						# int counteq(short* v1, short* v2, int n) {
	pushl %esi
	pushl %edi
	pushl %ebx
	xorl %eax, %eax				# 	int eax = 0;		// cnt
	xorl %ecx, %ecx				# 	int ecx = 0;		// i
	movl 16(%esp), %esi			# 	short *esi = v1;
	movl 20(%esp), %edi			# 	short *edi = v2;
	movl 24(%esp), %edx			# 	int edx = n;
L:
	cmpl %edx, %ecx				# 	if (ecx >= edx)
	jge E						# 		goto E;
	movw (%esi, %ecx, 2), %bx	# 	short bx = esi[ecx];
	cmpw %bx, (%edi, %ecx, 2)
	sete %bl					# 	char bl = (bx == edi[ecx]);
	movzbl %bl, %ebx			# 	int ebx = (int)bl;
	addl %ebx, %eax				# 	eax += ebx;
	incl %ecx					# 	ecx++;
	jmp L						# 	goto L;
E:
	popl %ebx
	popl %edi
	popl %esi
	ret
