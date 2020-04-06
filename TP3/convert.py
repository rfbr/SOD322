def convert(H):
    assert type(H).__name__ == 'generator'
    save_for_drawings = []
    D=dict()
    for community in H:
        save_for_drawings.append(community)
        for node in community:
            D.update({node: community})
    return D, save_for_drawings

#This function must be used with a read graph, not a generated one