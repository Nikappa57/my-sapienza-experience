c = input("carattere: ")
s = str()

while s.count(c) < 2:
    s = input("stringa: ")

print(s.count(c))