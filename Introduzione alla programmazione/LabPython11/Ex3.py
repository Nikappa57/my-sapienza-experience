import re

def Ex3(file):
    with open(file, encoding='UTF-8') as f:
        lines = f.readlines()
    pattern = r'\b\w*(\w)\1\w*\b\W*\b\w*\1\1\w*\b\W*\b\w*\1\1\w*\b'
    return sum([len(re.findall(pattern, l, flags=re.IGNORECASE)) for l in lines])
