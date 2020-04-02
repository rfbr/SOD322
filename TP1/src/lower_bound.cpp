#include <iostream>
#include <ctime>
#include <queue>
#include<iterator>
#include<list>
#include "../include/adjlist.hpp"
using namespace std;

unsigned long bfs_lower_bound(Adjlist& graph, unsigned long & node){
    bool* mark = (bool*) calloc(graph.n,sizeof(bool));
    queue<unsigned long> fifo;
    fifo.push(node);
    mark[node] = 1;
    unsigned long u;
    unsigned long distance = 0;
    bool new_layer = true;
    while(!fifo.empty()){
        u = fifo.front();
        fifo.pop();
        list<unsigned long> :: iterator it;
        for(it = graph.adj[u].begin(); it != graph.adj[u].end(); ++it){
            cout << *it << " ";
            if(!mark[*it]){
                if (new_layer) distance ++;
                new_layer = false;
                fifo.push(*it);
                mark[*it] = 1; 
            }
        }
        new_layer = true;
    }
    node = u;
    return distance;
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
    cout << "Computing lower bound estimation...\n";
    unsigned long found_diameter;
    unsigned long lower_bound = 0;
    for(int i=0;i<100;i++){
        unsigned long rand_node = rand()%g.n;
        bfs_lower_bound(g,rand_node);
        found_diameter = bfs_lower_bound(g,rand_node);
        lower_bound = max(lower_bound,found_diameter);
        }
    cout << "Lower bound of the diameter of the graph: " << lower_bound << "\n";
    cout << "Overall time = "<< float( clock () - begin_time ) /  CLOCKS_PER_SEC <<"\n";
    return 0;
}