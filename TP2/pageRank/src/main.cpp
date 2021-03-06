#include <iostream> 
#include <string>
#include <cmath> 
#include <vector> 
#include <stdlib.h>
#include <fstream>

#include "../include/TransitionMatrix.h"
#include "../include/PageRank.h"

using namespace std;





int main()
{
	// TransitionMatrix T("alr21--pageNum2Name--enwiki-20071018.txt", "alr21--dirLinks--enwiki-20071018.txt");
	cout << "PageRank algorithm on Wikipedia dataset... " << endl;
	PageRank p("../graph/alr21--pageNum2Name--enwiki-20071018.txt", "../graph/clean-alr21--dirLinks--enwiki-20071018.txt", 0.15);
	p.powerIteration(20);
	ofstream result("results-0.15.txt");
	for (int i = 0; i < p.page_rank_vec.size(); i++)
	{
		result << p.page_rank_vec[i] << endl;
	}
	return 0;
}
