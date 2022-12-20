import re

def parser(line):
    pattern = r'^(?:[A-Z]{3} ?){2} ?(?P<y>\d\d)(?P<m>[A-Z])(?P<d>\d\d) ?[A-Z]\d{3}[A-Z]$'
    months = {'A': 1, 'B': 2, 'C': 3, 'D': 4, 'E': 5, 'H': 6, 'L': 7, 'M': 8, 'P': 9, 'R': 10, 'S': 11, 'T': 12}
    days = {'A': 31, 'B': 28, 'C': 31, 'D': 30, 'E': 31, 'H': 30, 'L': 31, 'M': 31, 'P': 30, 'R': 31, 'S': 30, 'T': 31}
    m = re.search(pattern, line)

    if not m:
        return 'Codice errato'

    if m.group('m') not in months.keys():
        return 'Mese errato'

    day = int(m.group('d')) - 40 if int(m.group('d')) > 40 else int(m.group('d'))
    if day > days[m.group('m')]:
        return 'Giorno errato'

    return '{:02d}/{:02d}/{}'.format(
        day, 
        months[m.group('m')],
        int(m.group("y")) + (2000 if int(m.group("y")) <= 20 else 1900)
    )

def Ex8(file):
    with open(file, encoding='UTF-8') as f:
        lines = f.read().splitlines()
    return list(map(parser, lines))