#include <sstream>
#include <utility>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b)		//helper function for sort
{												//so that the sort is based on first val
	return(b.first > a.first);					//of the pair
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
    	int Array[15][15];						//2 d array to store the original
        istringstream in(line);					//matrix
		int i = 0;
		vector<pair<int,int> > V;				//create a vector of pairs, to hold the row
        while(getline(in, line, '|'))
        {
        	istringstream in2(line);
        	int j = 0, temp;
        	while(in2 >> temp){					//fill 2d array
        		if(i == 0){
        			pair<int, int> temp2 (temp, j);		//if first row, fill vector
        			V.push_back(temp2);
        		}
        		Array[i][j] = temp;
        		j++;
        	}
        	i++;
        }
        sort(V.begin(), V.end(), comp);	//sort vector

        for(int k = 0; k < i; k++){				//loop throw matrix and print, using 
        	for(int y = 0; y < i; y++)			//column indices based on vector sorted by
        		cout << Array[k][V[y].second] << ' ';		//vfirst
        	if(k != i - 1){cout << '|' << ' ';}		//formatting toget rid of last pipe
        }

        cout << endl;
    }
    return 0;
} 