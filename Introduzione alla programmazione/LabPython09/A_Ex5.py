def A_Ex5(filename,oggetto):
    with open(filename, encoding="UTF-8") as f:
        lines = f.read().split('\n')
    data = [l.strip().split(',') for l in lines[1:] if l]
    years = [int(l) for l in lines[0].strip().split(',')[1:] if l]
    sales = list(map(int, [e[1:] for e in data if e[0] == oggetto][0]))
    increments = [sales[i + 1] - sales[i] for i in range(len(sales) - 1)]
    if max(increments) < 1:
        return years[0]
    return max(years, key=lambda e: (increments[years.index(e) - 1], e))

