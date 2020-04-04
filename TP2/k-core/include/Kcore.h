#ifndef DEF_KCORE
#define DEF_KCORE

#include <iostream> 
#include <string>
#include <cmath> 
#include <vector> 
#include <stdlib.h>
#include <fstream>
#include <map>

#include "AdjacencyList.h"

using namespace std;

class Kcore
{	
	public:

	Kcore(string, string);
	~Kcore();

	void algorithm();

	map<int, vector<int> > kcore_map;

	private:

	AdjacencyList G;

	vector<int> findMinimum(); 
};

#endif