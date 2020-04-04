#include <iostream> 
#include <string>
#include <cmath> 
#include <vector> 
#include <stdlib.h>
#include <fstream>
#include <map>

#include "../include/AdjacencyList.h"

using namespace std;

AdjacencyList::AdjacencyList(string inputNodes, string inputEdges): path_file_nodes(inputNodes), path_file_edges(inputEdges), file_edges(path_file_edges.c_str()), file_nodes(path_file_nodes.c_str()), num_nodes(0)
{	
	cout << "building adjacency list of graph ... " << endl;
	findNumNodes();
	cout << num_nodes << " Nodes" << endl;
	buildAdjacencyList();


}

AdjacencyList::~AdjacencyList()
{

}

void AdjacencyList::findNumNodes()
{
	if (file_nodes)
	{	
		string line;
		while (getline(file_nodes, line))
		{	
			num_nodes += 1;
		}
	}
	else	
	{
		cout << "error : unable to read nodes file" << endl; 
	}
}

void AdjacencyList::buildAdjacencyList()
{
	if (file_edges)
	{	
		string line;
		while (getline(file_edges, line))
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

