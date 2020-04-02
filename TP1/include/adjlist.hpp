#ifndef __ADJLIST__
#define __ADJLIST__
#include <vector>
#include "../include/edge.hpp"
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

        //Constructor
        Adjlist();
};

Adjlist read_adj_list(char* input);
void mkadjlist(Adjlist& g);
#endif