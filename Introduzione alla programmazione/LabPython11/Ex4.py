def Ex4(file):
    with open(file, encoding='UTF-8') as f:
        data = [l.split(',') for l in f.read().splitlines()[1:]]

    items = {d[0] for d in data}
    result = {item: list() for item in items}
    for item in items:
        item_info = [l[1:] for l in data if l[0] == item]
        chain = [item_info[0][0]]
        for info in item_info:
            if chain[-1] == info[0]:
                chain.append(info[1])
        result[item].append(chain[0])
        result[item].append(chain[-1])