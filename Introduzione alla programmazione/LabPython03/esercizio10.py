def is_primo(n: int) -> bool:
    i = 2
    while i <= n/2:
        if n % i == 0:
            return False
        i += 1
    return True

if __name__ == "__main__":
    n = int(input("numero >1 : "))
    i = 2
    while i <= n:
        if is_primo(i):
            print(i)
        i += 1

