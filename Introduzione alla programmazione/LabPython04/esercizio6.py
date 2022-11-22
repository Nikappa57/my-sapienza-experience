def moltiplicazione(n1, n2):
    if n2 == 0:
        return 0
    return n1 + moltiplicazione(n1, n2 - 1)
    
n1 = int(input("1 numero: "))
n2 = int(input("2 numero: "))

segno = "" if (n1 >= 0 and n2 >= 0) or (n1 <= 0 and n2 <= 0) \
    else "-"
num = moltiplicazione(abs(n1), abs(n2))
print(segno, num, sep="")