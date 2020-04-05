#ifndef __ADJMATRIX__
#define __ADJMATRIX__
#include <vector>
#include "../include/edgelist.hpp"
using namespace std;

class Adjmatrix
{
    public:
        unsigned long n;
        unsigned long e;
        edge * edges;
        bool* mat;
        //Constructor
        Adjmatrix();
};

Adjmatrix read_adj_matrix(char* input);
void mkadjmatrix(Adjmatrix& g);
#endif