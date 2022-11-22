somma_n_pos = 0
n = str()

while n != '*':
    n = input("numero: ")
    if n.lstrip('-').isdigit():
        if int(n) < 0:
            somma_n_pos += int(n)
print(somma_n_pos)