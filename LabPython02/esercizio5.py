def bisestile(n: int) -> True:
    if n % 4 == 0:
        if not n % 100 == 0:
            return True
        elif n % 400 == 0:
            return True
    return False

if __name__ == "__main__":
    n = int(input("anno: "))
    if bisestile(n):
        print("anno bisestile")
    else:
        print("anno non bisestile")
