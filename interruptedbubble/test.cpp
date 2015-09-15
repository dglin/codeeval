
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        //cout << line << '|';
        vector<int> myV;
        istringstream in(line);
        getline(in, line, '|');
        istringstream in2(line);
        while(in2 >> line)
        {
            int temp;
            stringstream(line) >> temp;
            myV.push_back(temp);
           // cout << temp << ' ';
        }
        getline(in, line, ' ');
        getline(in, line);
        int temp;
        stringstream(line) >> temp;
        //cout << temp;
        //int j = 0;
        // while(j < temp)
        // {
        //     for(int i = 0; i < myV.size() - 1; i++)
        //     {
        //         if(myV[i] > myV[i + 1])
        //         {
        //             temp = myV[i];
        //             myV[i] = myV[i + 1];
        //             myV[i + 1] = temp;
        //         }
        //     }
        //     j++;
        // }
        if(myV.size() > 1 && temp <= myV.size())
        {
            for (int k = 0; k < temp; k++)
                for (unsigned int i = 0; i < myV.size() -1; i++)
                        if (myV[i] > myV[i + 1]){
                            int temp2 = myV[i];
                            myV[i] = myV[i + 1];
                            myV[i + 1] = temp2;
                        }
        }
        for(unsigned int i = 0; i < myV.size(); i++){cout << myV[i] << ' ';}
        
        cout << endl;
    }
    return 0;
} 