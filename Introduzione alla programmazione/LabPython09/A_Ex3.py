def A_Ex3(fileName):
    with open(fileName, encoding="UTF-8") as f:
        data = [l.strip().split(',') for l in f.read().split('\n')[1:] if l]
    return {l[2] for l in data if 
        any([l[2] == ls[2] and int(l[1]) >= 29 and int(ls[1]) >= 29 and l[0] != ls[0] 
            for ls in data])}
