def A_Ex1(l):
    return max({i for i in "".join(l) if i.islower()},
            key=lambda c: (sum([1 for s in l if c in s]), ord(c)))
