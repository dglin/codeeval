#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int countZero(vector<int> myVector);

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
    	vector<int> myV;
        istringstream in(line);
        while(getline(in, line, ','))
        {
        	int temp;
        	stringstream(line) >> temp;
        	myV.push_back(temp);
        }
        cout << countZero(myV) << endl;
    }
    return 0;
} 



int countZero(vector<int> myVector)
{
	int count  = 0;
	for (unsigned int i = 0; i < myVector.size(); i++)
	for (unsigned int j = i + 1; j < myVector.size(); j++)
	for (unsigned int k = j + 1; k < myVector.size(); k++)
	for (unsigned int l = k + 1; l < myVector.size(); l++)
	//for (unsigned int m = l + 1; m < myVector.size(); m++)
	if(myVector[i] + myVector[j] + myVector[k] + 
	myVector[l] == 0){count ++;}


	return count;
}