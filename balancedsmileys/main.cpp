#include <stack>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
bool balance(string line)
{
    stack<int> in;
	bool flag = true;
	for(unsigned int i = 0; i < line.length(); i++)
	{
		if(line[i] == '('){in.push(1);}
		else if(line[i] == ')'){
			if(in.empty())
			{flag = false;break;}
			else{in.pop();}
		}
	}
	if(!in.empty()){flag = false;}
	return flag;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
    	if(balance(line)){cout << "YES";}
    	else{
    		for(unsigned int i = line.length() - 1; i > 0; i--)
    			if(line[i - 1] == ':' && (line[i] == '(' || line[i] == ')')){line.erase(i - 1, 2);}
    		if(balance(line)){cout << "YES";}
    		else{cout << "NO";}
    	}
    	cout << endl;
    }
    return 0;
} 
















