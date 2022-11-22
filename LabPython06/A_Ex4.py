km1 = 0
km2 = 0

i = 1
for i in range(1000):
    km1 += 20
    km2 += i
    if km1 == km2:
        break
    i += 1

print("giorni:", i)

