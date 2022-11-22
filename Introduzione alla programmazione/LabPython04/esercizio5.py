def fatt(n):
    if n < 2:
        return 1
    return n * fatt(n - 1)

print(fatt(int(input("numero: "))))