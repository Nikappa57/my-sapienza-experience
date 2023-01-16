def Ex2(file,s):
    with open(file, encoding='UTF-8') as f:
        lines = f.read().splitlines()

    result = 0
    for l in lines:
        if s in l or s in l[::-1]:
            result += 1
    for i in range(len(lines[0])):
        line = "".join(l[i] for l in lines)
        if s in line or s in line[::-1]:
            result += 1
    return result