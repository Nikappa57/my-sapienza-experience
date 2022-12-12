while True:
    s = input("stringa: ")
    print(s[0], s[-1], sep="")
    if s.isalpha() and s.islower():
        break