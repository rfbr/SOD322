import resource
import time
import matplotlib.pyplot as plt
import networkx as nx
import random_graph as rg
import label_propagation as lp
from itertools import cycle
from modularity_maximization.utils import get_modularity
from convert import convert


start_time = time.clock()
G_read = nx.read_edgelist('clean_com-lj.top5000.cmty.txt')     #To read a graph
#G_random = rg.generate_default_random_graph(0.1, 0.1) #To generate a benchmark random_graph



H_read = lp.label_propagation_communities(G_read)

#H_random = lp.label_propagation_communities(G_random)





time_computing = time.clock()
print("Time to compute communities : %s seconds" % (time_computing - start_time))


def unpack(community_set):
    assert type(community_set).__name__ == "set"
    return [x for x in community_set]


def generator_to_graph(H):
    assert type(H).__name__ == 'generator'
    save_for_drawings = []
    for community in H:
        save_for_drawings.append(community)
        unpacked_community = unpack(community)
        label_propaged_graph = [*unpacked_community, ]
    return label_propaged_graph, save_for_drawings

#These two functions must be used with a random_generated graph, for a read graph, use convert function




graph_of_communities_read, drawings = convert(H_read)

#graph_of_communities_random, drawings = generator_to_graph(H_random)



error_read_label_propagation = get_modularity(G_read,graph_of_communities_read)

#error_random = get_modularity(G_read,graph_of_communities_random)



print("Modularity = ", error_read_label_propagation)

#print("Modularity = ", error_random)


#Drawing
pos = nx.spring_layout(G_read)
cycol = cycle('bgrcmk')
plt.figure(1)
for community in drawings:
    nx.draw_networkx_nodes(G_read, pos, nodelist=community, node_color=next(cycol), node_size=1)

plt.figure(2)
nx.draw(G_read,pos, ax=None)
plt.show()
print(resource.getrusage(resource.RUSAGE_SELF).ru_maxrss)
#Get the total amount of memory used



'''#Drawing
pos = nx.spring_layout(G_random)
cycol = cycle('bgrcmk')
plt.figure(1)
for community in drawings:
    nx.draw_networkx_nodes(G_random, pos, nodelist=community, node_color=next(cycol), node_size=1)

plt.figure(2)
nx.draw(G_random,pos, ax=None)
plt.show()

#Get the total amount of memory used
print(resource.getrusage(resource.RUSAGE_SELF).ru_maxrss)'''