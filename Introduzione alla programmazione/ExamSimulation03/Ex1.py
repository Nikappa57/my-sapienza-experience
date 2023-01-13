def Ex1(l):
    max_c = 1
    c = 1

    if not l:
        return 0

    for i in range(1, len(l)):
        if len(l[i - 1]) > len(l[i]):
            c += 1
        else:
            if c > max_c:
                max_c = c
            c = 1
    if c > max_c:
        max_c = c

    return max_c