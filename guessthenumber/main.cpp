#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        istringstream in(line);
        float num;
        in >> num;					//get first int, the number
        float middle = ceil(num / 2);		//first choice, half the number rounded up
        float higher = num, lower = 0;		//the bounds
        while(in >> line)
        {
        	if(line[0] == 'L')				// if lower, the new higher bound was old middle - 1
        	{
        		higher = middle - 1;
        		middle = lower + ceil((higher - lower) / 2);
        	}
        	else if(line[0] == 'H'){	//if higher the new lower bound was old middle + 1
        		lower = middle + 1;
        		middle = lower + ceil ((higher - lower) / 2);
        	}
        	else{
        		cout << middle << endl; // if now lower or higher must be Yay!
        	}
        }

    }
    return 0;
} 