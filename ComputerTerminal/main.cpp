
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    char Array[12][12] = { 0 };
    int ptrx = 0, ptry = 0;
    bool flag = true;
    while (getline(stream, line)) {
        cout << line << endl;
        for(unsigned x = 0; x < line.length(); x++)
        {
            if(line[x] == '^')
            {
                switch(line[x + 1]){
                    case 'c':
                        for(int l = 0; l < 10; l++){
                            for(int m = 0; m < 10; m++){Array[l][m] = '\0';}
                        }
                        break;
                    case 'h':
                        ptrx = ptry = 0;
                        break;
                    case 'b':
                        ptrx = 0;
                        break;
                    case 'd':
                        if(ptry < 9){ptry++;}
                        break;
                    case 'u':
                        if(ptry > 0){ptry--;}
                        break;
                    case 'l':
                        if(ptrx > 0){ptrx--;}
                        break;
                    case 'r':
                        if(ptrx < 9){ptrx++;}
                        break;
                    case 'e':
                        for(int d = ptrx; d < 10; d++){Array[ptry][d] = '\0';}
                        break;
                    case 'i':
                        flag = false;
                        break;
                    case 'o':
                        flag = true;
                        break;
                    case '^':
                        Array[ptry][ptrx] = '^';
                        if(ptrx < 9){ptrx++;}
                        //else{ptrx = 0; if(ptry < 9) {ptry++;}}
                        break;
                    default:
                        ptry = (line[x + 1] - '0') ;
                        ptrx = (line[x + 2] - '0') ;
                        x++;
                        break;
                }
                x++;
            }
            else
            {
                if(flag)
                {
                    Array[ptry][ptrx] = line[x];
                    if(ptrx < 9){ptrx++;}
                    //else{ptrx = 0; if(ptry < 9) {ptry++;}}
                }
                else
                {
                    for(int y = 9; y > ptrx; y--)
                    {
                        Array[ptry][y] = Array[ptry][y - 1];
                    }
                    Array[ptry][ptrx] = line[x];
                    if(ptrx < 9){ptrx++;}
                    //else{ptrx = 0; if(ptry < 9) {ptry++;}}
                }
            }
            //if(ptrx == 0 && ptry = 4)
        }
    }
    //Array[4][0] = '<';
    //Array[5][7] = '/';
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++)
        {
            if(Array[i][j] == '\0'){cout << ' ';}
            else{cout << Array[i][j];}
        }
        cout << endl;
    }
    
    return 0;
}