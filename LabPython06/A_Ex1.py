n1 = int(input("numero 1: "))
n2 = int(input("numero 2: "))

for i in reversed(range(1, n1 + 1)):
    if (n1 % i == 0) and (n2 % i > 0):
        print(i)
