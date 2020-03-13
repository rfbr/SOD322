#ifndef __ADJMATRIX__
#define __ADJMATRIX__
#include <vector>
#include "../include/edge.hpp"
using namespace std;

class Adjmatrix
{
    public:
        unsigned long n;
        unsigned long e;
        vector<edge> edges;
        vector<bool> mat;
        //Constructor
        Adjmatrix();
};

Adjmatrix read_adj_matrix(char* input);
void mkadjmatrix(Adjmatrix& g);
#endif