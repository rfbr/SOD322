import resource
import sys
import shlex
from subprocess import call
from itertools import cycle
import matplotlib.pyplot as plt
import networkx as nx
import label_propagation as lp
from convert import convert
from modularity_maximization.utils import get_modularity
from convert import convert

print("1st arg : path to louvain executable \n"
      "2nd arg : path to file to process \n"
      "3rd arg : path output file (please specify a name) \n"
      "4th arg : Relative path from this file to your processed_graph")

path_to_louvain_executable = sys.argv[1]
relative_path_to_file = sys.argv[2]
relative_path_to_output_file = sys.argv[3]
absolute_path_to_output_file = sys.argv[4]

cmd = shlex.split('/usr/bin/time -v ./path_to_louvain file_to_process /processed_graphs/processed_file_to_process')


cmd[2] = path_to_louvain_executable
cmd[3] = relative_path_to_file
cmd[4] = relative_path_to_output_file

call(cmd)

G_louvain = nx.read_edgelist(absolute_path_to_output_file)

H_louvain = lp.label_propagation_communities(G_louvain) #Take a neglectable amount of time  \
                                                        #since G has already been processed by louvain.c

graph_of_communities_louvain, drawings = convert(H_louvain)

error_louvain = get_modularity(G_louvain, graph_of_communities_louvain)

print("Total error of Louvain algorithm on random graph = ", error_louvain)


#Drawing
pos = nx.spring_layout(G_louvain)
cycol = cycle('bgrcmk')
plt.figure(1)
for community in drawings:
    nx.draw_networkx_nodes(G_louvain, pos, nodelist=community, node_color=next(cycol), node_size=1)

plt.figure(2)
nx.draw(G_louvain,pos, ax=None)
plt.show()

#Get the total amount of memory used
print(resource.getrusage(resource.RUSAGE_SELF).ru_maxrss)
