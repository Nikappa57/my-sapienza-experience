n = int(input("numero: "))

is_primo = True
i = 2
while i <= n/2:
    if n % i == 0:
        is_primo = False
    i += 1
if is_primo:
    print("numero primo")
else:
    print("numero non primo")