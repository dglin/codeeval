#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line, buffer = " ";
    while (getline(stream, line)) {         //fill the 2d array
    	register int Array[25][25] = { 0 };
    	line = buffer + line;
		istringstream in(line);
		int i = 0;
        while(getline(in, line, '|'))
        {
        	for(int j = 1; line[j] != ' '; j++)
        	{
        		Array[i][j - 1] = line[j] - '0';
        	}
        	i++;
        }

        // for(int k = 0; k < i; k++){
        // 	for(int y = 0; y < i; y++)
        // 		cout << Array[k][y] << ' ';
        // 	cout << '|';
        // }
	    register int X = 1, final = 10000;
	    do{
	    	bool flag = true;
		    for(register int z = 0; z < i - (X - 1); z++)   //loop through
		    {
		    	bool flag2 = true;                                   //every element in the array
		    	for(register int j = 0; j < i - (X - 1); j++)     //here
		    	{
		    		register int sum = 0;                        //here, create a submatrix
		    		for(register int y = z; y < z + X; y++)      //based on values X or Y
		    		{                                   //if out of bound break
		    			if(y > 24){break;}              // add sub matrices register into sum, and 
		    			for(register int x = j; x < j + X; x++)  //compare sum
		    			{
		    				if(x > 24){break;}
		    				if(Array[y][x] == 1){sum++;};
		    			}
		    		}
		    		if(sum != final && !(z == 0 && j == 0)){flag = false; flag2 = false;}
		    		final = sum;
		    	}
		    	if(!flag2){break;}
		    }
		    if(flag)
		    {
		    	break;
		    }

		    X++;

		}while(X <= i);
		printf("%ix%i, %i",X, X, final);
		cout << endl;
	}
    return 0;
} 