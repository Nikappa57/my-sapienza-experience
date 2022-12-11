def A_Ex5(s,n):
    dict_keys = {w[0] for w in s.split() if w}
    result = dict()
    for k in dict_keys:
        n_words = sum([1 for l in s.split() if l and l[0] == k and len(l) >= n])
        if n_words:
            result[k] = n_words
    return result