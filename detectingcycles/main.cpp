#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        int ArrayH[256] = { 0 };			//hare places
        int ArrayT[256] = { 0 };			//turtle places
        vector<int> myV;					//could be done with 1 array but got lazy
        istringstream in(line);
        while(in >> line)
        {
        	int temp;
        	stringstream(line) >> temp;
        	myV.push_back(temp);
        }									//fill vector or sequence/list
        bool flag = false;							//again got lazy
        int i = 0, steps = 0, limit = 1;	//tortoise and the hair, upgraded
        while(true)						//limit is equal to one! shitty case they just have a repeat at end of the lisrt
        {
        	if(i == myV.size() - 1){break;} // at the end?
        	ArrayH[myV[i]] = 1; // move rabbit
        	steps ++;//count steps
        	if(ArrayT[myV[i]] == 1){flag = true; break;} // if rabbit = turtle!
        	if(steps == limit)// if reached steps
        	{
        		steps = 0; // reset steps
        		ArrayT[myV[i]] = 1; // teleport turtle, in this case increment turtle
        	}
        	i++;
        }
        int done = myV[i];
        do{ // print the sequence
        	cout << myV[i] << ' ';
        }while(done != myV[++i]);
        cout << endl;
    }
    return 0;
}