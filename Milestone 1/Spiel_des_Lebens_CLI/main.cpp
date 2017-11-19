#include <iostream>
#include <fstream>
#include <CAbase.h>
#include <stdlib.h>
#include <string>
#include <sstream>

// version 0.6
// debug map to see living neighbors added
// in-place evolution added
// missing: save game and load game
// bug: abrupt program stop on reprint after some evolutions, needs fix

using namespace std;

CAbase base1(30, 30);

void savegame(){

}

void loadgame(){

}

void printMenu(){
    cout << "Choose an option: " << endl;
    cout << "0. Exit" << endl;
    cout << "1. Change Cell to value" << endl ;
    cout << "2. Flip Cell" << endl ;
    cout << "3. Reprint" << endl;
    cout << "4. Evolve" << endl;
    cout << "5. Resize" << endl;
}

void printMap(int worldType){
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
            switch (worldType) {
            case 1 :
                // print normal world
                cout << ((base1.getCell(i,j)) ? "*" : " ") << " ";
                break;
            case 2 :
                // maybe will print newWorld, no need yet
                break;
            case 3 :
                // print amount of living neighbors for each cell
                cout << base1.livingNeighbors(i,j) << " ";
            default:
                break;
            }
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

void printMap(){
    printMap(1);
}

int intUserInput(int minValue, int maxValue){
    string userinput;
    int numChoice;
    bool wronginput;
    do{
        getline(cin, userinput);
        stringstream inputStream(userinput);
        if (inputStream >> numChoice){
            if((minValue <= numChoice) & (numChoice <= maxValue)) break;
        }
        cout << "wrong input, please follow instructions!" << endl;
        wronginput=true;
    }while(wronginput);
    return numChoice;
}

int main()
{
    printMap();
    do {
        printMenu();
        string userinput;
        int menuoption, worldRow, worldColumn, worldWidth, worldHeigh;
        bool wronginput, cellValue;
        worldWidth=base1.getworldWidth();
        worldHeigh=base1.getworldHeigh();
        getline(cin, userinput);
        stringstream inputStream(userinput);
        if (inputStream >> menuoption)
            switch(menuoption){
            case 0 :  // exit
                return 0;

            case 1 :  // set cell to value manually
                cout << "Which cell do you want to change?" << endl;
                cout << "Enter row number (1-" << worldHeigh << "): ";
                worldRow = intUserInput(1, worldHeigh);
                cout << "Enter column number (1-" << worldWidth << "): ";
                worldColumn=intUserInput(1, worldWidth);
                cellValue=intUserInput(0, 1);
                cout << "Row: " << worldRow << " Column: " << worldColumn;
                cout << " Actual value: " << base1.getCell((worldColumn-1), (worldRow-1)) << endl;
                cout << "New value: ";
                // change state of cell
                base1.setCell((worldRow-1),(worldColumn-1), cellValue );
                break;

            case 2 :
                // flip cell value 0<->1
                cout << "Which cell do you want to change?" << endl;
                cout << "Enter row number (1-" << worldHeigh << "): ";
                worldRow = intUserInput(1, worldHeigh);
                cout << "Enter column number (1-" << worldWidth << "): ";
                worldColumn=intUserInput(1, worldWidth);
                cout << "Row: " << worldRow << " Column: " << worldColumn;
                cout << " Actual value: " << base1.getCell((worldColumn-1), (worldRow-1)) << endl;

                // now flip the state of cell
                base1.flipCell( (worldRow-1), (worldColumn-1) );
                break;
            case 3 :
                printMap();
                break;

            case 4 :
                base1.evolveWorld();
                break;

            case 5 :
                // resize world, we use same vars, as in previous cases
                int xSize, ySize;
                // loop to get the rows number
                do{
                    cout << "Enter amount of rows: ";
                    getline(cin, userinput);
                    stringstream inputStream(userinput);
                    if (inputStream >> xSize) break;
                    cout << "wrong input, please follow instructions!" << endl;
                    wronginput=true;
                }while(wronginput);

                // loop to get the columns number
                do{
                    cout << "Enter amount of columns: ";
                    getline(cin, userinput);
                    stringstream inputStream(userinput);
                    if (inputStream >> ySize) break;
                    cout << "wrong input, please follow instructions!" << endl;
                    wronginput=true;
                }while(wronginput);
                base1.resizeWorld(ySize, xSize);

            // now some "hidden features":
            case 8 :
                // evolve one cell in world asynchronously
                cout << "Which cell do you want to evolve in place?" << endl;
                cout << "Enter row number (1-" << worldHeigh << "): ";
                worldRow = intUserInput(1, worldHeigh);
                cout << "Enter column number (1-" << worldWidth << "): ";
                worldColumn=intUserInput(1, worldWidth);
                cout << "Row: " << worldRow << " Column: " << worldColumn;
                cout << "Actual value: " << base1.getCell((worldColumn-1), (worldRow-1)) << endl;
                cellValue = base1.evolveCell((worldColumn-1), (worldRow-1));
                // now evolve this one cell
                base1.setCell((worldColumn-1), (worldRow-1), cellValue);
                cout << "New value: " << base1.getCell((worldColumn-1), (worldRow-1)) << endl;
                break;
            case 9 :
                // print neighbor cell map
                printMap(3);
            default:
                cout << "Please choose one of the given options (0-2)";
                break;
            }
    }while(true);
    return 0;
}
