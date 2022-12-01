def A_Ex8(fileName):
    with open(fileName, encoding="UTF-8") as f:
        lines = f.read().split('\n')
    return max(range(1, len(lines) + 1), key=lambda i: (sum(c.isupper() for c in lines[i - 1]), i))

