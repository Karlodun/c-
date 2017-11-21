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
    cout << "goodbye!";
}

/* class methods */
int CAbase::getworldWidth(){
    return Nx;
}

int CAbase::getworldHeigh(){
    return Ny;
}

int CAbase::livingNeighbors(int x, int y){
    return livingNeighbors(cellId(x,y));
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

int CAbase::cellId(int x, int y){
    // y is the row number, starting with 1
    // x is cell number, starting with 1
    return (y*Nx+x);
}

bool CAbase::getCell(int x, int y){
    return getCell(cellId(x,y));
};

bool CAbase::getCell(int id){
    return World[id];
};

void CAbase::setCell(int x, int y, bool status){
    // sets the value of cell in world, used to setup or change status
    setCell(cellId(x,y), status);
};

void CAbase::setCell(int id, bool status){
    // manage living cells counter:
    alive += (status & !World[id] ? 1 : 0); //if status is 1 and cell is dead, add one
    alive -= (!status & World[id] ? 1 : 0); //if status is 0 and cell is alive, substr one
    // sets the value of cell in world, used to setup or change status
    World[id]=status;
};

void CAbase::flipCell(int x, int y){
    flipCell(cellId(x,y));
}

void CAbase::flipCell(int id){
    alive += (World[id] ? -1 : 1); //if cell is alive, kill one
    World[id]=!World[id];
}

bool CAbase::evolveCell(int x, int y){
    return evolveCell(cellId(x,y));
}

bool CAbase::evolveCell(int id){
    // if used to evolve cell, will not affect amount of living cells!
    // yes we have some kind of a Schroedingers (Cat) Cell !!
    bool status=0;
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
    return status;
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
    World = new bool[worldSize];
    newWorld = new bool[worldSize];
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
