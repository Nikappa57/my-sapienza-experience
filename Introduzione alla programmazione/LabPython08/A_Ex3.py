def A_Ex3(l):
    return {(s1, s2) for s1 in l for s2 in l if s1 != s2 and len(s1) == len(s2)}
