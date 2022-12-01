def A_Ex4(filename,anno):
    with open(filename, encoding="UTF-8") as f:
        lines = f.read().split('\n')
    years = list(map(int, lines[0].strip().split(',')[1:]))
    y_index = years.index(anno)
    values = {e[0]:e[y_index + 1] for e in [l.split(',') for l in lines[1:]]}
    return max(values, key=lambda v: (values.get(v), v))
