def A_Ex7(l):
    extend = [l[i + 1] - l[i] for i in range(len(l) - 1) if l[i] < l[i + 1]]
    if not l:
        return []
    if len(extend) == 1 and l[-1] < extend[0]:
        return l + extend + [extend[0] - l[-1]]
    print(extend)
    return l + A_Ex7(extend)
