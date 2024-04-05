.globl clone

clone:						# void* clone(const void* src, int n) {
	pushl %edi
	pushl %ebx
	subl $12, %esp
	movl 28(%esp), %edi		#    int edi = n;
	movl %edi, (%esp)
	call malloc				#    void* eax = malloc(edi);
	testl %eax, %eax		#    if (eax==0)
	je E					#        return eax;
	movl %eax, %ebx			#    void* ebx = eax;
	movl 24(%esp), %eax		#    eax = (void*)src;
	movl %ebx, (%esp)
	movl %eax, 4(%esp)
	movl %edi, 8(%esp)
	call memcpy				#    memcpy(ebx, eax, edi);
	movl %ebx, %eax			#    eax = ebx;
E:
	addl $12, %esp
	popl %ebx
	popl %edi
	ret
