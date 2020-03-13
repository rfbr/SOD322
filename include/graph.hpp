#ifndef __GRAPH__
#define __GRAPH__
#include "./edge.hpp"
#include "./adjarray.hpp"
#include "./adjmatrix.hpp"

class  Graph
{
    public:
        Edgelist edge_list;
        Adjmatrix adj_matrix;
        vector<unsigned long> adj_list;
};

#endif