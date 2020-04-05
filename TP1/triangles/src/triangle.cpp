#include <iostream>
#include <ctime>
#include <algorithm>
#include <fstream>
#include "../include/tsl.hpp"
using namespace std;

int triangle_list(Adjlist &graph)
{
    int nb_triangles = 0;
    unsigned long i, u, v;
    for (i = 0; i < graph.e; i++)
    {
        u = graph.edges[i].s;
        v = graph.edges[i].t;
        list<unsigned long> temp;

        //Need sorting the list before using set_intersection
        graph.adj[u].sort();
        graph.adj[v].sort();
        set_intersection(graph.adj[u].begin(), graph.adj[u].end(), graph.adj[v].begin(), graph.adj[v].end(), inserter(temp, temp.begin()));
        nb_triangles += temp.size();
    }
    return nb_triangles;
}

int main(int argc, char **argv)
{
    if (argv[1] == NULL)
    {
        cout << "Enter file name\n";
        return 0;
    }
    Adjlist g;
    const clock_t begin_time = clock();
    cout << "Reading edgelist from file " << argv[1] << "\n";
    g = read_adj_list(argv[1]);
    cout << "Number of nodes: " << g.n << "\n";
    cout << "Number of edges: " << g.e << "\n";
    cout << "Building adjacency list\n";
    mkadjlist(g);
    cout << "Listing triangles..." << endl;
    int nb_tringles = triangle_list(g);
    cout << "Number of triangles: " << nb_tringles << endl;
    cout << "Overall time = " << float(clock() - begin_time) / CLOCKS_PER_SEC << "\n";
    return 0;
}