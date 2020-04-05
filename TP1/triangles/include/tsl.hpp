#ifndef __ADJLIST_WITH_DEGREE__
#define __ADJLIST_WITH_DEGREE__
#include <vector>
#include "../include/edgelist.hpp"
#include <list>
#include <vector>
using namespace std;

class Adjlist
{
    public:
        unsigned long n;
        unsigned long e;
        edge * edges;
        vector<list<unsigned long>> adj;
        unsigned long * d;
        //Constructor
        Adjlist();
};

Adjlist read_adj_list(char* input);
void mkadjlist(Adjlist& g);
#endif