def A_Ex2(start,n):
    if not start % 2:
        start += 1

    return [start + i * 2 for i in range(n)]
