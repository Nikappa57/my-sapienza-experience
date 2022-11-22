s = input("stringa: ")
if len(s) > len(set(s)):
    print(True)
else:
    print(False)