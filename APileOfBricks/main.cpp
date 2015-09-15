#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    char chars[] = "[]()";
    while (getline(stream, line)) {
        int Array[15] = { 0 };
        int index;
        istringstream in(line);
        getline(in, line, '|');
        for (unsigned int i = 0 ; i < strlen(chars); ++i) // remove shit for formatting
        {
            line.erase(remove(line.begin(), line.end(), chars[i]), line.end());
        }
        int big, small, temp;               //parse the hole size
        istringstream in2(line);
        getline(in2, line, ',');
        stringstream(line) >> small;
        getline(in2, line, ' ');
        stringstream(line) >> big;
        getline(in2, line, ',');
        stringstream(line) >> temp;
        small = abs(small - temp);
        getline(in2, line);
        stringstream(line) >> temp;
        big = abs(big - temp);
        if(small > big){ temp = big; big = small; small = temp;} //arrage hole by length.
        int x,y,z,counter = 0;                                  // removes case where
        getline(in, line, ';');                                 //llengths of bricks
        do                                                      //different fit
        {                                                       //probably not necessary
            for (unsigned int i = 0 ; i < strlen(chars); ++i)
            {
                line.erase(remove(line.begin(), line.end(), chars[i]), line.end());
            }
            istringstream in3(line);            // all this to parse the bricks
            getline(in3, line, ' ');            // need the temp to combine x,y,z
            stringstream(line) >> index;
            getline(in3, line, ',');
            stringstream(line) >> x;
            getline(in3, line, ',');
            stringstream(line) >> y;
            getline(in3, line, ' ');
            stringstream(line) >> z;
            getline(in3, line, ',');
            stringstream(line) >> temp;
            x = abs(x - temp);
            getline(in3, line, ',');
            stringstream(line) >> temp;
            y = abs(y - temp);
            getline(in3, line);
            stringstream(line) >> temp;
            z = abs(z - temp);
            if((x <= small && y <= big) || (x <= big && y <= small)){
                // if(counter == 0){cout << index;}
                // else{cout << ',' << index;} 
                Array[counter] = index;        // check if bricks will pass through
                counter++;                          // the whole
                continue;
                
            }
            if((z <= small && x <= big) || (z <= big && x <= small)){
                // if(counter == 0){cout << index;}
                // else{cout << ',' << index;}
                Array[counter] = index;
                counter++;                          //bricks are 3D thus need 3 cases
                continue;
                
            }
            if((z <= small && y <= big) || (z <= big && y <= small)){
                // if(counter == 0){cout << index;}
                // else{cout << ',' << index;}
                Array[counter] = index;
                counter++;
                continue; // just in case two planes could make it though
            }
            
        }while(getline(in, line,';'));
        qsort(Array, counter, sizeof(int), compare);

        for(int i = 0; i < counter; i++){
            if(i == 0){cout << Array[i];}
            else{cout << ',' << Array[i];}
        }

        if(counter == 0){cout << '-';}
        cout << endl;
    }
    return 0;
} 