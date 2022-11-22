somma_n_3 = 0

n = 1
while n != 0:
    n = int(input("numero: "))
    if not n % 3:
        somma_n_3 += n
print(somma_n_3)