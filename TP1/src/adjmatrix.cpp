#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "../include/edge.hpp"
#include "../include/adjmatrix.hpp"

#define NLINKS 100000000 

//Constructor
Adjmatrix::Adjmatrix(): n(0), e(0){}

Adjmatrix read_adj_matrix(char* input){
    unsigned long e = NLINKS;
    FILE *file = fopen(input, "r");
    Adjmatrix adj_matrix;

    adj_matrix.edges = (edge*) malloc(e*sizeof(edge));

    while(fscanf(file,"%lu %lu", &(adj_matrix.edges[adj_matrix.e].s),&(adj_matrix.edges[adj_matrix.e].t))==2){
        adj_matrix.n = max(max(adj_matrix.n,adj_matrix.edges[adj_matrix.e].s),adj_matrix.edges[adj_matrix.e].t);
        if(++(adj_matrix.e)==e){
            e+=NLINKS;
            adj_matrix.edges = (edge*) realloc(adj_matrix.edges,e*sizeof(edge));
        }
    }
    fclose(file);
    adj_matrix.n++;
    adj_matrix.edges = (edge*) realloc(adj_matrix.edges,e*sizeof(edge));
    return adj_matrix;
}

void mkadjmatrix(Adjmatrix& g){
    unsigned long i,u,v;
    g.mat = (bool*) malloc(g.n*g.n);
    for(i=0;i<g.e;i++){
        u = g.edges[i].s;
        v = g.edges[i].t;
        g.mat[u+g.n*v] = 1;
        g.mat[v+g.n*u] = 1;
    }
}