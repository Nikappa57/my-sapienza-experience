s = ["", "", " "]
while len(s[-2]) + len(s[-3]) != len(s[-1]):
    s.append(input("stringa: "))

print(" ".join(s[-3:]))
