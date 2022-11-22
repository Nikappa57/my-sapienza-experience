n = int(input("numeratore: "))
d = int(input("denominatore: "))

if n < d:
    print("propria")
elif n % d == 0:
    print("apparente")
elif n > d:
    print("impropria")