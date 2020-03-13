#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "../include/edge.hpp"
#include "../include/adjmatrix.hpp"

#define NLINKS 100000000 

//Constructor
Adjmatrix::Adjmatrix(): n(0), e(0){}

Adjmatrix read_adj_matrix(char* input){
    unsigned long n = NLINKS;
    FILE *file = fopen(input, "r");
    Adjmatrix adj_matrix;

    vector<edge> edges(n);
    adj_matrix.edges = edges;

    while(fscanf(file,"%lu %lu", &(adj_matrix.edges[adj_matrix.e].s),&(adj_matrix.edges[adj_matrix.e].t))==2){
        adj_matrix.n = max(max(adj_matrix.n,adj_matrix.edges[adj_matrix.e].s),adj_matrix.edges[adj_matrix.e].t);
        if(++(adj_matrix.e)==n){
            n+=NLINKS;
            adj_matrix.edges.resize(n);
        }
    }
    fclose(file);
    adj_matrix.n++;
    adj_matrix.edges.resize(adj_matrix.e*sizeof(edge));
    return adj_matrix;
}

void mkadjmatrix(Adjmatrix& g){
    unsigned long i,u,v;
    g.mat =  vector<bool>(g.n*g.n);
    for(i=0;i<g.e;i++){
        u = g.edges[i].s;
        v = g.edges[i].t;
        g.mat[u+g.n*v] = 1;
        g.mat[v+g.n*u] = 1;
    }
}