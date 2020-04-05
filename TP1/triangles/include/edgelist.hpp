#ifndef __EDGELIST__
#define __EDGELIST__

using namespace std;
struct edge
{
    unsigned long s;
    unsigned long t;
};

class Edgelist
{
    public:
        unsigned long n;
        unsigned long e;
        edge* edges;
        //Constructeurs
        Edgelist();
        Edgelist(unsigned long n,unsigned long e);
};

Edgelist read_edge_list(char* input);

#endif