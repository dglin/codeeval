
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line, right;
    while (getline(stream, line)) {
        int Array[256] = { 0 };
        cout << line << '|';
        string Array2[50];
        //map<int,string> mapp;
        istringstream in(line);
        getline(in, line, ';');
        int i = 0;
        while(getline(in,right,','))
        {
            Array2[i] = right;
            i++;
        }
        
        
        
        for(int y = 0; y < i; y += 2)
        {
            for(unsigned int j = 0; j < line.length(); j++)
            {
                if(line[j] == Array2[y][0] && Array[j] != 1)
                {
                    if(line.substr(j,Array2[y].length() - 1) == Array2[y])
                    {
                        //mapp[j] = Array2[y];
                        
                        for(unsigned int u = j; u < j + Array2[y].length() + 1; u++){
                            Array[u] = 1;
                        }
                        line = line.substr(0,j) + Array2[y + 1] + line.substr(j + Array2[y].length(),line.length() - j);
                    }
                }
            }
        }
        
        // map<int,string>::iterator ptr;
        // for(ptr = mapp.begin(); ptr != mapp.end(); ptr++)
        // {
        //     cout << ptr->second;
        // }
        cout << line;
        
        cout << endl;
        
        
    }
    return 0;
} 