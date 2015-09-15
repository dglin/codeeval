#include <utility>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
bool comp(pair<unsigned int, string> a, pair<unsigned int, string> b){return a.first > b.first;}
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    vector<pair<unsigned int, string> > V;
    getline(stream, line);
    int num;
    stringstream ss(line);
    ss >> num;
    while (getline(stream, line)) {
    	pair<unsigned int, string> temp(line.length(), line);
    	V.push_back(temp);
    }
    sort(V.begin(), V.end(), comp);
	for(int i = 0; i < num; i++)
    	cout << V[i].second << endl;
    return 0;
} 