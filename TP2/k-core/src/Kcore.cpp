#include <iostream> 
#include <string>
#include <cmath> 
#include <vector> 
#include <stdlib.h>
#include <fstream>
#include <map>

#include "../include/Kcore.h"
#include "../include/AdjacencyList.h"

using namespace std;

Kcore::Kcore(string InputNodes, string InputEdges): G(InputNodes, InputEdges)
{

}

Kcore::~Kcore()
{

}

void Kcore::algorithm()
{	
	cout << "k-core decomposition !" << endl;
	int c = 0;
	int count = 0;
	while (!G.adj_list.empty())
	{
		count += 1;

		if (count % 1000 == 0) 
		{
			cout << count << " nodes done" << endl;
		}
		vector<int> min_degree(2);
		min_degree = findMinimum();
		c = max(c, min_degree[1]);
		if (kcore_map.count(c) == 0)
		{	
			vector<int> tmp = {min_degree[0]};
			kcore_map[c] = tmp;
		}
		else
		{
			kcore_map[c].push_back(min_degree[0]);
		}
		G.drop(min_degree[0]);
	}
	cout << "completed" << endl;
}

vector<int> Kcore::findMinimum()
{
	int min_node(G.adj_list.begin()->first);
	int min_degree(G.adj_list.begin()->second.size());
	for (auto &x : G.adj_list)
	{
		if (x.second.size() <= min_degree)
		{
			min_node = x.first;
			min_degree = x.second.size();
		}
	}
	vector <int> res = {min_node, min_degree};
	return res;
}
