def Ex2(m):
    if len(m) == 1:
        return m[0][0]
    sums = list()
    for y in range(len(m) - 1):
        for x in range(len(m) - 1):
            sums.append(m[x][y] + m[x+1][y] + m[x][y+1] + m[x+1][y+1])
    return max(sums, default=0)