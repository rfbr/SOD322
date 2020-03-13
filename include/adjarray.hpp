#ifndef __ADJARRAY__
#define __ADJARRAY__
#include <vector>
#include "../include/edge.hpp"
#include "../include/graph.hpp"

using namespace std;

class Adjlist
{
    public:
        unsigned long n;
        unsigned long e;
        vector<edge> edges;
        vector<unsigned long> cd;
        vector<unsigned long> adj;
        //Constructor
        Adjlist();
};

Adjlist read_adj_list(char* input);
void mkadjlist(Adjlist& g);
#endif