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

Kcore::Kcore(string InputEdges): G(InputEdges)
{

}

Kcore::~Kcore()
{

}

void Kcore::algorithm()
{	
	cout << "k-core decomposition !" << endl;
	chrono::time_point<chrono::system_clock> start, end;
	start = chrono::system_clock::now();
	int c = 0;
	int count = 0;
	while (!G.adj_list.empty())
	{
		count += 1;

		if (count % 1000 == 0) 
		{
			cout << count << " nodes done" << endl;
		}
		
		int min_degree = 1;
		while(G.grouped_by_degrees[min_degree].empty() && min_degree < G.max_degree)
		{
			min_degree += 1;
		}
		if (G.grouped_by_degrees[min_degree].empty())
		{
			break;
		}
		set<int> min_nodes(G.grouped_by_degrees[min_degree]);
		int min_node;
		for (int x : min_nodes)
		{
			min_node = x;
			break;
		}

		// pair<int, int> min = findMinimum();
		// int min_degree = min.second;
		// int min_node = min.first;
		c = max(c, min_degree);
		if (kcore_unordered_map.find(c) == kcore_unordered_map.end())
		{	
			vector<int> tmp = {min_node};
			kcore_unordered_map[c] = tmp;
		}
		else
		{
			kcore_unordered_map[c].push_back(min_node);
		}
		G.drop(min_node, min_degree);
	}
	end = chrono::system_clock::now();
	float elapsed_time = chrono::duration_cast<chrono::seconds> (end - start).count();
	cout << "core value : " << c << endl;
	cout << "completed in " << elapsed_time << " seconds" << endl;
}



bool pairCompare( pair<int,int> i, pair<int,int> j)
{
return i.second < j.second;
} 

pair<int,int> Kcore::findMinimum()
{
	pair<int,int> min = *min_element(G.degrees.begin(), G.degrees.end(), pairCompare);
	return min;
}

