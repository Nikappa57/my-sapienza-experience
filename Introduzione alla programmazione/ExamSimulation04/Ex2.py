def Ex2(file,s):
    with open(file, encoding='UTF-8') as f:
        lines = f.read().splitlines()
    return {i + 1: [w for w in l.split() if sorted(w.lower()) == sorted(s)] 
        for i, l in enumerate(lines)}