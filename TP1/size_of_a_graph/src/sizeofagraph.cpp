#include <iostream>
#include <ctime>
#include <fstream>
#include <set>

using namespace std;

int main(int argc, char **argv)
{
    if (argv[1] == NULL)
    {
        cout << "Enter file name\n";
        return 0;
    }
    unsigned long e = 0, node_1, node_2;
    set<unsigned long> nodes;
    const clock_t begin_time = clock();
    cout << "Reading edgelist from file " << argv[1] << "\n";

    ifstream graph_file(argv[1]);
    while (graph_file >> node_1 >> node_2)
    {
        nodes.insert(node_1);
        nodes.insert(node_2);
        ++e;
    }
    cout << "Number of nodes: " << nodes.size() << "\n";
    cout << "Number of edges: " << e << "\n";
    cout << "Overall time = " << float(clock() - begin_time) / CLOCKS_PER_SEC << "\n";
    return 0;
}