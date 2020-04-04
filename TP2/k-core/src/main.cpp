#include "../include/Kcore.h"
#include "../include/AdjacencyList.h"

using namespace std;

int main()
{
	Kcore K("../graph/ID.txt", "../graph/net.txt");
	K.algorithm();
	for (auto &x: K.kcore_map)
	{
		cout << "k = " << x.first << endl;
		for (int node : x.second)
		{
			cout << node << "; ";
		}
		cout << endl;
	}
	return 0;
}
