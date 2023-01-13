def Ex3(file1,file2):
    with open(file1, encoding='UTF-8') as f:
        menu = {e[0]: {'prize': int(e[1]), 'ingredients': set(e[2:])} for e in 
            [l.split(',') for l in f.read().splitlines()]}

    with open(file2, encoding='UTF-8') as f:
        client_allergies = [(e[0], set(e[1:])) for e in 
            [l.split(',') for l in f.read().splitlines()]]

    return {client: max((name for name, info in menu.items() 
        if all(ingredient not in info['ingredients'] for ingredient in allergies)), 
            key=lambda n: menu[n]['prize'], default='Nessuno')
                for client, allergies in client_allergies}
