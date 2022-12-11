def A_Ex4(fileName):
    with open(fileName, encoding='UTF-8') as f:
        data = [l.split(',') for l in f.read().split('\n')[1:] if l]
    ids = {int(l[0]) for l in data}
    result = dict()
    for i in ids:
        n_exams = sum([1 for l in data if int(l[0]) == i and int(l[1]) >= 18])
        if n_exams:
            result[i] = n_exams
    return result