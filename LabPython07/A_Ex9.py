def A_Ex9(l):
    result = list()
    for s in l:
        s = sorted(s)
        max_c = s[0]
        for c in s:
            if s.count(c) > s.count(max_c):
                max_c = c
        result.append(max_c)
    return result
