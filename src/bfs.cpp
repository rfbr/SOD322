#include <queue>
#include "../include/adjarray.hpp"
using namespace std;

int bfs(const Adjlist& graph, const unsigned long & node,bool* mark){
    queue<unsigned long> fifo;
    fifo.push(node);
    mark[node] = 1;
    int compteur = 1;
    while(!fifo.empty()){
        fifo.pop();
        for(unsigned long i=0;i<graph.n;i++){
            unsigned long v = graph.adj[i];
            if (!mark[v]){
                fifo.push(v);
                mark[v] = 1;  
                compteur ++;
            }               
        }
    }
    return compteur;
}