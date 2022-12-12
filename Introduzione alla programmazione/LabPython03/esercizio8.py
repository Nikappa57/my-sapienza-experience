s = input("stringa palindroma: ")

while s != s[::-1]:
    s = input("non palindroma, inserire una stringa palindroma: ")
print("stringa palindroma di lunghezza", len(s))