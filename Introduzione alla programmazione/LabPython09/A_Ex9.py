def A_Ex9(fileName,squadra):
    with open(fileName, encoding="UTF-8") as f:
        data = [(i[0], i[1], int(i[2]), int(i[3])) for i in 
            [e.split(',') for e in f.read().split('\n')[1:] if e]]

    return sum(
        [3 if e[2] > e[3] else 1 if e[2] == e[3] else 0 for e in data if e[0] == squadra] +
        [3 if e[3] > e[2] else 1 if e[2] == e[3] else 0 for e in data if e[1] == squadra]
    )

