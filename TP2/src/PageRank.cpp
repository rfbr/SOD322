#include <iostream> // input output stream 
#include <string>
#include <cmath> 
#include <vector> 
#include <stdlib.h>
#include <fstream>

#include "../include/TransitionMatrix.h"
#include "../include/PageRank.h"

using namespace std;



PageRank::PageRank(string inputFileNodes, string inputFileEdges, float inputAlpha=0.2): path_file_nodes(inputFileNodes), path_file_edges(inputFileEdges), alpha(inputAlpha), T(path_file_nodes, path_file_edges)
{
	cout << "building PageRank vector ... " << endl;
	for (int i = 0; i < T.num_nodes; i++)
	{
		page_rank_vec.push_back(1 / (float) T.num_nodes);
	}
}


void PageRank::powerIteration(int t)
{	
	cout << "power iteration algo with t = " << t << endl;
	for (int i=0; i < t; i++)
	{
		cout << "iteration " << i + 1 << "..." <<endl;
		matMul();
		secondStep();
		cout << "visualize some pagerank values :" << endl;
	    for (int i=100; i < 150; i++)
		{
			cout << page_rank_vec[i] << endl;
		} 
	} 


}


PageRank::~PageRank()
{

}

void PageRank::matMul()
{	
	vector<float> tmp(T.num_nodes, 0);
	
	for (int i = 0; i < T.num_nodes; i++)
	{	
		int node = T.id_nodes_inverse[i];
		for (int pred : T.predecessors[node])
		{	
			int j = T.id_nodes[pred];
			tmp[i] += page_rank_vec[j] * 1 / (float) T.degrees[pred];
		}
	}
	page_rank_vec = tmp;
}

void PageRank::secondStep()
{
	float sum = 0;
	for (float &x : page_rank_vec)
	{
		sum += abs(x);
	}

	for (int i = 0; i < T.num_nodes; i++)
	{
		page_rank_vec[i] = (1 - alpha) * page_rank_vec[i] + alpha / (float) T.num_nodes;
		page_rank_vec[i] += (1 - sum) / float (T.num_nodes); 
	}
}

