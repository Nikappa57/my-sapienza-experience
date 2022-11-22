s = input("stringa: ")

liv = 0
for i in range(len(s) // 2 + 1):
    if s[i] != s[-(i + 1)]:
        break
    liv += 1

print("livello:", liv if liv < len(s)/2 else len(s))
