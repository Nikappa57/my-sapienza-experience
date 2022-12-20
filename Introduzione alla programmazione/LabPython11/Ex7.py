import re

def Ex7(file):
    with open(file, encoding='UTF-8') as f:
        string = f.read()
    validi_pattern = r'^(([0-1]?\d?\d|2[0-4][0-9]|25[0-5])\.){1,3}([0-1]?\d?\d|2[0-4][0-9]|25[0-5])$'
    domestici_pattern = r'^(192\.168\.([0-1]?\d?\d|2[0-4][0-9]|25[0-5])\.[0-1]?\d?\d|2[0-4][0-9]|25[0-5])$'
    
    result = {'domestici': len(re.findall(domestici_pattern, string, flags=re.MULTILINE))}
    result['altri'] = len(re.findall(validi_pattern, string, flags=re.MULTILINE)) - result['domestici']
    result['invalidi'] = len(string.splitlines()) - sum(result.values())