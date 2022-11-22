cane = float(input("anni del cane: "))

uomo = ((cane - 2) * 4) if cane > 2 else 0

if cane > 0:
    uomo += 10.5
if cane > 1:
    uomo += 10.5

print(uomo)