def Ex2(file, d):
    with open(file, encoding='UTF-8') as f:
        lines = f.read().splitlines()

    return {i + 1: [w for w in l.split() if set(w.lower()) == set(d.keys()) 
        and all(w.lower().count(c) >= n for c, n in d.items())] 
            for i, l in enumerate(lines)}