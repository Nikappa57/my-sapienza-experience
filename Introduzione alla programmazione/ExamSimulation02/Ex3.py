def Ex3(file1,file2):
    with open(file1, encoding='UTF-8') as f:
        file_data = [l.split(',') for l in f.read().splitlines() if l]

    data = {l[0]: {'amount': int(l[1]), 'minAmount': int(l[2]), 
        'prize': int(l[3]), 'notSell': 0} for l in file_data}

    with open(file2, encoding='UTF-8') as f:
        sells = [l.split(',', 1) for l in f.read().splitlines() if l]

    for name, amount in sells:
        amount = int(amount)
        product = data[name]

        if amount > 0: # buy
            if (product['amount'] < product['minAmount'] and product['amount'] 
                + amount >= product['minAmount']):
                product['prize'] -= 5
            product['amount'] += amount
        else: # sells
            if (product['amount'] >= product['minAmount'] 
                and amount + product['amount'] < product['minAmount']):
                product['prize'] += 5
            if amount + product['amount'] < 0:
                product['notSell'] -= amount + product['amount']
                product['amount'] = 0
            else:
                product['amount'] = amount + product['amount']

    return {name: [info['amount'], info['notSell'], info['prize']] 
        for name, info in data.items()}