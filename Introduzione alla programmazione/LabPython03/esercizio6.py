s = input("Stringa: ")
length = len(s)
i = 0
while i < length:
    if ord(s[i]) > 100:
        print("Il primo carattere con codice Unicode maggiore di 100 è", s[i])
        break
    i += 1

if i == length:
    print("stringa consumata e carattere non trovato")