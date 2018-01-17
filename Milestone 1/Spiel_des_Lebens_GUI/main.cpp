#include <iostream>
#include <fstream>
#include <CAbase.h>
#include <snake.h>
#include <pasture.h>
#include <raptors.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <ctime>

//srand(time(NULL)); //seed randomizer

// version 1.1
// debug map to see living neighbors added
// in-place evolution added

using namespace std;

CAbase base1(10, 10);
Snake snake1;
Pasture pHeard;
Raptors rHeard;

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
    // print top border
    cout << "+";
    for (int i=0; i<base1.Nx; i++){
        cout << "--";
    }
    cout  << "+" << endl;
    // inner values
    for (int i=0; i<base1.Nx; i++){
        cout << "+ ";
        for (int j=0; j<base1.Ny; j++){
            switch (worldType) {
            case 1 :
                // print normal world
                cout << ((base1.getCell(j,i)) ? "*" : " ") << " ";
                break;
            case 2 :
                // print ids
                cout << base1.cellId(j,i) << " | ";
                break;
            case 3 :
                // print amount of living neighbors for each cell
                cout << base1.livingNeighbors(j,i) << " ";
                break;
            default:
                break;
            }
        }
        cout << "+" << endl;
    }
    // print bottom border
    cout << "+";
    for (int i=0; i<base1.Nx; i++){
        cout << "--";
    }
    cout << "+" << endl;
    cout << "Living cells: " << base1.alive << " age: " << base1.World_age << endl;
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

void PrepareFieldSnake(){
    // we use initial size, and add borders
    base1.resizeWorld(base1.Nx+2,base1.Ny+2); // also clears world
    // our game is setup in a way, that the border is made of "walls", which are cells with value=2
    // thus we can have random obstacles on the field, if wanted. Game can be extended easely to have this.
    // add borders to outer cells, according to requirement, those borders should NOT be visible on field
    // we could make the field borders thicker, to visualize them.
    for (int i=0; i<=base1.Nx; i++) {  // yes, we set the corner cells twice, who cares?
        base1.setCell(i,0,2); //first row, first to last cell
        base1.setCell(i,base1.Ny,2); //last row, first to last cell
        base1.setCell(0,i,2); //first column, first to last cell
        base1.setCell(0,base1.Nx,2); //last column, first to last cell
    }

    /* random head setter,
     * disabled to comply with requirements that our snake needs head, few body and a tail part
     * those are distinguished just by their values (tail is always 3, even if tail=head)
    base1.setSnakeHead(base1.randomObjId()); // creates one object with value=3, and all objects with value>2 are movable and belong to snake.
    */
    base1.setCell(snake1.grow(base1.getCell(5,5)), 5); // we set a snake into cell 55
    snake1.Status=1;
    // random food cell 1 is food, we could combine both games :-)
    base1.setCell(base1.randomObjId(),1);
}

int moveSnake(){
    // this is only semi object oriented...
    if (1!=snake1.Status) return -1;  //snake is dead, don't move
    int newid;
    switch(snake1.Direction){
    case 8 : newid = snake1.Body[0] - base1.Nx; break;  //up
    case 4 : newid = snake1.Body[0] - 1; break;  //left
    case 5 : newid = snake1.Body[0] + base1.Nx; break; //down
    case 6 : newid = snake1.Body[0] + 1; break; //right
    default : return -1; //dead or not there
    }
    // depending on the object in newid our snake can move, grow or die
    switch(base1.World[newid]){
    case 0 : // move
        base1.setCell(snake1.move(newid), 0); // we move snake and clear tail in one step
        return 0;
    case 1 : // grow
        base1.setCell(snake1.grow(newid), 5);
        base1.setCell(base1.randomObjId(),1); // create random food cell
        return 1;
    default : // die, die, die my darling!
        snake1.Status=2;
        return -1;
    }
}

void evolveJungle(){
    /* we first evolve all raptors, then we evolve pasture
     * this will ensure the required behavior
     */
    int oldID, moveID, moveRes;
    // move raptors
    for (i=0; i<=rHeard.Population; i++){
        oldID=rHeard.Locations[i];
        moveID=base1.moveSpecialCell(oldID,4);
        moveRes=rHeard.Move(i, moveID, base1.World[moveID]);
        switch(moveRes){
        case 1 : // base knows cell has moved and alive
            base1.World[moveID]=4; // set cell to raptor
            base1.World[oldID]=0; // remove raptor from old place
            break;
        case 0 : // base knows cell died
            base1.World[rHeard.Decay(herdID)]=0; // remove decayed raptor
        }
    }

    // procede with pasture
    for (i=0; i<=rHeard.Population; i++){
        oldID=pHeard.Locations[i];
        moveID=base1.moveSpecialCell(oldID,3);
        moveRes=pHeard.Move(i, moveID, base1.World[moveID]);
        switch(moveRes){
        case 1 : // base knows cell has moved and alive
            base1.World[moveID]=3; // set cell to pasture
            base1.World[oldID]=0; // remove pasture from old place
            break;
        case 0 : // base knows cell died
            base1.World[rHeard.Decay(herdID)]=0; // remove decayed pasture
        }
    }
}

int main()
{
    printMap();
    printMenu();
    do {
        string userinput;
        int menuoption, worldRow, worldColumn, cellValue;
        bool wronginput;
        getline(cin, userinput);
        stringstream inputStream(userinput);
        if (inputStream >> menuoption)
            switch(menuoption){
            case 0 :  // exit
                return 0;

            case 1 :  // set cell to value manually
                cout << "Which cell do you want to change?" << endl;
                cout << "Enter row number (1-" << base1.Ny << "): ";
                worldRow = intUserInput(1, base1.Ny)-1;
                cout << "Enter column number (1-" << base1.Nx << "): ";
                worldColumn=intUserInput(1, base1.Nx)-1;
                cellValue=intUserInput(0, 1);
                // change state of cell
                base1.setCell(worldColumn,worldRow, cellValue );
                break;

            case 2 :
                // flip cell value 0<->1
                cout << "Which cell do you want to change?" << endl;
                cout << "Enter row number (1-" << base1.Ny << "): ";
                worldRow = intUserInput(1, base1.Ny)-1;
                cout << "Enter column number (1-" << base1.Nx << "): ";
                worldColumn=intUserInput(1, base1.Nx)-1;
                // now flip the state of cell
                base1.flipCell(worldColumn,worldRow);
                break;

            case 3 :
                printMap();
                printMenu();
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
                break;

            // now some "hidden features":
            case 7 :
                // evolve one cell in world asynchronously
                cout << "Which cell do you want to evolve in place?" << endl;
                cout << "Enter row number (1-" << base1.Ny << "): ";
                worldRow = intUserInput(1, base1.Ny)-1;
                cout << "Enter column number (1-" << base1.Nx << "): ";
                worldColumn=intUserInput(1, base1.Nx)-1;
                cellValue = base1.evolveCell(worldColumn, worldRow); // get new Value
                base1.setCell(worldColumn, worldRow, cellValue); // evolve this one cell
                break;
            case 8 :
                // print id map
                printMap(2);
                break;
            case 9 :
                // print neighbor cell map
                printMap(3);
                break;
            default:
                cout << "Please choose one of the given options (0-2)";
                break;
            }
    }while(true);
    return 0;
}
