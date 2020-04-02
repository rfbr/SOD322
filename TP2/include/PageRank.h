#ifndef DEF_PAGERANK
#define DEF_PAGERANK

#include <string>
#include <iostream> 
#include <cmath> 
#include <vector> 
#include <stdlib.h>
#include <fstream>
#include <map>

using namespace std; 

class PageRank
{
	public:

	PageRank(string, string, float);
	void powerIteration(int);
	~PageRank();

	vector<float> page_rank_vec;

	private:

	string graph_file;
	float alpha;
	string path_file_nodes;
	string path_file_edges;
	TransitionMatrix T;
	

	void matMul();
	void secondStep();


};

#endif