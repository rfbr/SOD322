#ifndef DEF_KCORE
#define DEF_KCORE

#include <iostream> 
#include <string>
#include <cmath> 
#include <vector> 
#include <stdlib.h>
#include <fstream>
#include <map>
#include <chrono>
#include <ctime>
#include <bits/stdc++.h>

#include "../include/AdjacencyList.h"

using namespace std;

class Kcore
{	
	public:

	Kcore(string);
	~Kcore();

	void algorithm();

	unordered_map<int, vector<int> > kcore_unordered_map;

	private:

	AdjacencyList G;

	pair<int,int> findMinimum(); 

};


#endif
