def Ex1(l,x,y):
    start = None
    result = list()
    for i, e in enumerate(l):
        if e == x and start == None:
            start = i
        if e == y and start != None:
            result.extend(l[start + 1:i])
            start = None
    return result