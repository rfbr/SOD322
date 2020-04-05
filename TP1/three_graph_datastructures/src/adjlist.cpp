#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "../include/edgelist.hpp"
#include "../include/adjlist.hpp"

#define NLINKS 100000000

//Constructor
Adjlist::Adjlist() : n(0), e(0) {}

Adjlist read_adj_list(char *input)
{
    unsigned long e = NLINKS;
    FILE *file = fopen(input, "r");
    Adjlist adj_list;

    adj_list.edges = (edge *)malloc(e * sizeof(edge));

    while (fscanf(file, "%lu %lu", &(adj_list.edges[adj_list.e].s), &(adj_list.edges[adj_list.e].t)) == 2)
    {
        adj_list.n = max(max(adj_list.n, adj_list.edges[adj_list.e].s), adj_list.edges[adj_list.e].t);
        if (++(adj_list.e) == e)
        {
            e += NLINKS;
            adj_list.edges = (edge *)realloc(adj_list.edges, e * sizeof(edge));
        }
    }
    fclose(file);
    adj_list.n++;
    adj_list.edges = (edge *)realloc(adj_list.edges, e * sizeof(edge));
    return adj_list;
}

void mkadjlist(Adjlist &g)
{
    unsigned long i, u, v;
    g.adj.resize(g.n);
    for (i = 0; i < g.e; i++)
    {
        u = g.edges[i].s;
        v = g.edges[i].t;
        g.adj[u].push_back(v);
        g.adj[v].push_back(u);
    }
}