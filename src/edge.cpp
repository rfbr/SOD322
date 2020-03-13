#include <stdio.h>
#include <cmath>
#include <algorithm>
#include "../include/edge.hpp"
using namespace std;

#define NLINKS 100000000


Edgelist read_edge_list(char* input){
    unsigned long n = NLINKS;
    FILE *file = fopen(input, "r");
    Edgelist e_list;

    vector<edge> edges(n);
    e_list.edges = edges;

    while(fscanf(file,"%lu %lu", &(e_list.edges[e_list.e].s),&(e_list.edges[e_list.e].t))==2){
        e_list.n = max(max(e_list.n,e_list.edges[e_list.e].s),e_list.edges[e_list.e].t);
        if(++(e_list.e)==n){
            n+=NLINKS;
            e_list.edges.resize(n);
        }
    }
    fclose(file);
    e_list.n++;
    e_list.edges.resize(e_list.e*sizeof(edge));
    return e_list;
}

Edgelist::Edgelist(): n(0), e(0){}
Edgelist::Edgelist(unsigned long n, unsigned long e): n(n), e(e){}
