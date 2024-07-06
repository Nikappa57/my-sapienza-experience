is_suffix:
        movl 4(%esp), %eax
        movl 8(%esp), %ecx

L1:     cmpb $0, (%eax)
        je L2
        incl %eax
        jmp L1

L2:     cmpb $0, (%ecx)
        je L3
        incl %ecx
        jmp L2

L3:     cmpl %eax, 4(%esp)
        je E
        cmpl %ecx, 8(%esp)
        je E
        decl %eax
        decl %ecx
        movb (%eax), %dl
        cmpb (%ecx), %dl
        jne E
        jmp L3

E:      cmpl %eax, 4(%esp)
        sete %dl
        movb (%eax), %al
        cmpb (%ecx), %al
        sete %al
        andb %dl, %al
        movzbl %al, %eax
        ret