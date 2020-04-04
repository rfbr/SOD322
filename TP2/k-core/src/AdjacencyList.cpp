#include <iostream> 
#include <string>
#include <cmath> 
#include <vector> 
#include <stdlib.h>
#include <fstream>
#include <map>

#include "../include/AdjacencyList.h"

using namespace std;

AdjacencyList::AdjacencyList(string inputEdges): path_file_edges(inputEdges), file_edges(path_file_edges.c_str()), num_nodes(0)
{	
	cout << "building adjacency list of graph ... " << endl;
	buildAdjacencyList();
	cout << num_nodes << " Nodes" << endl;
}

AdjacencyList::~AdjacencyList()
{

}


void AdjacencyList::buildAdjacencyList()
{
	if (file_edges)
	{	
		string line;
		while (getline(file_edges, line))
		{	
			if (isdigit(line[0]))
			{
				int source;
				int target;
				source = stoi(line.substr(0, line.find(' '))); 
				target = stoi(line.substr(to_string(source).length() + 1, line.find(' '))); 
				if (adj_list.count(source) == 0)
				{
					set<int> tmp;
					tmp.insert(target);
					adj_list[source] = tmp;
				}
				else 
				{
					adj_list[source].insert(target);
				}
				if (adj_list.count(target) == 0)
				{
					set<int> tmp;
					tmp.insert(source);
					adj_list[target] = tmp;				
				}
				else
				{
					adj_list[target].insert(source);
				}
			}
			
		}
		num_nodes = adj_list.size();
	}
	else	
	{
		cout << "error : unable to read edges file" << endl; 
	}
}

void AdjacencyList::drop(int node)
{
	set<int> neighbors(adj_list[node]);
	for (int neig : neighbors)
	{
		adj_list[neig].erase(node);
	}
	adj_list.erase(node);	
}


