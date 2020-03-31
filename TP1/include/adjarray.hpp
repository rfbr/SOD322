#ifndef __ADJARRAY__
#define __ADJARRAY__
#include <vector>
#include "../include/edge.hpp"

using namespace std;

class Adjlist
{
    public:
        unsigned long n;
        unsigned long e;
        edge * edges;
        unsigned long * cd;
        unsigned long * adj;
        //Constructor
        Adjlist();
};

Adjlist read_adj_list(char* input);
void mkadjlist(Adjlist& g);
#endif