.globl interleave

interleave:		#	void interleave(const char* a, const char* b, char* c) {
	pushl %ebx
	// +4
	movl 8(%esp), %eax		#	    const char *eax = a;
	movl 12(%esp), %ebx		#	    const char *ebx = b;
	movl 16(%esp), %ecx		#	    char *ecx = c;
L:
	cmpb $0, (%eax)		#	    if (*eax == '\0')
	jz S1		#	        goto S1;
	movb (%eax), %dl		#	    char dl = *eax;
	movb %dl, (%ecx)		#	    *ecx = dl;
	incl %ecx		#	    ecx++;
	incl %eax		#	    eax++;

S1:
	cmpb $0, (%ebx)		#	    if (*ebx == '\0')
	jz S2		#	        goto S2;
	movb (%ebx), %dl		#	    dl = *ebx;
	movb %dl, (%ecx)		#	    *ecx = dl;
	incl %ecx		#	    ecx++;
	incl %ebx		#	    ebx++;

S2:
	cmpb $0, (%eax)		#	    if (*eax != '\0')
	jnz L		#	        goto L;
	cmpb $0, (%ebx)		#	    if (*ebx != '\0')
	jnz L		#	        goto L;
	movb $0, (%ecx)		#	    *ecx = '\0';

	popl %ebx
	ret
