s = input("stringa: ")

m = 0, 0 # indice e numero
for i, c in enumerate(s):
    count = 0
    while i + count < len(s) and c == s[i + count]:
        count += 1
    if count >= m[1]:
        m = (c, count)

print(m[0], m[1])


    