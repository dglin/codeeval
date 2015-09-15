#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;

// 0 can be a sequence A's, 1 can be a sequence of A's or B's. Trying to 
//figure out if the sequence of A and B's on right fits the binary on left.


int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line = "01001110 AAAABAAABBBBBBAAAAAAA", right;
    //while (getline(stream, line)) {
        istringstream in(line);
        getline(in, line, ' ');
        getline(in, right);
        //unsigned int j = 0;
        //bool flag = true;
        string regex = "";
        string Array[2] = {"A+", "(A+|B+)"};
        for(unsigned int i = 0; i < line.length(); i++)
        {
            if(line[i] == '1')
            {
                regex += Array[1];
                // for(; j < right.length(); j++)
                // {
                //     if(j > 0)
                //         if(right[j] != right[j + 1]){j++;break;}
                // }
            }
            else if(line[i] == '0')
            {
                regex += Array[0];
                // if(right[j] != 'A'){cout << j << i;flag = false; break;}
                // for(; j < right.length(); j++)
                // {
                //     if(right[j] != 'A'){break;}
                // }
            }
        }
        // if(flag){cout << "Yes";}
        // else{cout << "No";}
        string final;
        regex_match(right,regex) ? final = "Yes" : final = "No";
        cout << final << endl;
        //cout << regex << endl;
    //}
    return 0;
}