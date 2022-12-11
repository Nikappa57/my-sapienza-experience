def A_Ex7(file):
    with open(file, encoding='UTF-8') as f:
        data = [l.split(',') for l in f.read().split('\n')[1:] if l]
    teams = set().union(*[l[:2] for l in data if l])
    return {team: sum(
        [(3 if int(l[2]) > int(l[3]) else 0 if int(l[2]) < int(l[3]) else 1) if l[0] == team else
            (3 if int(l[3]) > int(l[2]) else 0 if int(l[3]) < int(l[2]) else 1) if l[1] == team else 0 
                for l in data]) for team in teams}

