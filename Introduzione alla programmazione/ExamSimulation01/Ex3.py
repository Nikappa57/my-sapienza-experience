def Ex3(file1,file2):
    with open(file1, encoding='UTF-8') as f:
        foodsData = [l.strip().split(',') for l in f.read().splitlines() if l]
    with open(file2, encoding='UTF-8') as f:
        clientsData = [l.strip().split(',') for l in f.read().splitlines() if l]

    return {client:
        max([(name, price, ingredients) for name, price, *ingredients in foodsData if
            all(ingredient not in allergies for ingredient in ingredients)],
            key=lambda foodData: (int(foodData[1]), foodData[0]),
            default=['Nessuno', 0])[0]
        for client, *allergies in clientsData}