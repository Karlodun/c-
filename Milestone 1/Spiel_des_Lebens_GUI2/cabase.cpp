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

int CAbase::getworldSize(){
    return Nx*Ny;
}

int CAbase::livingNeighbors(int x, int y){
    return livingNeighbors(cellId(x,y));
}

int CAbase::livingNeighbors(int id){
    // counter of living neighbors
    int livingNeighbors = 0;
    // outer loop for rows
    for ( int i=-1; i<2; i++) {
        // inner loop for columns
        for ( int j=-1; j<2; j++) {
            if ( !((i==0) & (j==0)) ) {// we exclude the cell itself
                int checkid = id+(Ny*i+j);
                if ( (0<=checkid) && (checkid<worldSize) ) // we exclude cells out of scope
                    livingNeighbors += World[checkid];
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
    // sets the value of cell in world, used to setup or change status
    World[id]=status;
};

void CAbase::flipCell(int x, int y){
    flipCell(cellId(x,y));
}

void CAbase::flipCell(int id){
    World[id]=!World[id];
}

bool CAbase::evolveCell(int x, int y){
    return evolveCell(cellId(x,y));
}

bool CAbase::evolveCell(int id){
    bool status=0;
    int ln = livingNeighbors(id);
    cout << "(ln: "<< ln << ")";
    switch (ln){
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

        alive+=World[cellid];
    }
    cout << endl << "living cells in new world: " << alive << endl;

    // copy new world to old
    for (int i=1; i<worldSize; i++){
        World[i]=newWorld[i];
    }

    // no need to delete newWorld
}

void CAbase::clearWorld(){
    delete [] World;
    delete [] newWorld;
    createWorld();
}

void CAbase::test(){
    resizeWorld(10,10);
    for (int i= 20; i < 80; i++){
        flipCell(i);
    }
}
