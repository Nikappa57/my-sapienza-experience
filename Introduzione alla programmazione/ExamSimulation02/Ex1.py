def Ex1(l):
    max_c = 0
    c = 1

    for i in range(1, len(l)):
        if l[i - 1] < l[i]:
            c += 1
            if c > max_c:
                max_c = c
                c = 1
        else:
            c = 1

    return max_c