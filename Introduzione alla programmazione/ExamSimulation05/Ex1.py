def Ex1(n):
    max_c = 1
    c = 1
    for i in range(1, len(str(n))):
        if int(str(n)[i - 1]) % 2 != int(str(n)[i]) % 2:
            c += 1
            if c > max_c:
                max_c = c
        else:
            c = 1
    return max_c