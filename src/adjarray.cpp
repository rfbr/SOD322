#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "../include/edge.hpp"
#include "../include/adjarray.hpp"

#define NLINKS 100000000 

//Constructor
Adjlist::Adjlist(): n(0), e(0){}

Adjlist read_adj_list(char* input){
    unsigned long n = NLINKS;
    FILE *file = fopen(input, "r");
    Adjlist adj_list;

    vector<edge> edges(n);
    adj_list.edges = edges;

    while(fscanf(file,"%lu %lu", &(adj_list.edges[adj_list.e].s),&(adj_list.edges[adj_list.e].t))==2){
        adj_list.n = max(max(adj_list.n,adj_list.edges[adj_list.e].s),adj_list.edges[adj_list.e].t);
        if(++(adj_list.e)==n){
            n+=NLINKS;
            adj_list.edges.resize(n);
        }
    }
    fclose(file);
    adj_list.n++;
    adj_list.edges.resize(adj_list.e*sizeof(edge));
    return adj_list;
}

void mkadjlist(Adjlist& g){
    unsigned long i,u,v;
    vector<unsigned long> d(g.n);
    for(i=0;i<g.n;i++){
        d[g.edges[i].s]++;
        d[g.edges[i].t]++;
    }
    g.cd = vector<unsigned long>(g.n+1);
    g.cd[0]=0;
    for(i=1;i<g.n+1;i++){
        g.cd[i]=g.cd[i-1]+d[i-1];
        d[i-1]=0;
    }
    g.adj = vector<unsigned long>(2*g.e);
    for(i=0;i<g.e;i++){
        u = g.edges[i].s;
        v = g.edges[i].t;
        g.adj[g.cd[u]+d[u]++]=v;
        g.adj[g.cd[v]+d[v]++]=u;
    }
}
