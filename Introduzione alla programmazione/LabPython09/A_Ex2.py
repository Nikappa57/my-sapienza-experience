def A_Ex2(fileName):
    with open(fileName, encoding="UTF-8") as f:
        data = [l.strip().split(',') for l in f.read().split('\n')[1:] if l]
    return [(result[0], result[2]) for result in data if int(result[1]) >= 18]
