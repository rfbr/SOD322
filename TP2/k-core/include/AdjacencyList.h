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

using namespace std;


class AdjacencyList
{
	public:
		AdjacencyList(string);
		~AdjacencyList();
	 	void drop(int);

	 	map<int, set<int> > adj_list;
	 	int num_nodes;

	private:

	    string path_file_edges;
	    string path_file_nodes;
	    ifstream file_edges;
	    ifstream file_nodes;	

		void buildAdjacencyList();
		void findNumNodes();

};

#endif
