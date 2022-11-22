def check(s: str, n: int) -> bool:
    for i in range(len(s) - n):
        if s[i] == s[i + n]:
            return True
    return False

s = input("stringa: ")
n = int(input("numero: "))
print(check(s, n))