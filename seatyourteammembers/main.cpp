#include <sstream>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    char chars[] = ";,";
    map<int, vector<int> > megamap;
    int num;
    while (getline(stream, line)) {
    	for(int i = 0; i < 2; i++)
    		line.erase(remove(line.begin(), line.end(), chars[i]), line.end());
    	replace(line.begin(), line.end(), ':', ' ');
    	replace(line.begin(), line.end(), ']', '}');
    	replace(line.begin(), line.end(), '[', '|');
    	istringstream in2(line);
    	getline(in2, line, ' ');
    	int num; stringstream ss(line); ss >> num;
    	getline(in2, line);
    	istringstream in(line);
    	int counter = 1;
    	while(getline(in, line, '}'))
    	{
    		stringstream in3(line);
    		getline(in3,line, '|'); // getting rid of useless index! cna incremenet a counter
	    	getline(in3,line);
	    	istringstream intoo(line);
	    	int temp;
	    	vector<int> tempV; 
	    	while(intoo >> temp){tempV.push_back(temp);}
	    	megamap[counter] = tempV;
	    	
	    	counter++;
    	}
        megamap.clear();
        int Hash[51] = { 0 };
        bool flag;
        for(int i = 1; i < num + 1; i++)
        {
        	for(int j = 1; j < num; j++)
        	{
        		cout << megamap[j].size();
        		if(megamap[j].size() == i)
        		{
        			cout << i;
        			bool flag2 = false;
        			for(int k = 0; k < i; k++)
        			{
        				if(Hash[megamap[j][k]] !=  1)
        					{Hash[megamap[j][k]] = 1; flag2 = true; break;}
        			}
        			if(flag2){cout << "No"; break;}
        			flag = flag2;
        		}
        	}
        }
        if(!flag){cout << "Yes";}
        cout << endl;
    }
    return 0;
} 