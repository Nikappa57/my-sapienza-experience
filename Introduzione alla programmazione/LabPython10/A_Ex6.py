def A_Ex6(fileName):
    with open(fileName, encoding='UTF-8') as f:
        file = f.read()
    data = [list(map(int, l.split(','))) for l in file.split('\n') if l]
    dict_keys = set().union(*data)
    return {k: {i + 1 for i, l in enumerate(data) if k in l} for k in dict_keys}
