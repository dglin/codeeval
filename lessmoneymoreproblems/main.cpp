#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    int c, v;
    vector<int> myV;
    while (getline(stream, line)) {
    	line.erase(remove(line.begin(), line.end(), '|'), line.end());
    	istringstream in(line);
    	in >> c; in >> v;
    	cout << c << v;
    	int temp;
    	while(in >> temp)
    	{
    		myV.push_back(temp);
    		cout << temp;
    	}

    	for(int i = v; i >= 1; i++)
    	{

    	}
        cout << endl;
    }
    return 0;
} 