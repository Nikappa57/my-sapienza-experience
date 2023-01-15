def Ex1(s):
    max_c = 1
    c = 1

    for i in range(1, len(s)):
        if s[i - 1] <= s[i]:
            c += 1
            if c > max_c:
                max_c = c
        else:
            c = 1

    return max_c