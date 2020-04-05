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
	cout << "degré maximal : " << max_degree << endl;
}

AdjacencyList::~AdjacencyList()
{

}

vector<string> findSourceAndTarget(string line)
{
	vector<string> s_and_t;
	stringstream tmp(line);
	string intermediate;
	int count = 0;
	while(getline(tmp, intermediate, ' '))
	{
		count += 1;
		s_and_t.push_back(intermediate);
		if (count == 2)
		{
			break;
		}
	}
	return s_and_t;
}
void AdjacencyList::buildAdjacencyList()
{
	if (file_edges)
	{	
		string line;
		int count = 0;
		while (getline(file_edges, line))
		{	
			if (isdigit(line[0]))
			{	
				count += 1;
				// source = stoi(line.substr(0, line.find(' '))); 
				// target = stoi(line.substr(to_string(source).length() + 1, line.find(' '))); 
				vector<string> s_and_t = findSourceAndTarget(line); 
				int source = stoi(s_and_t[0]);
				int target = stoi(s_and_t[1]);
				if (adj_list.find(source) == adj_list.end())
				{
					set<int> tmp;
					tmp.insert(target);
					adj_list[source] = tmp;
					degrees[source] = 1;
				}
				else 
				{
					adj_list[source].insert(target);
					degrees[source] += 1;
				}
				if (adj_list.find(target) == adj_list.end())
				{
					set<int> tmp;
					tmp.insert(source);
					adj_list[target] = tmp;		
					degrees[target] = 1;		
				}
				else
				{
					adj_list[target].insert(source);
					degrees[target] += 1;
				}
			}
			
		}
		num_nodes = adj_list.size();
		findMaximum();
		for (auto &x : adj_list)
		{
			if (grouped_by_degrees.find(x.second.size()) == grouped_by_degrees.end())
			{
				set<int> tmp;
				tmp.insert(x.first);
				grouped_by_degrees[x.second.size()] = tmp;
			}
			else
			{
				grouped_by_degrees[x.second.size()].insert(x.first);
			}
		}
		for (int i = 1; i <= max_degree; i++)
		{
			if(grouped_by_degrees.find(i) == grouped_by_degrees.end())
			{
				set<int> tmp;
				grouped_by_degrees[i] = tmp;
			}
		}
	}
	else	
	{
		cout << "error : unable to read edges file" << endl; 
	}
}


void AdjacencyList::drop(int node, int deg)
{
	set<int> neighbors(adj_list[node]);
	for (int neig : neighbors)
	{	
		adj_list[neig].erase(node);		
		grouped_by_degrees[adj_list[neig].size() + 1].erase(neig);
		// degrees[neig] -= 1;
		grouped_by_degrees[adj_list[neig].size()].insert(neig);
	}
	adj_list.erase(node);
	// degrees.erase(node);
	grouped_by_degrees[deg].erase(node);
}


void AdjacencyList::findMaximum()
{
	max_degree = 1;
	for (auto &x : degrees)
	{
		if (x.second > max_degree)
		{
			max_degree = x.second;
		}
	}
}

