import re

def Ex1(file):
    with open(file, encoding='UTF-8') as f:
        string = f.read()
    pattern = r'\b(\w)\w*(\w) \1\w*\2\b'
    return len(re.findall(pattern, string, flags=re.IGNORECASE))