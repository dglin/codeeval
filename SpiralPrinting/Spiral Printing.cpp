
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctype.h>
using namespace std;

// void spiralPrintCL(char** Array, int x1, int y1, int x2, int y2);
// void spiralPrintIL(int** Array, int x1, int y1, int x2, int y2);
// void spiralPrintIR(int** Array, int x1, int y1, int x2, int y2);
// void spiralPrintCR(char** Array, int x1, int y1, int x2, int y2);

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) 
    {
        //cout << line << '|'; 
        istringstream in(line);
        getline(in, line,';');
        int N,M;
        int Array[256][256];
        char Array2[256][256];
        stringstream(line) >> N; // row
        getline(in,line,';');
        stringstream(line) >> M; //column
        int i = 0, j = 1, flag = 0; // i = n, j = m
        getline(in, line, ' ');
        if(isdigit(line[0]))
        {
            int temp1;
            stringstream(line) >> Array[0][0];
            while(getline(in, line, ' '))
            {
                int temp;
                stringstream(line) >> temp;
                Array[i][j] = temp;
                j++;
                if(j == M)
                {
                    i++;
                    j -= M;
                }
            }
        }
        else
        {
            flag = 1;
            Array2[0][0] = line[0];
            while(getline(in, line, ' '))
            {
                Array2[i][j] = line[0];
                j++;
                if(j == M)
                {
                    i++;
                    j -= M;
                }
            }
        }
        int A = 0, B = 0; // initial row
        int collected = 0, total = M * N;
        //string final = "";


        if(flag == 0){
        while(collected < total)
        {
            for(int i = 0 + A; i < M - A; i++)
            {
                cout << Array[A][i] << ' ';
                collected++;
            }
            if(collected == total){break;}
            A++;
            // Top

            for(int i = 1 + B; i < N - B; i++)
            {
                cout << Array[i][M - 1 - B] << ' ';
                collected++;
            }
            if(collected == total){break;}
            B++;
            //Right


            for(int i = M - A - 1; i >= A - 1; i--)
            {
                cout << Array[N - A][i] << ' ';
                collected++;
            }
            if(collected == total){break;}
            //Bottom

            for(int i = N - B - 1; i >= B; i--)
            {
                cout << Array[i][A - 1] << ' ';
                collected++;
            }
            if(collected == total){break;}
            //Left
        }
        }
        else
        {
        while(collected < total)
        {
            for(int i = 0 + A; i < M - A; i++)
            {
                cout << Array2[A][i] << ' ';
                collected++;
            }
            if(collected == total){break;}
            A++;
            // Top

            for(int i = 1 + B; i < N - B; i++)
            {
                cout << Array2[i][M - 1 - B] << ' ';
                collected++;
            }
            if(collected == total){break;}
            B++;
            //Right


            for(int i = M - A - 1; i >= A - 1; i--)
            {
                cout << Array2[N - A][i] << ' ';
                collected++;
            }
            if(collected == total){break;}
            //Bottom

            for(int i = N - B - 1; i >= B; i--)
            {
                cout << Array2[i][A - 1] << ' ';
                collected++;
            }
            if(collected == total){break;}
            //Left
        }
        }
        cout << endl;
    }
    return 0;
} 


// void spiralPrintIR(int** Array, int x1, int y1, int x2, int y2)
// {
//     cout << "HIIII4";
//     int i = 0, j = 0;
//     for(i = x1; i < x2 + 1; i++)
//     {
//         cout << Array[y1][i] << ',';
//     }
//     for(j = y1 + 1; j < y2 + 1; j++)
//     {
//         cout << Array[j][x2] << ',';
//     }
//     if(x2 - x1 > 0)
//     {
//         spiralPrintIL(Array, x1, y1 + 1, x2 - 1, y2);
//     }
// }

// void spiralPrintIL(int** Array, int x1, int y1, int x2, int y2)
// {
//     int i = 0, j = 0;
//     for(i = x2; i > x1 - 1; i--)
//     {
//         cout << Array[y2][i] << ',';
//     }
//     for(j = y2 - 1; j > y1 - 1; j--)
//     {
//         cout << Array[j][x1] << ',';
//     }
//     if(x2 - x1 > 0)
//     {
//         spiralPrintIR(Array, x1 + 1, y1, x2, y2 - 1);
//     }
// }
// void spiralPrintCR(char** Array, int x1, int y1, int x2, int y2)
// {
//     int i = 0, j = 0;
//     cout << "HIIII5";
//     for(i = x1; i < x2 + 1; i++)
//     {
//         cout << Array[y1][i] << ',';
//     }
//     for(j = y1 + 1; j < y2 + 1; j++)
//     {
//         cout << Array[j][x2] << ',';
//     }
//     if(x2 - x1 > 0)
//     {
//         spiralPrintCL(Array, x1, y1 + 1, x2 - 1, y2);
//     }
// }

// void spiralPrintCL(char** Array, int x1, int y1, int x2, int y2)
// {
//     int i = 0, j = 0;
//     for(i = x2; i > x1 - 1; i--)
//     {
//         cout << Array[y2][i] << ',';
//     }
//     for(j = y2 - 1; j > y1 - 1; j--)
//     {
//         cout << Array[j][x1] << ',';
//     }
//     if(x2 - x1 > 0)
//     {
//         spiralPrintCR(Array, x1 + 1, y1, x2, y2 - 1);
//     }
// }


