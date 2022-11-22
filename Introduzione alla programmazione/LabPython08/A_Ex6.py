def A_Ex6(l,c,n):
    return list(filter(lambda s: s.count(c) < n, l))
