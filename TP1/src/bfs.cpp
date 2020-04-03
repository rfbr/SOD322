#include <iostream>
#include <ctime>
#include <queue>
#include "../include/adjlist.hpp"

unsigned long bfs(Adjlist& graph, const unsigned long & node,bool* & mark){
    queue<unsigned long> fifo;
    fifo.push(node);
    mark[node] = 1;
    unsigned long compteur = 0;
    while(!fifo.empty()){
        compteur ++;
        unsigned long u = fifo.front();
        fifo.pop();
        list<unsigned long> :: iterator it;
        for(it = graph.adj[u].begin(); it != graph.adj[u].end(); ++it){
            unsigned long neighbour = *it;
            if(!mark[neighbour]){
                fifo.push(neighbour);
                mark[neighbour] = 1; 
            }
        }
    }
    return compteur;
}

int main(int argc, char** argv){
    if (argv[1]==NULL){
        cout << "Enter file name\n";
        return 0;
    }
    Adjlist g;
    const clock_t begin_time = clock();
    cout << "Reading edgelist from file "<<argv[1]<<"\n";
    g = read_adj_list(argv[1]);
    cout << "Number of nodes: " << g.n << "\n";
    cout << "Number of edges: " << g.e << "\n";
    cout << "Building adjacency list\n";
    mkadjlist(g);
    cout << "Bfs\n";
    bool* mark = (bool*) malloc(g.n);
    unsigned long max_size = 0;
    for(unsigned long i=0;i<g.n;i++){
        if (!mark[i]){
            max_size = max(max_size,bfs(g,i,mark));
        }
    }
    cout << "Size of the biggest cluster: " << max_size << "\n";
    cout << "Fraction of nodes in the largest connected component: " << (float)max_size / g.n << "\n";
    cout << "Overall time = "<< float( clock () - begin_time ) /  CLOCKS_PER_SEC <<"\n";
    return 0;
}