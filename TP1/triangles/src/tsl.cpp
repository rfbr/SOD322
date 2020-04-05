#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "../include/edgelist.hpp"
#include "../include/tsl.hpp"

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

bool sort_by_row1(const vector<unsigned long> &v1,
                  const vector<unsigned long> &v2)
{
    return v1[1] > v2[1];
}

bool sort_by_row0(const vector<unsigned long> &v1,
                  const vector<unsigned long> &v2)
{
    return v1[1] < v2[1];
}

void mkadjlist(Adjlist &g)
{
    unsigned long i, u, v, k, l;
    g.adj.resize(g.n);
    g.d = (unsigned long *)calloc(g.n, sizeof(unsigned long));

    //Computing degree of each node
    for (i = 0; i < g.e; i++)
    {
        u = g.edges[i].s;
        v = g.edges[i].t;
        g.d[u]++;
        g.d[v]++;
    }

    vector<unsigned long> neighbour_with_degree(3);
    vector<vector<unsigned long>> neighbors_with_degree(g.n, neighbour_with_degree);

    //Matching node and their degree
    for (i = 0; i < g.n; i++)
    {
        neighbors_with_degree[i][0] = i;
        neighbors_with_degree[i][1] = g.d[i];
    }

    //Sorting nodes in non-increasing order according to their degree
    sort(neighbors_with_degree.begin(), neighbors_with_degree.end(), sort_by_row1);

    //Create new node label
    for (i = 0; i < g.n; i++)
    {
        neighbors_with_degree[i][2] = i;
    }

    //Resorting the matrix to get true node label as index
    sort(neighbors_with_degree.begin(), neighbors_with_degree.end(), sort_by_row0);

    //Create the adjacency list with the new labels
    for (i = 0; i < g.e; i++)
    {
        u = g.edges[i].s;
        v = g.edges[i].t;

        //get new labels
        k = neighbors_with_degree[u][2];
        l = neighbors_with_degree[v][2];

        g.adj[k].push_back(l);
        g.adj[l].push_back(k);
        g.edges[i].s = k;
        g.edges[i].t = l;
    }

    //truncate neighbors w of u/v such that degree(w)>degree(u/v) in the adjacency list
    for (i = 0; i < g.e; i++)
    {
        u = g.edges[i].s;
        v = g.edges[i].t;
        g.adj[u].sort(greater<>());
        g.adj[v].sort(greater<>());
        list<unsigned long>::iterator it;

        while ((g.adj[u].front() > u) & (!g.adj[u].empty()))
        {
            g.adj[u].pop_front();
        }

        while ((g.adj[v].front() > v) & (!g.adj[v].empty()))
        {
            g.adj[v].pop_front();
        }
    }
}