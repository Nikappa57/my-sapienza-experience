import re

def Ex2(file):
    with open(file, encoding='UTF-8') as f:
        string = f.read()
    nums = {int(n) for n in re.findall(r'\b\d+\b', string)}

    result = dict()
    for n in nums:
        lines_index = sorted([i + 1 for i, l in enumerate(string.splitlines()) 
            if re.search(rf'\b0*{n}\b', l)], reverse=True)
        if lines_index:
            result[int(n)] = lines_index
    return result