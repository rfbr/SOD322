#include <queue>
#include "../include/graph.hpp"
using namespace std;

void bfs(Graph graph, unsigned long node){
    queue<unsigned long> fifo;
    unsigned long u;
    fifo.push(node);
    while(!fifo.empty()){
        u = fifo.front();
        fifo.pop();
        //mark(s)
        vector<unsigned long> adj = graph.adj_list;
        int n = adj.size();
        for(int i=0;i<n;i++){
            unsigned long v = graph.adj_list[i];
            //if v not marked then
                //fifo.push(v);
                //mark(v);   
        }
    }
}