import resource
import time
import matplotlib.pyplot as plt
import networkx as nx
import random_graph as rg
import label_propagation as lp
from itertools import cycle
from modularity_maximization.utils import get_modularity


start_time = time.clock()

#G = nx.read_edgelist('../graphs/clean_com-lj.top5000.cmty.txt')     #To read a graph
G = rg.generate_default_random_graph(0.1, 0.1) #To generate a benchmark random_graph





def unpack(community_set):
    assert type(community_set).__name__ == "set"
    return [x for x in community_set]


def generator_to_graph(H):
    save_for_drawings = []
    for community in H:
        save_for_drawings.append(community)
        unpacked_community = unpack(community)
        label_propaged_graph = [*unpacked_community, ]
    return label_propaged_graph, save_for_drawings


H = lp.label_propagation_communities(G)

time_computing = time.clock()
print("Time to compute communities : %s seconds" % (time_computing - start_time))


graph_of_communities, drawings = generator_to_graph(H)
graph_of_communities2 = nx.generate_edgelist(graph_of_communities)
error_default = get_modularity(G,graph_of_communities2)
#error_default = error_on_random(G,H)
print("Total error of Label Propagation algorithm = ", error_default)



#Drawing
pos = nx.spring_layout(G)
cycol = cycle('bgrcmk')
plt.figure(1)
for community in drawings:
    nx.draw_networkx_nodes(G, pos, nodelist=community, node_color=next(cycol), node_size=1)

plt.figure(2)
nx.draw(G,pos, ax=None)
plt.show()

#Get the total amount of memory used
print(resource.getrusage(resource.RUSAGE_SELF).ru_maxrss)