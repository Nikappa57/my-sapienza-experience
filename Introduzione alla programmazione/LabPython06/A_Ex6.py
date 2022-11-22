numeraleAlieno="349776123345679876543234567876543234569055"
numeroTerrestre=9510990939794952322311710154344301747012051743844839

num_b = list()
base = 2
while num_b != numeraleAlieno:
    assert(numeroTerrestre > base)
    num_b = list()
    temp_numeroTerrestre = numeroTerrestre

    while temp_numeroTerrestre > base:
        num_b.insert(0, temp_numeroTerrestre % base)
        temp_numeroTerrestre = temp_numeroTerrestre // base

    num_b.insert(0, temp_numeroTerrestre)
    num_b = "".join(str(c) for c in num_b)
    base += 1

print(base)