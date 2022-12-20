import re

def Ex6(file):
    with open(file, encoding='UTF-8') as f:
        string = f.read()
    pattern = r'\b(\w)\w*(\w)\2\w*\1\b'
    return len(re.findall(pattern, string, flags=re.IGNORECASE))