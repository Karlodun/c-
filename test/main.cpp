#include <iostream>
#include <stdlib.h>

using namespace std;

//Variable declaration

extern int A1[30][30];
extern int *A2[30*30];
extern int x, y;

int main()
{
    for ( int x=0; x<30; x++) {
        cout << "Zeile:" << endl;
        cout << x << endl;
        for ( int y=0; y<30; y++) {
            cout << "Spalte:" << endl;
            cout << y << endl;
            int A1[x][y];
            A1[x][y]= rand() %9 + 1;
//            cout << "Zelle:" << endl;
//            cout << A1[x][y] << endl;
        }
    }
    cout << "Hello World!" << endl;
//    cout << A1[0][2] << endl;
    return 0;
}
