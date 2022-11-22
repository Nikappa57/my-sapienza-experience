s = input("stringa: ")
max = s[-1]

for i in s[::-1]:
    if s.count(i) > s.count(max):
        max = i
print(max)