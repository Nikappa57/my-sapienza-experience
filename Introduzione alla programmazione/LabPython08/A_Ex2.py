def A_Ex2(l):
    return {c for c in set("".join(l)) 
               if any(s.count(c) > 1 for s in l)}