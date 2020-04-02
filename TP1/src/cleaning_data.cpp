#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc,char** argv){
    if ((argv[1]==NULL) | (argv[2]==NULL)){
        cout << "Enter file name\n";
        return 0;
    }
    string temp = "awk '{if ($1<$2) print $1\" \"$2;else if ($2<$1) print $2\" \"$1}' ";
    temp += argv[1];
    temp += " | sort -n -k1 -k2 -u > ";
    temp += argv[2];
    char script[temp.size()+1];
    strcpy(script,temp.c_str());
    system(script);
    return 0;
}