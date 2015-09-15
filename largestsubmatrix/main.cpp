#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    register int myArray[20][20] = { 0 };
    register int i = 0;
    while (getline(stream, line)) {         //fill the 2d array

        istringstream in(line);
        register int temp, j = 0;
        while(in >> temp)
        {
        	myArray[i][j] = temp;
        	j++;
        }
        i++;
    }

    register int X = 1, Y = 1, final = -100;
    do{
	    for(register int i = 0; i < 20; i++)   //loop through
	    {                                   //every element in the array
	    	for(register int j = 0; j < 20; j++)     //here
	    	{
	    		
	    		
	    		
	    		register int sum = 0;                        //here, create a submatrix
	    		for(register int y = i; y < i + Y; y++)      //based on values X or Y
	    		{                                   //if out of bound break
	    			if(y > 19){break;}              // add sub matrices register into sum, and 
	    			for(register int x = j; x < j + X; x++)  //compare sum
	    			{
	    				if(x > 19){break;}
	    				sum += myArray[y][x];
	    			}
	    		}
	    		if(sum > final){final  = sum;}

	    	}
	    }

	    if(X == 20)//increment X and Y to cover every possible sub matrix dimension
	    {
	    	X = 1;
	    	Y++;
	    }
	    else{
	    	X++;
	    }

	}while(X <= 20 && Y <= 20);
	cout << final << endl;
    return 0;
} 