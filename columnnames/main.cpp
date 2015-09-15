
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        int val, temp1, temp2, temp3; // the digits of the number
        stringstream(line) >> val;
        if(val <= 26)
        {
        	cout << (char)(val + 64);    // if lucky case only 1 digit
        }
        else if(val <= 702 && val > 26)         //two digits, not as conclusive
        {
        	temp1 = (val - 1) / 26 + 64;
        	temp2 = (val - 1) % 26 + 65;
        	cout << (char) temp1 << (char) temp2;
        }
        else
        {
        	temp1 = val / 676;         //the first value
            val -= temp1 * 676;     //adjust value, the base nuber, for convenience sake
        	temp2 = val /26;
            if(temp2 == 0)          //shitty case that val < 26, which requires wrap around due to zero index
            {
                temp1 -= 1;
                temp2 = 26;
            }
            temp3 = val % 26;       //last case, also requires wrap around
        	if(temp3 == 0)
            {
                temp2 -= 1;
                temp3 = 26;
            }
            temp1 += 64;            //adjustment for ascii
            temp2 += 64;
            temp3 += 64;
        	cout << (char) temp1 << (char) temp2 << (char) temp3;
        }
        cout << endl;
    }
    return 0;
} 