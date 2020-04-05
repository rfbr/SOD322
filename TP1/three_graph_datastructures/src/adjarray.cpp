#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "../include/edgelist.hpp"
#include "../include/adjarray.hpp"

#define NLINKS 100000000

//Constructor
Adjarray::Adjarray() : n(0), e(0) {}

Adjarray read_adj_array(char *input)
{
    unsigned long e = NLINKS;
    FILE *file = fopen(input, "r");
    Adjarray adj_array;

    adj_array.edges = (edge *)malloc(e * sizeof(edge));

    while (fscanf(file, "%lu %lu", &(adj_array.edges[adj_array.e].s), &(adj_array.edges[adj_array.e].t)) == 2)
    {
        adj_array.n = max(max(adj_array.n, adj_array.edges[adj_array.e].s), adj_array.edges[adj_array.e].t);
        if (++(adj_array.e) == e)
        {
            e += NLINKS;
            adj_array.edges = (edge *)realloc(adj_array.edges, e * sizeof(edge));
        }
    }
    fclose(file);
    adj_array.n++;
    adj_array.edges = (edge *)realloc(adj_array.edges, e * sizeof(edge));
    return adj_array;
}

void mkadjarray(Adjarray &g)
{
    unsigned long i, u, v;
    unsigned long *d = (unsigned long *)calloc(g.n, sizeof(unsigned long));

    for (i = 0; i < g.e; i++)
    {
        d[g.edges[i].s]++;
        d[g.edges[i].t]++;
    }

    g.cd = (unsigned long *)malloc((g.n + 1) * sizeof(unsigned long));
    g.cd[0] = 0;
    for (i = 1; i < g.n + 1; i++)
    {
        g.cd[i] = g.cd[i - 1] + d[i - 1];
        d[i - 1] = 0;
    }

    g.adj = (unsigned long *)malloc(2 * g.e * sizeof(unsigned long));

    for (i = 0; i < g.e; i++)
    {
        u = g.edges[i].s;
        v = g.edges[i].t;
        g.adj[g.cd[u] + d[u]++] = v;
        g.adj[g.cd[v] + d[v]++] = u;
    }
}