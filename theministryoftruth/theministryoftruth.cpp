#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream stream(argv[1]);
	string line, right;
	while(getline(stream, line))
	{
		//cout << line << '|';
		vector<string> lineV;
		vector<string> rightV;
		istringstream in(line);
		getline(in, line, ';');
		getline(in, right);

		istringstream in2(line);
		istringstream in3(right);
		string temp;
		while(in2 >> temp){lineV.push_back(temp);}
		while(in3 >> temp){rightV.push_back(temp);}
		unsigned int counter = 0, counter2 = 0;
		bool flag2 = true, flag3 = true;
		string final;
		if(rightV.empty()){
			for(unsigned int k = 0; k < lineV.size(); k++){
				for(unsigned int l = 0; l < lineV[k].length();l++){
					cout << '_';
				}
				cout << ' ';
			}
			cout << endl;
			continue;
		}
		//int blah = 0;
		for(unsigned int i = 0; i < lineV.size(); i++){
			flag3 = true;
			//blah = 0;
			for(unsigned int k = 0; k < lineV[i].length(); k++)
			{
				if(lineV[i][k] == rightV[counter][0] && flag3)
				{
					bool flag = true;
					for(unsigned int r = 0; r < rightV[counter].length();r++)
					{
						if(lineV[i][k + r] != rightV[counter][r])
						{
							flag = false;break;
						}
					}
					if (flag && flag2){
						temp = lineV[i].substr(k, rightV[counter].length());
						//cout << temp;
						final += temp;
						k += temp.length() - 1;
						flag3 = false;
						//blah++;
						//if(k + temp.length() < lineV[i].length())
						//	{k += temp.length() < lineV[i].length();}
						if(rightV.size() - 1 > counter){counter++;}
						else{flag2 = false;}
						counter2++;
					}
					else{
						//cout << '_';
						final += '_';
					}
				}
				else{
					//cout << lineV[i][k];
					final += '_';
					//cout << '_';
					flag3 = true;
				}
			}
			//if ( blah > 1){
			//	break;
			//}
			//cout << ' ';
			final += ' ';
		}
		//cout << final << ' ' << rightV.size() << ' ' << counter << ' ' << counter2;// << endl;
		if(counter2 < rightV.size()){cout << "I cannot fix history";}
		else{cout << final;}
		cout << endl;
	}
}