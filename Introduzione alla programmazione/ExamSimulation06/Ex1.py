def Ex1(l1,l2,n):
    return sum([1 for w1 in l1 for w2 in l2 if 
        any(w2[i:i+n] in w1 for i in range(0, len(w2) - n))])