#include <iostream>
#include <fstream>
#include <CAbase.h>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

// creation of universe with given dimensions
CAbase::CAbase(int size_x, int size_y){
    Nx=size_x;
    Ny=size_y;
    worldSize=Nx*Ny;
    createWorld();
}

CAbase::~CAbase(){
    delete [] World;
    delete [] newWorld;
    cout << "goodbye!";
}

/* class methods */
int CAbase::cellId(int x, int y){
    // y is the row number, starting with 1
    // x is cell number, starting with 1
    return (y*Nx+x);
}

int CAbase::livingNeighbors(int id){
    // counter of living neighbors
    int livingNeighbors = 0;
    int row, col;
    // outer loop for rows
    for ( int i=-1; i<2; i++) {
        // inner loop for columns
        for ( int j=-1; j<2; j++) {
            if ( !((i==0) & (j==0)) ) {// we exclude the cell itself
                // here we decided to train ternary if....
                // after hours of headache it works, and looks nice, and it means:
                // if top edge ? look down : otherwise ( if bottom edge ? look up : otherwise i)
                row = ( (( (id/Nx)==0 ) & (i==-1)) ? (Ny-1) : ( (( (Ny-1)==id/Nx) & (i==1)) ? -(Ny-1) : i ) );
                // similar, but for sides.
                col = ( (( (id%Nx)==0) & (j==-1)) ? (Nx-1) : ( (( (id%Nx)==(Nx-1)) & (j==1)) ? -(Nx-1) : j ) );
                livingNeighbors += ( World[id+(Nx*row+col)] ? 1 : 0);
            }
        }
    }
    return livingNeighbors;
}

int CAbase::moveSpecialCell(int id, int celltype){
    /* we'll search for first foodcell, if found return
     * foodsells are celltype dependent, celltype 4 eats 3, everything else eats 1
     * implemented with switch case, for possible extendability
     * if no food cell found - search for empty cell
     */
    int food, row, col, lookupid;
    // define food:
    switch (celltype) {
    case 4: food=3; break;
    default: food=1; break;
    }
    // search for food
    // outer loop for rows
    for ( int i=-1; i<2; i++) {
        // inner loop for columns
        for ( int j=-1; j<2; j++) {
            if ( !((i==0) & (j==0)) ) {// we exclude the cell itself
                // if top edge ? look down : otherwise ( if bottom edge ? look up : otherwise i)
                row = ( (( (id/Nx)==0 ) & (i==-1)) ? (Ny-1) : ( (( (Ny-1)==id/Nx) & (i==1)) ? -(Ny-1) : i ) );
                // similar, but for sides.
                col = ( (( (id%Nx)==0) & (j==-1)) ? (Nx-1) : ( (( (id%Nx)==(Nx-1)) & (j==1)) ? -(Nx-1) : j ) );
                lookupid=id+(Nx*row+col);
                if( World[lookupid]==food) return lookupid;
            }
        }
    }
    // no food found, search for empty cell
    for ( int i=-1; i<2; i++) {
        // inner loop for columns
        for ( int j=-1; j<2; j++) {
            if ( !((i==0) & (j==0)) ) {// we exclude the cell itself
                // if top edge ? look down : otherwise ( if bottom edge ? look up : otherwise i)
                row = ( (( (id/Nx)==0 ) & (i==-1)) ? (Ny-1) : ( (( (Ny-1)==id/Nx) & (i==1)) ? -(Ny-1) : i ) );
                // similar, but for sides.
                col = ( (( (id%Nx)==0) & (j==-1)) ? (Nx-1) : ( (( (id%Nx)==(Nx-1)) & (j==1)) ? -(Nx-1) : j ) );
                lookupid=id+(Nx*row+col);
                if(World[lookupid]==0) return lookupid;
            }
        }
    }
    // neither food, nor empty neighbor found, return initial id
    return id;
}

int CAbase::getCell(int id){
    return World[id];
}

void CAbase::setCell(int id, int status){
    // manage living cells counter:
    alive += ( (status==1) & (World[id]==0) ? 1 : 0); //if status is 1 and cell is dead/empty, add one
    alive -= ( (status==0) & (World[id]==1) ? 1 : 0); //if status is 0 and cell is alive, substr one
    // sets the value of cell in world, used to setup or change status
    World[id]=status;
}

void CAbase::flipCell(int id){
    if (World[id]==0){
        alive++; //if cell is alive, kill one
        World[id]=1;
    }
    else if(World[id]==1){
        alive--;
        World[id]=0;
    }
    // else we do nothing
}

int CAbase::evolveCell(int id){
    switch(World[id]){
    case 0 :    //empty cell
        ;//pass
    case 1 :    //living cell (food)
    {
        // if used to evolve cell manually, will not affect amount of living cells!
        // yes we have some kind of a Schroedingers (Cat) Cell !!
        int status=0;
        int ln = livingNeighbors(id);
        switch (ln){
        case 0 :
            status = 0;
            break;
        case 1 :
            status = 0;
            break;
        case 2 :
            status = (World[id]) ? 1 : 0;
            break;
        case 3 :
            status = 1;
            break;
        default:
            status = 0;
            break;
        }
        newWorld[id]=status;
        break;
    }
    default :    //some other object like wall or snake
        newWorld[id]=World[id];  //just copy
    }
    return newWorld[id];
}

int CAbase::randomObjId(){
    // randomly places snake head on any free map cell
    int randCell=rand()%worldSize; // limit max iterations to prevent long searches
    int cellShift=randCell; // iterator = max iterations
    int cellid=0;
    while(cellShift>0) { // iterate through free cells
        if (World[cellid]==0) cellShift--; // decrement iterator
        cellid++; // next cell
        if ((cellid>worldSize) & (cellShift<randCell)){
            cellid=0; // restart if necessary
        }
        else return 0; // iterator unchanged, means we found no empty cells;
    }
    // search for next possible free cell and use it
    do{
        if (World[cellid]==0) break; // found appropriate random cell
        cellid++; // next cell
        if (cellid>worldSize) cellid=0; // restart if necessary
    }while(true);
    return cellid;
}

void CAbase::resizeWorld(int size_x, int size_y){
    Nx=size_x;
    Ny=size_y;
    worldSize = Nx*Ny;
    delete [] World;
    World = NULL; // just to make sure no memory is allocated to World
    delete [] newWorld;
    newWorld = NULL;
    createWorld();
}

void CAbase::createWorld(){
    // we just set the vars, but don't touch their inner, should be 0 anyways.
    World = new int[worldSize];
    newWorld = new int[worldSize];
    for (int i=0; i<worldSize; i++){
        World[i]=0;
        newWorld[i]=0;
    }
}

void CAbase::evolveWorld(){
    // reset living cells counter
    alive=0;
    // project cell evolution to newWorld
    for (int cellid=0; cellid<=worldSize; cellid++){
        evolveCell(cellid);
    }

    // copy new world to old
    for (int i=0; i<worldSize; i++){
        World[i]=newWorld[i];
        alive+=World[i];
    }
    World_age++;
    cout << endl << "living cells in age " << World_age << ": " << alive << endl;
    // no need to delete newWorld
}

void CAbase::clearWorld(){
    delete [] World;
    delete [] newWorld;
    createWorld();
}
