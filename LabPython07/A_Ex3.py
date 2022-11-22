def A_Ex3(l,n):
    assert n >= 0
    return "".join(map(lambda s: s[n] if n <= len(s) - 1 else "!", l))