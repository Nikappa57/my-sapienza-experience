def Ex2(file,ins):
    with open(file, encoding='UTF-8') as f:
        lines = f.read().splitlines()

    result = dict()
    for w in ins:
        lines_index = [i + 1 for i, l in enumerate(lines) if w in l.split()]
        if lines_index:
            result[w] = sorted(lines_index, reverse=True)
    return result