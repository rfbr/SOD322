#ifndef __ADJARRAY__
#define __ADJARRAY__
#include <vector>
#include "../include/edgelist.hpp"
#include <list>
#include <vector>
using namespace std;

class Adjarray
{
    public:
        unsigned long n;
        unsigned long e;
        edge * edges;
        unsigned long *cd;
        unsigned long *adj;
        //Constructor
        Adjarray();
};

Adjarray read_adj_array(char* input);
void mkadjarray(Adjarray& g);
#endif