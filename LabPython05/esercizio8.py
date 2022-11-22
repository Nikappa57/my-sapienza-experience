base = int(input("numero: "))

space = (base - 1)//2
while space >= 0:
    print(" " * space + "*" * (base - space * 2))
    space -= 1