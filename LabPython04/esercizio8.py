s = list()
i = 1
s.append(input("stringa: "))

while True:
    s.append(input("stringa: "))
    if s[i - 1][-1] == s[i][0]:
        print(s[i - 1], s[i])
        break
    i += 1
