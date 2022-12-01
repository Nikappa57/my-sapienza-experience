def A_Ex6(filename):
    with open(filename, encoding="UTF-8") as f:
        lines = f.read().split('\n')
    years = [int(i) for i in lines[0].split(',')[1:] if i]
    sales = [list(map(int, i.split(',')[1:])) for i in lines[1:] if i]
    return max(years, key=lambda y: (sum(sale[years.index(y)] for sale in sales), y))

