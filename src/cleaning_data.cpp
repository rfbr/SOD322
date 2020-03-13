#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc,char** argv){
    string temp = "awk '{if ($1<$2) print $1" "$2;else if ($2<$1) print $2" "$1}' ";
    temp += argv[1];
    temp += " | sort -n -k1,2 -u > ";
    temp += argv[2];
    char script[temp.size()+1];
    strcpy(script,temp.c_str());
    system(script);
    return 0;
}