#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <cmath>
#include "../include/edge.hpp"

using namespace std;


int main(int argc, char** argv){
    if (argv[1]==NULL){
        cout << "Enter file name\n";
        return 0;
    }
    Edgelist e_list;
    const clock_t begin_time = clock();
    cout<<"Reading edgelist from file "<<argv[1]<<"\n";
    e_list = read_edge_list(argv[1]);
    cout << "Number of nodes: " << e_list.n <<"\n";
    cout << "Number of edges: " << e_list.e <<"\n";
    cout << "Overall time = "<< float( clock () - begin_time ) /  CLOCKS_PER_SEC <<"\n";
    return 0;
}   

