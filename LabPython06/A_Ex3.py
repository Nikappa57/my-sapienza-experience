for i in range(8):
    for j in range(8):
        if i != 0 and j != 0:
            print(oct(i * j)[2:], end="\t")
    print()
