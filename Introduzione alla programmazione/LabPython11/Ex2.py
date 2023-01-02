import re

def Ex2(file):
    with open(file, encoding='UTF-8') as f:
        string = f.read()
    pattern = r'\b\w*(\w)\w*(\w)\w*\b\W*\b\w*\2\w*\1\w*\b'
    return len(re.findall(pattern, string, flags=re.IGNORECASE))