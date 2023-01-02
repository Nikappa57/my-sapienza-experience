def Ex2(file,s):
    with open(file, encoding='UTF-8') as f:
        lines = f.read().splitlines()

    return {i + 1: [w for w in line.split(' ') 
        if sorted(w.lower()) == sorted(s.lower())] 
            for i, line in enumerate(lines)}