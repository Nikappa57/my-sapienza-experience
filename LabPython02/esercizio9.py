m = int(input("mese: "))
a = int(input("anno: "))

if m > 12 or m < 1:
    print("input non valido")
else:
    if m != 12:
        m += 1
    else:
        m = 1
        a += 1
    print(m, a)