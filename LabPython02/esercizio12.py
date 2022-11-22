temperatura = int(input("Temperatura: "))
scala = input("scala (C/F): ")

if scala == "F":
    temperatura = (temperatura - 32)/1.8

if scala in ("C", "F"):
    if temperatura >= 100:
        print("gassosa")
    elif temperatura > 0:
        print("liquida")
    else:
        print("solida")