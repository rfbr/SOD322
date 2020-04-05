#include "../include/Kcore.h"
#include "../include/AdjacencyList.h"
#include<fstream>

using namespace std;

int main(int argc,char** argv)
{
    if (argv[1]==NULL){
    cout << "Enter file name\n";
    return -1;
    }

	Kcore K(argv[1]);
	K.algorithm();
	string tmp(argv[1]);
	ofstream results("results_" + tmp);
	for (auto &x: K.kcore_unordered_map)
	{
		results << "k = " << x.first << endl;
		for (int node : x.second)
		{
			results << node << "; ";
		}
		results << endl;
	}
	return 0;
}
