seq = [1, 1]
i = 2
n = int(input("numero: "))
while i < n:
    seq.append(seq[i - 1] + seq[i - 2])
    i += 1
print("\n".join(str(i) for i in seq[:n]))