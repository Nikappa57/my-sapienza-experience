n_pos = 0
n = str()

while n != '*':
    n = input("numero: ")
    if n.isdigit():
        n_pos += 1
print(n_pos)