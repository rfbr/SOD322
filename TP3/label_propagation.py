import networkx as nx
import random
from collections import Counter

def Fisher_Yates_shuffle(nodes):
    # Start from the last element and swap one by one
    n = len(nodes)
    for i in range(n - 1, 0, -1):
        j = random.randint(0, i)
        # Swap arr[i] with the element at random index
        nodes[i], nodes[j] = nodes[j], nodes[i]
    return nodes



def label_propagation_communities(G):
    """Generates community sets determined by label propagation

    Finds communities in `G` using a semi-synchronous label propagation
    method[1]_. This method combines the advantages of both the synchronous
    and asynchronous models. Not implemented for directed graphs.

    Parameters
    ----------
    G : graph
        An undirected NetworkX graph.

    Yields
    ------
    communities : generator
        Yields sets of the nodes in each community.

    Raises
    ------
    NetworkXNotImplemented
       If the graph is directed

    References
    ----------
    .. [1] Cordasco, G., & Gargano, L. (2010, December). Community detection
       via semi-synchronous label propagation algorithms. In Business
       Applications of Social Network Analysis (BASNA), 2010 IEEE International
       Workshop on (pp. 1-8). IEEE.
    """
    coloring = _color_network(G)
    # Create a unique label for each node in the graph
    labeling = {v: k for k, v in enumerate(G)}
    while not _labeling_complete(labeling, G):
        # Update the labels of every node with the same color.
        for color, nodes in coloring.items():
            for n in nodes:
                _update_label(n, labeling, G)

    for label in set(labeling.values()):
        yield set((x for x in labeling if labeling[x] == label))



def _color_network(G):
    """Colors the network so that neighboring nodes all have distinct colors.

       Returns a dict keyed by color to a set of nodes with that color.
    """
    coloring = dict()  # color => set(node)
    colors = nx.coloring.greedy_color(G)
    for node, color in colors.items():
        if color in coloring:
            coloring[color].add(node)
        else:
            coloring[color] = set([node])
    return coloring


def _labeling_complete(labeling, G):
    """Determines whether or not LPA is done.

       Label propagation is complete when all nodes have a label that is
       in the set of highest frequency labels amongst its neighbors.

       Nodes with no neighbors are considered complete.
    """
    return all(labeling[v] in _most_frequent_labels(v, labeling, G)
               for v in G if len(G[v]) > 0)


def _most_frequent_labels(node, labeling, G):
    """Returns a set of all labels with maximum frequency in `labeling`.

       Input `labeling` should be a dict keyed by node to labels.
    """
    if not G[node]:
        # Nodes with no neighbors are themselves a community and are labeled
        # accordingly, hence the immediate if statement.
        return {labeling[node]}

    # Compute the frequencies of all neighbours of node
    freqs = Counter(labeling[q] for q in G[node])
    max_freq = max(freqs.values())
    return {label for label, freq in freqs.items() if freq == max_freq}


def _update_label(node, labeling, G):
    """Updates the label of a node using the Prec-Max tie breaking algorithm

       The algorithm is explained in: 'Community Detection via Semi-Synchronous
       Label Propagation Algorithms' Cordasco and Gargano, 2011
    """
    high_labels = _most_frequent_labels(node, labeling, G)
    if len(high_labels) == 1:
        labeling[node] = high_labels.pop()
    elif len(high_labels) > 1:
        # Prec-Max
        if labeling[node] not in high_labels:
            labeling[node] = max(high_labels)