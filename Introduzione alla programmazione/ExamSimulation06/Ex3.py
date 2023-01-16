def Ex3(file):
    with open(file, encoding='UTF-8') as f:
        data = [(e[0], int(e[1])) for e in 
            [l.split(',') for l in f.read().splitlines()]]
    clients_info = {k[0]: {'balance': 0, 'n-red': 0} for k in data}

    for client, money in data:
        clients_info[client]['balance'] += money
        if clients_info[client]['balance'] < 0:
            clients_info[client]['n-red'] += 1

    worst_client = min([(client, info) for client, info in clients_info.items()],
        key=lambda e: (-e[1]['n-red'], e[0]))
    if worst_client[1]['n-red'] == 0:
        return 'nessun prelievo in rosso'
    return (worst_client[0], worst_client[1]['balance'])