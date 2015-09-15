#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line, right;
    while (getline(stream, line)) {
        istringstream in(line);
        getline(in, line, ',');
        getline(in, right);
        int Array[256] = { 0 };
        int counter = 1;
        for(unsigned int i = 0; i < line.length(); i++)
        {
        	if(line[i] == right[0])
        	{
        		bool flag = false;
        		for(unsigned int j = i + 1; j < line.length(); j++)
        		{
        			if(j == line.length()){flag = true;break;}
        			if(line[j] != right[j - i])
        			{
        				continue;
        			}

        		}
        	}
        }
        cout << line << endl;
    }
    return 0;
} 