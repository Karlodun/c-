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
    World=new bool[Nx*Ny];
}

CAbase::~CAbase(){
    cout << "goodbye!";
}

/* class methods */

int CAbase::livingNeighbors(int id){
    // counter of living cells
    int livingNeighbors = 0;
    // outer loop for rows
    for ( int i=-1; i<1; i++) {
        for ( int j=0; j<1; j++) {
            if (!((i==0) & (j==0))) // we exclude the cell itself
                livingNeighbors += World[id+(Ny*i+j)];
        }
    }
    return livingNeighbors;
}

int CAbase::cellId(int x, int y){
    // y is the row number, starting with 1
    // x is cell number, starting with 1
    return ((y-1)*Nx+(x-1));
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

void CAbase::evolveCell(int x, int y){
    evolveCell(cellId(x,y));
}

bool CAbase::evolveCell(int id){
    bool status=0;
    int ln = livingNeighbors(id);
    switch (ln){
        case 0: status = 0;
        case 1: status = 0;
        case 2: status = (World[id]) ? 1 : 0;
        case 3: status = 1;
        default: status = 0;
    }
    newWorld[id]=status;
    return status;
}

void CAbase::resizeWorld(int size_x, int size_y){
    Nx=size_x;
    Ny=size_y;
    worldSize = Nx*Ny;
    createWorld();
}

void CAbase::createWorld(){
    // we just set the vars, but don'T touch their inner, should be 0 anyways.
    World = new bool[worldSize];
    newWorld = new bool[worldSize];
}

void CAbase::evolveWorld(){
    for (int cellid=0; cellid<=worldSize; cellid++){
        evolveCell(cellid);
    }
    // copy new world to old
    // delete new world values
};

/*
bool CAbase::getWorld(){
    return World;
};

bool CAbase::getnewWorld(){
    return newWorld;
};

void CAbase::setWorld(bool map[]){
    // needs fix
    World=map;
};

void CAbase::randomWorld(int spores){
    //we tell how many living cells should be there, and randomly insert them

};
*/

void CAbase::clearWorld(){
    delete [] World;
    delete [] newWorld;
    createWorld();
};