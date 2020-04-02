#ifndef __EDGE__
#define __EDGE__

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

void free_edgelist(Edgelist& e_list);
#endif