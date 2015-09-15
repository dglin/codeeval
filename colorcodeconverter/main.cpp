#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

void CMYK(string line)			//rather simple formula
{
	float c,y,m,k,r,g,b;
	line.erase(0, 1); line.erase(line.length() - 1, 1); // remove parenthesis, and replace
	replace(line.begin(), line.end(),',',' ');				//commas with spaces so can use
	istringstream in(line);								//extraction operator
	in >> c; in >> y; in >> m; in >> k;
	r = 255 * (1 - c) * (1 - k);
	g = 255 * (1 - y) * (1 - k);
	b = 255 * (1 - m) * (1 - k);
	printf("RGB(%i,%i,%i)", (int)round(r), (int)round(g), (int)round(b));
}

void hex(string line)			//simple converts hex to dec, two digits at a time
{
	int r, g, b;
	stringstream in, in2, in3;
	in << hex << line.substr(1,2);
	in >> r;
	in2 << hex << line.substr(3,2);
	in2 >> g;
	in3 << hex << line.substr(5,2);
	in3 >> b;
	printf("RGB(%i,%i,%i)", r, g, b);
}

void HSL(string line)		//rather complicated formula
{
	float h, s, l, c, x, m, r, g, b;
	line.erase(0, 4); line.erase(line.length() - 1, 1);
	replace(line.begin(), line.end(),',',' ');
	istringstream in(line);
	in >> h; in >> s; in >> l;
	h /= 60;s /= 100; l /= 100;
	c = (1 - abs( 2 * l - 1)) * s;
	x = c * (1 - abs((fmod(h,2) - 1)));		//floats need to a special mod function!
	m = l - c / 2;
	if(h < 1) {r = (c + m) * 255; g = (x + m) * 255; b = m * 255;}
	else if(h >= 1 && h < 2) {r = (x + m) * 255; g = (c + m) * 255; b = m * 255;}
	else if(h >= 2 && h < 3) {r = m * 255; g = (c + m) * 255; b = (x + m) * 255;}
	else if(h >= 3 && h < 4) {r = m * 255; g = (x + m) * 255; b = (c + m) * 255;}
	else if(h >= 4 && h < 5) {r = (x + m) * 255; g = m * 255; b = (c + m) * 255;}
	else{r = (c + m) * 255; g = m * 255; b = (x + m) * 255;}
	printf("RGB(%i,%i,%i)", (int)round(r), (int)round(g), (int)round(b));
}

void HSV(string line)
{
	float h, s, v, c, x, m, r, g, b;
	line.erase(0, 4); line.erase(line.length() - 1, 1);
	replace(line.begin(), line.end(),',',' ');
	istringstream in(line);
	in >> h; in >> s; in >> v;
	h /= 60; s /= 100; v /= 100;
	c = v * s;
	x = c * (1 - abs(fmod(h,2) - 1));
	m = v - c;
	if(h < 1) {r = (c + m) * 255; g = (x + m) * 255; b = m * 255;}
	else if(h >= 1 && h < 2) {r = (x + m) * 255; g = (c + m) * 255; b = m * 255;}
	else if(h >= 2 && h < 3) {r = m * 255; g = (c + m) * 255; b = (x + m) * 255;}
	else if(h >= 3 && h < 4) {r = m * 255; g = (x + m) * 255; b = (c + m) * 255;}
	else if(h >= 4 && h < 5) {r = (x + m) * 255; g = m * 255; b = (c + m) * 255;}
	else{r = (c + m) * 255; g = m * 255; b = (x + m) * 255;}
	printf("RGB(%i,%i,%i)", (int)round(r), (int)round(g), (int)round(b));
}



int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        switch(line[0]){
        	case '(':
        		CMYK(line);
        		break;
        	case '#':
        		hex(line);
        		break;
        	default:
        		if(line[2] == 'L'){HSL(line);}
        		else{HSV(line);}
        		break;
        }
        cout << endl;
    }
    return 0;
} 