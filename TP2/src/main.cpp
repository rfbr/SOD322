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
	PageRank p("../graph/alr21--pageNum2Name--enwiki-20071018.txt", "../graph/alr21--dirLinks--enwiki-20071018.txt", 0.2);
	p.powerIteration(3);
	return 0;
}