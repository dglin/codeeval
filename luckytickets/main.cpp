// #include <cmath>
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <cstring>
// using namespace std;
// int main(int argc, char *argv[]) {
//     ifstream stream(argv[1]);
//     string line = "4";
//     int lucky = 0;
    //while (getline(stream, line)) {
        // int val;
        // stringstream(line) >> val;
        // for(int i = 0; i < pow(10,val); i++)
        // {
        //     string temp;
        //     stringstream ss;
        //     ss << i;
        //     ss >> temp;
        //     int a = temp.length(); // .length() is an unsigned int
        //     //cout << temp.substr(0, a / 2) << '|' << temp.substr(a / 2,a / 2) << endl;
        //     string lefty = temp.substr(0, a / 2), righty = temp.substr(a / 2, a / 2);
        //     int left = 0, right = 0;
        //     for(unsigned int i = 0; i < lefty.length(); i++)
        //     {
        //         left += lefty[i] - '0';
        //     }
        //     for(unsigned int i = 0; i < righty.length(); i++)
        //     {
        //         right += righty[i] - '0';
        //     }
        //     if(left == right)
        //     {
        //         lucky++;
        //     }
        // }
        // cout << lucky << endl;
        // lucky = 0;
    //}
//     return 0;
// }
#include <cmath>
#include <sstream>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;



int factorial(int number) {
    int temp;

    if(number <= 1) return 1;

    temp = number * factorial(number - 1);
    return temp;
}

int comb(int n, int k)
{
    return (int)(factorial(n) / (factorial(k) * factorial(n - k)));
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        int val;
        stringstream(line) >> val;
        int sum = 0;
        for(unsigned int i = 0; i < (int)floor(((9 * val) / 20) + 1); i++)
        {
            sum += ((int)pow(-1, i) * comb(val,i) * 
            comb( val + (int)floor( 9 * val / 2) - 10 * i - 1, val - 1));
        }
        cout << sum << endl;

    }
    return 0;
} 