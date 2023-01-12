def Ex1(l):
    max_c = 1
    c = 1
    if not l:
        return 0

    for i in range(1, len(l)):
        if l[i - 1] < l[i]:
            c += 1
        elif c > max_c:
            max_c = c
            c = 1
        else:
            c = 1

    return max_c