s = input("stringa: ")

# Metodo alternativo senza .rfind()
# n_max = 0
# for i in range(len(s)):
#     for n in range(1, len(s) - i):
#         if s[i] == s[i + n] and n > n_max:
#             n_max = n
# print(n_max)

n2_max = 0
for i, c in enumerate(s):
    c_distance = s.rfind(c) - i
    if c_distance > n2_max:
        n2_max = c_distance
print(n2_max)