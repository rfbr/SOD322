import networkx as nx
import random


def generate_default_random_graph(p, q):
    assert q <= p
    total_number_of_nodes = 400
    random_graph = nx.Graph()
    random_graph.add_nodes_from([i for i in range(399)])
    for i in range(total_number_of_nodes-1):
        for j in range(i+1, total_number_of_nodes):

            if i < 100:
                if j < 100 and random.random() < p:
                    random_graph.add_edge(i,j)
                elif j >= 100 and random.random() < q:
                    random_graph.add_edge(i, j)

            elif 100 <= i < 200:
                if j < 200 and random.random() < p:
                    random_graph.add_edge(i,j)
                elif j >= 200 and random.random() < q:
                    random_graph.add_edge(i, j)

            elif 200 <= i < 300:
                if j < 300 and random.random() < p:
                    random_graph.add_edge(i,j)
                elif j >= 300 and random.random() < q:
                    random_graph.add_edge(i, j)

            else:
                if random.random() < p:
                    random_graph.add_edge(i, j)
    return random_graph