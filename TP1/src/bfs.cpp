#include <iostream>
#include <ctime>
#include <queue>
#include "../include/adjmatrix.hpp"

void bfs(const Adjmatrix& graph, const unsigned long & node,bool* mark){
    queue<unsigned long> fifo;
    fifo.push(node);
    mark[node] = 1;
    while(!fifo.empty()){
        unsigned long u = fifo.front();
        fifo.pop();
        for(unsigned long i=0;i<graph.n;i++){
            if(graph.mat[u+graph.n*i]){
                if (!mark[i]){
                    fifo.push(i);
                    mark[i] = 1;  
                }               
            };
        }
    }
}

int main(int argc, char** argv){
    if (argv[1]==NULL){
        cout << "Enter file name\n";
        return 0;
    }
    Adjmatrix g;
    const clock_t begin_time = clock();
    cout << "Reading edgelist from file "<<argv[1]<<"\n";
    g = read_adj_matrix(argv[1]);
    cout << "Number of nodes: " << g.n << "\n";
    cout << "Number of edges: " << g.e << "\n";
    cout << "Building adjacency list\n";
    mkadjmatrix(g);
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