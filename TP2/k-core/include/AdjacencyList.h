#ifndef DEF_ADJACENCYLIST
#define DEF_ADJACENCYLIST

#include <iostream> 
#include <string>
#include <cmath> 
#include <vector> 
#include <stdlib.h>
#include <fstream>
#include <map>
#include <set>
#include <bits/stdc++.h>

using namespace std;


class AdjacencyList
{
	public:
		AdjacencyList(string);
		~AdjacencyList();
	 	void drop(int, int);

	 	unordered_map<int, set<int> > adj_list;
	    unordered_map<int, int> degrees;
	    unordered_map<int, set<int> > grouped_by_degrees;
	 	int num_nodes;
	 	int max_degree;

	private:

	    string path_file_edges;
	    string path_file_nodes;
	    ifstream file_edges;
	    ifstream file_nodes;

		void buildAdjacencyList();
		void findNumNodes();
		void findMaximum();

};

#endif
