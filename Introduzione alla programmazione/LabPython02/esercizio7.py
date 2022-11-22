n1 = int(input("numero 1: "))
n2 = int(input("numero 2: "))
n3 = int(input("numero 3: "))

ns = [n1, n2, n3]
ns.sort(reverse=True)
print("\n".join(str(i) for i in ns))