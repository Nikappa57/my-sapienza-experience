s1 = input("stringa: ")
s2 = input("stringa: ")

result = (0, 0) # start and finish

for i in range(len(s1)):
    for j in range(i + 1, len(s1) + 1):
        if s1[i:j] in s2:
            if j - i > result[1] - result[0]:
                result = (i, j)
        else:
            break
            
print(s1[result[0]:result[1]])