def A_Ex3(fileName):
    with open(fileName, encoding='UTF-8') as f:
        data = [l.split(',') for l in f.read().split('\n')[1:] if l]
    subjects = {e[2] for e in data}
    result = dict()
    for s in subjects:
        l = sorted([int(l[0]) for l in data if l[2] == s and int(l[1]) >= 18])
        if l:
            result[s] = l
    return result