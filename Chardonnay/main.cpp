#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line, num;
    while (getline(stream, line)) {
        istringstream in(line);
        getline(in, line, '|');
        getline(in, num);
        istringstream in2(line);
        int Array2[256] = { 0 };
        for(unsigned int j = 1; j < num.length(); j++)
        {
        	Array2[num[j] - '0']++;
        }
        int counter = 0;
        while(in2 >> line)
        {
            cout << num;
            int Array[256] = { 0 };
        	for(unsigned int i = 0; i < line.length(); i++)
        	{
        		Array[line[i] - '0']++;
        	}
        	bool flag = true;
        	for(unsigned int k = 1; k < num.length(); k++)
        	{
        		if(Array[num[k] - '0'] != Array2[num[k] - '0']){
        			flag = false; 
                    break;
                }
        	}
        	if(flag){cout << line << ' ';counter++;}
        }
        if(counter == 0){cout << "False";}
        cout << endl;
    }
    return 0;
} 