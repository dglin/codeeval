
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
//#include <cmath>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

vector< pair<int, int> > zipper(vector<int> V1, vector<int> V2, int l)
{
    vector< pair<int, int> > temp(l);			//zip function
    for (int i = 0; i < l; ++i)					//probably could use map but fuck it
        temp[i] = pair<int, int>(V1[i], V2[i]);
    return temp;
}


int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line, right;
    while (getline(stream, line)) {
        istringstream in(line);
        getline(in, line, ' ');
        getline(in, right);

        replace(line.begin(), line.end(), ',', ' ');  //get rid of useless chars to use the
        replace(right.begin(), right.end(), ',', ' ');	//extraction operator
        line = line.substr(1, line.length() - 2);
        right = right.substr(1, right.length() - 2);

        istringstream in2(line);
        istringstream in3(right);

        vector<int> street;
        vector<int> avenue;
        double bufferS, bufferA;
        while(in2 >> line)			//fill street vector
        {
    		int temp;
        	stringstream(line) >> temp;
        	street.push_back(temp);
        	bufferS = temp;
        }
        while(in3 >> right)		//fill avenue vector
        {
    		int temp;
        	stringstream(right) >> temp;
        	avenue.push_back(temp);
        	bufferA = temp;
        }

        vector<int> street2(street.begin() + 1, street.end());	//create new offset vectors
        vector<int> avenue2(avenue.begin() + 1, avenue.end());
        

        vector< pair<int, int> > X = zipper(street, street2, street2.size());
        vector< pair<int, int> > Y = zipper(avenue, avenue2, avenue2.size());


        double slope = bufferA / bufferS;  // y = mx, where m =  slope, aka last street/ last
        int final = 0;
		for (int i = 0; i < X.size(); ++i)
		    for (int j = 0; j < Y.size(); ++j)
		        if (!((slope * X[i].first >= Y[j].second) || (slope * X[i].second <= Y[j].first)))
		            final++;	//check if in a box, double * int == double
        cout << final << endl;
    }
    return 0;
} 