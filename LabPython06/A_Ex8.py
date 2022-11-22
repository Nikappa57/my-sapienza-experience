s1 = input("stringa: ")
s2 = input("stringa: ")
n = int(input("numero: "))

result = (0, 0) # start and finish

for i in range(len(s1)):
    for j in range(i + 1, len(s1) + 1):
        if not (set(s1[i:j]) - set(s2)):
            if j - i >= result[1] - result[0] and j - i <= n:
                result = (i, j)
        else:
            break

print(s1[result[0]:result[1]])