def A_Ex1(fileName):
    with open(fileName, encoding="UTF-8") as f:
        return sum(c.isalpha() for c in f.read())
