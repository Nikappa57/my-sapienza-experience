def Ex3(file1,file2,n):
    with open(file1, encoding='UTF-8') as f:
        catalog = {e[0]: 
            {'amount': int(e[1]), 'prize': int(e[2]), 'sell': 0, 'notSell': 0} 
            for e in [l.split(',') for l in f.read().splitlines()]}

    with open(file2, encoding='UTF-8') as f:
        records = [(e[1], int(e[2])) for e in 
            [l.split(',') for l in f.read().splitlines()] if int(e[0]) <= n]

    for name, amount in records:
        product = catalog[name]

        if amount > 0: # buy
            product['amount'] += amount
        else: # sell
            remain = amount + product['amount']
            if remain < 0:
                product['sell'] += product['amount']
                product['amount'] = 0
                product['notSell'] -= remain 
            else:
                product['amount'] += amount
                product['sell'] -= amount

    return {name: [info['sell'] * info['prize'], info['notSell'] * info['prize']] 
        for name, info in catalog.items() if info['sell'] or info['notSell']}
