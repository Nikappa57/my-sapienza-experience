import re

def Ex5(file):
    with open(file, encoding='UTF-8') as f:
        string = f.read()
    
    auto_pattern = r'^[A-Z]{2}\d{3}[A-Z]{2}$'
    moto_pattern = r'^[A-Z]{2}\d{5}$'
    ciclomotore1_pattern = r'^[A-Z0-9]{5}$'
    ciclomotore2_pattern = r'^[A-Z0-9]{6}$'

    result = {
        'auto': len(re.findall(auto_pattern, string, flags=re.MULTILINE)),
        'moto': len(re.findall(moto_pattern, string, flags=re.MULTILINE)),
        'ciclomotore1': len(re.findall(ciclomotore1_pattern, string, flags=re.MULTILINE)),
        'ciclomotore2': len(re.findall(ciclomotore2_pattern, string, flags=re.MULTILINE)),
    }
    result['errata'] = len(string.splitlines()) - sum(result.values())

    return result