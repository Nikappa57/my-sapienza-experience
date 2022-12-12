def A_Ex2(file):
    with open(file, encoding="UTF-8") as f:
        file = f.read()
    lines = [s.split(' ') for s in file.split('\n') if s]
    words = file.split()

    return {w: {i + 1 for i, l in enumerate(lines) if w in l} for w in set(words)}
