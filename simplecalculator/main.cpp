#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctype>
#include <vector>
using namespace std;

int Evaluate(string line)
{
	string temp, line1;
	int sum = 0;
	vector<int> values;
	vector<char> operators;
	for(unsigned int i = 0; i < line.length(); i++)
	{
		if(line[i] == '(')
		{
			for(unsigned int j = i + 1; line[j] != ')'; j++){}
			temp = line.substr(i + 1, j - (i + 1));
			int temp1 = Evaluate(temp);
			stringstream ss;
			ss << temp1;
			temp = ss.str();
			line = line.substr()
		}

	}
	istringstream in(line);
	while(getline(in, line, ' '))
	{
		if(line == "*" || line == "/" || line == "+" || line == "-")
		{
			operators.push_back(line[0]);
		}
		else
		{
			int temp2;
			stringstream(line) >> temp2;
			values.push_back(temp2); 
		}
	}

	for(unsigned int k = 0; k < operators.size() - 1; k += 1)
	{

	}

}


int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
    	cout << Evaluate(line) << endl;
    }
    return 0;
} 