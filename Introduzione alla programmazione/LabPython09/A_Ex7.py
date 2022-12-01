def A_Ex7(fileName):
    with open(fileName, encoding="UTF-8") as f:
        return sum(int(i) for i in f.read().replace('\n', ' ').split(' ') if i.isdigit())
