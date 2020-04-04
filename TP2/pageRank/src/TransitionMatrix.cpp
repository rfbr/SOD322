#include <iostream> 
#include <string>
#include <cmath> 
#include <vector> 
#include <stdlib.h>
#include <fstream>
#include <map>

#include "../include/TransitionMatrix.h"


using namespace std;


TransitionMatrix::TransitionMatrix(string inputFileNodes, string inputFileEdges): path_file_nodes(inputFileNodes), path_file_edges(inputFileEdges), num_nodes(0), num_edges(0), file_edges(path_file_edges.c_str()), file_nodes(path_file_nodes.c_str())
{	
	cout << "building graph ..." << endl;
	cout << "nodes ..." << endl;
	findNumNodes();
	cout << "number of nodes : " << num_nodes << endl;
	cout << "edges ..." << endl;
	buildEdges();
	cout << "number of edges : " << num_edges << endl;
	cout << "degrees ..." << endl;
	buildDegrees();
}


int TransitionMatrix::numNodes()
{
	return num_nodes;
}


int TransitionMatrix::numEdges()
{
	return num_edges;
}

TransitionMatrix::~TransitionMatrix()
{

}



void TransitionMatrix::findNumNodes()
{
	if (file_nodes)
	{	
		string line;
		int count = 0;
		int node;
		while (count <= 8)
		{	
			getline(file_nodes, line);
			count += 1;
		}
		while (getline(file_nodes, line))
		{	
			node = stoi(line.substr(0, line.find(' ')));
			if (id_nodes.count(node) == 0)
			{
				id_nodes[node] = num_nodes;
				id_nodes_inverse[num_nodes] = node;
				num_nodes += 1;
			}

		}
	}
	else	
	{
		cout << "error : unable to read nodes file" << endl; 
	}
}

void TransitionMatrix::buildEdges()
{
	if (file_edges)
	{	
		string line;
		int count = 0;
		int node;
		vector<int> edge(2);
		while (count <= 8)
		{	
			string comment;
			getline(file_edges, line);
			count += 1;
		}
		int source;
		int target;
		while (getline(file_edges, line))
		{
			source = stoi(line.substr(0, line.find(' '))); 
			target = stoi(line.substr(to_string(source).length(), line.find(' '))); 
			edge[0] = source;
			edge[1] = target;
			edges.insert(edge);
			if (predecessors.count(target) == 0)
			{
				predecessors[target] = vector<int > {source};
			}
			else
			{
				predecessors[target].push_back(source);
			}
			num_edges += 1;
		}
	}
	else	
	{
		cout << "error : unable to read edges file" << endl; 
	}
}


void TransitionMatrix::buildDegrees()
{	
	for (auto &edge : edges)
	{ 
		if (degrees.count(edge[0]) == 0)
		{	
			degrees[edge[0]] = 1;
		}
		else
		{	
 			degrees[edge[0]] += 1;
		}
	}		
}

