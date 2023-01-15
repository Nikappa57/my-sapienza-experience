def Ex3(file1,file2):
    with open(file1, encoding='UTF-8') as f:
        menu = {e[0]: e[1:] for e in 
            [l.split(',') for l in f.read().splitlines()]}

    with open(file2, encoding='UTF-8') as f:
        favourites = {e[0]: e[1:] for e in 
            [l.split(',') for l in f.read().splitlines()]}

    result = {client: str() for client in favourites.keys()}
    for client, fav in favourites.items():
        favourite_name = 'Nessuno'
        for name, ingredients in menu.items():
            favourite_nums = (len(set(menu[favourite_name]).intersection(set(fav))) 
                if favourite_name != 'Nessuno' else 0)
            fav_ingredients = len(set(ingredients).intersection(set(fav)))
            if fav_ingredients and ((favourite_nums == fav_ingredients 
                and name > favourite_name) or fav_ingredients > favourite_nums):
                favourite_name = name
        result[client] = favourite_name

    return result