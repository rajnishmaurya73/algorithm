function: MinCutPhase(Graph G, Weights W, Vertex a):
    A <- {a}
    while A != V:
        add tightly connected vertex to A
    store cut_of_the_phase and shrink G by merging the two vertices added last

minimum = INF
function: MinCut(Graph G, Weights W, Vertex a):
    while |V| > 1:
        MinCutPhase(G,W,a)
        if cut_of_the_phase < minimum:
            minimum = cut_of_the_phase
    return minimum
