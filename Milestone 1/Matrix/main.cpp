#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

/* References
 *
 * Using cin to get user input: http://www.cplusplus.com/forum/articles/6046/
 *
 */

using namespace std;

//Variable declaration

int A1[30][30];

int *A2 = new int[30*30];

int x, y;

void fillA1(){
    for ( int x=0; x<30; x++) {
        for ( int y=0; y<30; y++) {
            A1[x][y]= rand() %9 + 1;
        }
    }
}

void fillA2(){
    for ( int x=0; x<(30*30); x++) {
        A2[x] = A1[x/30][x%30];
    }
}

void printA2(){
    for ( int x=0; x<30; x++) {
        for ( int y=0; y<30; y++) {
            cout << A2[x*y] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Hello World!" << endl;
    fillA1();
    fillA2();
    printA2();

    do {
        string userinput;
        int menuoption, A2row, A2column;
        bool wronginput;
        cout << "Choose an option: " << endl << "0. Exit" << endl << "1. Change Cell" << endl << "2. Reprint" << endl;
        getline(cin, userinput);
        stringstream inputStream(userinput);
        if (inputStream >> menuoption)
            switch(menuoption){
            case 0 :
                return 0;
                // no break statement necessary
            case 1 :
                cout << "Which cell do you want to change?" << endl;
                // request entry until user enter appropriate
                // we took two identical loops, instead of one, to make it more appropriate for the user
                // even though the code could be simplified by using a function - we saved us the work.

                // loop to get the row number
                // a simple while would be more appropriate, but we'll use do while, just in case
                do{
                    cout << "Enter row number (1-30): ";
                    getline(cin, userinput);
                    stringstream inputStream(userinput);
                    if (inputStream >> A2row){
                        cout << A2row;
                        if((0 < A2row) & (A2row<31)) break;
                    }
                    cout << "wrong input, please follow instructions!" << endl;
                    wronginput=true;
                }while(wronginput);

                // loop to get the column number
                do{
                    cout << "Enter column number (1-30): ";
                    getline(cin, userinput);
                    stringstream inputStream(userinput);
                    if (inputStream >> A2column){
                        cout << A2column;
                        if((0 < A2column) & (A2column<31)) break;
                    }
                    cout << "wrong input, please follow instructions!" << endl;
                    wronginput=true;
                }while(wronginput);

                cout << "Row: " << A2row << " Column: " << A2column;
                cout << " Actual value: " << A2[(A2row-1)*(A2column-1)] << endl;
                cout << "New value (1-9): "; cin >> A2[(A2row-1)*(A2column-1)];
                break;
            case 2 :
                printA2();
                break;
            default:
                cout << "Please choose one of the given options (0-2)";
                break;
            }
    }while(true);
    return 0;
}
