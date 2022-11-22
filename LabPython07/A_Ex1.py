def A_Ex1(l1, l2):
    assert len(l2) >= len(l2)

    return [l2[i] if i > len(l1) - 1 else l1[i] + l2[i] for i in range(len(l2))]
