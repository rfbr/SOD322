#include <stdio.h>
#include <cmath>
#include <algorithm>

#include "../include/edgelist.hpp"
using namespace std;

#define NLINKS 100000000

Edgelist read_edge_list(char *input)
{
    unsigned long e = NLINKS;
    FILE *file = fopen(input, "r");
    Edgelist e_list;

    e_list.edges = (edge *)malloc(e * sizeof(edge));

    while (fscanf(file, "%lu %lu", &(e_list.edges[e_list.e].s), &(e_list.edges[e_list.e].t)) == 2)
    {
        e_list.n = max(max(e_list.n, e_list.edges[e_list.e].s), e_list.edges[e_list.e].t);
        if (++(e_list.e) == e)
        {
            e += NLINKS;
            e_list.edges = (edge *)realloc(e_list.edges, e * sizeof(edge));
        }
    }
    fclose(file);
    e_list.n++;
    e_list.edges = (edge *)realloc(e_list.edges, e * sizeof(edge));
    return e_list;
}

Edgelist::Edgelist() : n(0), e(0) {}
Edgelist::Edgelist(unsigned long n, unsigned long e) : n(n), e(e) {}