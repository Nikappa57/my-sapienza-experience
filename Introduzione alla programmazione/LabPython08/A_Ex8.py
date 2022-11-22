def A_Ex8(l):
    return {n for i in l for n in i
            if sum(1 for i in l if n in i) == 1}
