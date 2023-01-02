def Ex1(s):
    return max((j - i for i in range(len(s)) for j in range(len(s), i, -1) 
        if all(c1 <= c2 for c1, c2 in zip(s[i:j], s[i + 1:j]))), default=0)