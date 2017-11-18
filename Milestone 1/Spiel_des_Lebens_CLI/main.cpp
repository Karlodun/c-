#include <iostream>
#include <fstream>
#include <CAbase.h>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

CAbase base1(10, 10);

void savegame(){

}
void loadgame(){

}

void printMenu(){
    cout << "Choose an option: " << endl;
    cout << "0. Exit" << endl;
    cout << "1. Change Cell" << endl ;
    cout << "2. Reprint" << endl;
    cout << "3. Evolve" << endl;
    cout << "4. Resize" << endl;
}

void printMap(){
    int worldWidth = base1.getworldWidth();
    int worldHeigh = base1.getworldHeigh();
    // print top border
    cout << "+";
    for (int i=0; i<worldWidth; i++){
        cout << "--";
    }
    cout  << "+" << endl;
    // inner values
    for (int i=0; i<worldWidth; i++){
        cout << "+ ";
        for (int j=0; j<worldHeigh; j++){
            cout << ((base1.getCell(i,j)) ? "*" : " ") << " ";
        }
        cout << "+" << endl;
    }
    // print bottom border
    cout << "+";
    for (int i=0; i<worldWidth; i++){
        cout << "--";
    }
    cout << "+" << endl;
}

void printCLI(){
    printMap();
    printMenu();
}

int main()
{
    printCLI();
    do {
        string userinput;
        int menuoption, worldRow, worldColumn, worldWidth, worldHeigh;
        bool wronginput;
        worldWidth=base1.getworldWidth();
        worldHeigh=base1.getworldHeigh();
        printMenu();
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
                    cout << "Enter row number (1-" << worldHeigh << "): ";
                    getline(cin, userinput);
                    stringstream inputStream(userinput);
                    if (inputStream >> worldRow){
                        cout << worldRow;
                        if((0 < worldRow) & (worldRow<=worldHeigh)) break;
                    }
                    cout << "wrong input, please follow instructions!" << endl;
                    wronginput=true;
                }while(wronginput);

                // loop to get the column number
                do{
                    cout << "Enter column number (1-" << worldWidth << "): ";
                    getline(cin, userinput);
                    stringstream inputStream(userinput);
                    if (inputStream >> worldColumn){
                        cout << worldColumn;
                        if((0 < worldColumn) & (worldColumn<31)) break;
                    }
                    cout << "wrong input, please follow instructions!" << endl;
                    wronginput=true;
                }while(wronginput);

                cout << "Row: " << worldRow << " Column: " << worldColumn;
                cout << " Actual value: " << base1.getCell((worldColumn-1), (worldRow-1)) << endl;
                cout << "New value (1-9): ";
                // change state of cell

                base1.setCell((worldRow-1),(worldColumn-1), ( (base1.getCell(worldColumn-1), (worldRow-1)) ? 0 : 1 ) );
                break;
            case 2 :
                printCLI();
                break;
            default:
                cout << "Please choose one of the given options (0-2)";
                break;
            }
    }while(true);
    return 0;
}
