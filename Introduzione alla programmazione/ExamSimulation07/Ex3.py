def Ex3(file1,l):
    with open(file1, encoding='UTF-8') as f:
        data = [l.split(',') for l in f.read().splitlines()]
    requests = [(l[i], l[i+1]) for i in range(0, len(l), 2)]
    return {ability:
        min(
        [info for info in data if info[1] == ability and int(info[2]) >= day_required],
        key=lambda e: int(e[2]), default=('Nessuno', '', 0))[0]
            for ability, day_required in requests}