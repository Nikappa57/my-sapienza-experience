def A_Ex8(file):
    with open(file, encoding='UTF-8') as f:
        data = [l.split(',') for l in f.read().split('\n')[1:] if l]
    names = list(set().union(*[l[:2] for l in data]))

    result = {name: list() for name in names}
    for p1, p2, info in data:
        if info == 'amici':
            if p2 not in result[p1]:
                result[p1].append(p2)
            if p1 not in result[p2]:
                result[p2].append(p1)
        else:
            if p2 in result[p1]:
                result[p1].remove(p2)
            if p1 in result[p2]:
                result[p2].remove(p1)

    result = dict(map(lambda item: (item[0], sorted(item[1])), result.items()))
    return result
