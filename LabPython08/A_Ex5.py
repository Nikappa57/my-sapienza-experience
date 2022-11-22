def A_Ex5(a,b):
    return {(nome, regione) for nome, citta in a for citta_r, regione in b 
                if citta == citta_r}
