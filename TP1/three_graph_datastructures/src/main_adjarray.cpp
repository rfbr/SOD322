#include <ctime>
#include <iostream>
#include "../include/adjarray.hpp"

using namespace std;

int main(int argc, char **argv)
{
    if (argv[1] == NULL)
    {
        cout << "Enter file name\n";
        return 0;
    }
    Adjarray g;
    const clock_t begin_time = clock();
    cout << "Reading edgelist from file " << argv[1] << "\n";
    g = read_adj_array(argv[1]);
    cout << "Number of nodes: " << g.n << "\n";
    cout << "Number of edges: " << g.e << "\n";
    cout << "Building adjacency array...\n";
    mkadjarray(g);
    cout << "Overall time = " << float(clock() - begin_time) / CLOCKS_PER_SEC << "\n";
    return 0;
}