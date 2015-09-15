
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <math.h>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line = "63.00;89.35", cash;
    map<double,string> mapp;
    mapp[0.01] = "PENNY";
    mapp[0.05] = "NICKEL";
    mapp[0.10] = "DIME";
    mapp[0.25] = "QUARTER";
    mapp[0.50] = "HALF DOLLAR";
    mapp[1.00] = "ONE";
    mapp[2.00] = "TWO";
    mapp[5.00] = "FIVE";
    mapp[10.00] = "TEN";
    mapp[20.00] = "TWENTY";
    mapp[50.00] = "FIFTY";
    mapp[100.00] = "ONE HUNDRED";
    long double Array[12] = { 0.01, 0.05, 0.10, 0.25,0.50,1.00,2.00,5.00,10.00,20.00,50.00,100.00};
    //while (getline(stream, line)) {
        cout << line << '|';
        istringstream in(line);
        getline(in, line, ';');
        getline(in, cash);
        int format = 0;
        long double ch, pp;
        stringstream(line) >> pp;
        stringstream(cash) >> ch;
        int counter = 11;
        ch -= pp;
        if(ch < 0)
        {
            cout << "ERROR";
        }
        else if(ch == 0)
        {
            cout << "ZERO";
        }
        else{
            while(counter >= 0)
            {
                if(ch - Array[counter] >= 0.0)
                {
                    if(format == 0){cout << mapp[Array[counter]];format++;}
                    else{cout << ',' << mapp[Array[counter]];}
                    ch -= Array[counter];
                    cout << '|' << ch << '|' << ch - Array[counter];
                }
                else if(ch - Array[counter] > -0.01)
                {
                    cout << ',' << mapp[Array[counter]];
                    break;
                }
                else
                {
                    counter--;
                }
            }
        }
        cout << endl;
    //}
    return 0;
} 