#include <ctime>
#include <iostream>
#include "../include/edgelist.hpp"

using namespace std;

int main(int argc, char **argv)
{
    if (argv[1] == NULL)
    {
        cout << "Enter file name\n";
        return 0;
    }
    Edgelist g;
    const clock_t begin_time = clock();
    cout << "Building edgelist from file..." << argv[1] << "\n";
    g = read_edge_list(argv[1]);
    cout << "Number of nodes: " << g.n << "\n";
    cout << "Number of edges: " << g.e << "\n";
    cout << "Overall time = " << float(clock() - begin_time) / CLOCKS_PER_SEC << "\n";
    return 0;
}