#include <iostream>
#include <ctime>
#include <vector>
#include "../include/bfs.hpp"
#include "../include/adjarray.hpp"

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
    bool* mark = (bool*) calloc(g.n,sizeof(bool));
    int compteur = 0;
    for(unsigned long i=0;i<g.n;i++){
        if (!mark[i]){
            bfs(g,i,mark);
            compteur ++;
        }
    }
    cout << "Nombre de cluster: " << compteur << "\n";
    cout << "Overall time = "<< float( clock () - begin_time ) /  CLOCKS_PER_SEC <<"\n";
    return 0;
}