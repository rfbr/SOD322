#ifndef DEF_TRANSITIONMATRIX
#define DEF_TRANSITIONMATRIX

#include <string>
#include <iostream> 
#include <cmath> 
#include <vector> 
#include <stdlib.h>
#include <fstream>
#include <map>
#include <set>

using namespace std; 

class TransitionMatrix
{
    public:
   TransitionMatrix(string, string);
    int numNodes();
    int numEdges();
    ~TransitionMatrix();

    set<vector<int> > edges; 
    map<int, int> degrees;
    map<int, int> id_nodes;
    map<int, int> id_nodes_inverse;
    int num_nodes;
    int num_edges;
    map<int, vector<int> > predecessors;

    private:
    string path_file_edges;
    string path_file_nodes;
    ifstream file_edges;
    ifstream file_nodes;

    void findNumNodes();
    void buildEdges();
    void buildDegrees();


 

};

#endif