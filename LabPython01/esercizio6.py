from math import sqrt, pow

a = float(input("a: "))
b = float(input("b: "))
c = float(input("c: "))

print((-b + sqrt((pow(b, 2) - 4 * a * c))) / 2 * a)
print((-b - sqrt((pow(b, 2) - 4 * a * c))) / 2 * a)