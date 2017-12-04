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

int CAbase::getCell(int id){
    return World[id];
};

void CAbase::setCell(int id, int status){
    // manage living cells counter:
    alive += ( (status==1) & (World[id]==0) ? 1 : 0); //if status is 1 and cell is dead/empty, add one
    alive -= ( (status==0) & (World[id]==1) ? 1 : 0); //if status is 0 and cell is alive, substr one
    // sets the value of cell in world, used to setup or change status
    World[id]=status;
};

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

void CAbase::setSnakeHead(int id){
    // forcefully places snake head on choosen id with 7 for no direction
    // will change any value to snake
    setCell(id, 7);
    snakeHeadCell=id;
}

int CAbase::nextSnakePart(int id){
    int nextid=-1;
    if ( (2 < World[id]) & (10 > World[id]) ){ // we have a head
        // search for neighbor with highest value over 9
        int nextValue=9; //needed only to find cell with highest value
        if (nextValue<World[id-Nx]) {nextValue=World[id-Nx]; nextid=id-Nx;}
        if (nextValue<World[id-1]) {nextValue=World[id-1]; nextid=id-1;}
        if (nextValue<World[id+Nx]) {nextValue=World[id+Nx]; nextid=id+Nx;}
        if (nextValue<World[id+1]) {nextValue=World[id+1]; nextid=id+1;}
    } else if (10 < World[id]) { // we have body
        // we search for next snake part on top, left, bottom, right
        // next snake part is smaller by 1
        if ((World[id]-1) == World[id-Nx]){ // top
            nextid=id-Nx;
        } else if ((World[id]-1) == World[id-1]){ // left
            nextid=id-1;
        } else if ((World[id]-1) == World[id+Nx]){ // bottom
            nextid=id+Nx;
        } else if ((World[id]-1) == World[id+1]){ // top
            nextid=id+1;
        }
    }
    return nextid;
}

int CAbase::moveSnakeHead(){
    // get id of the cell we want to move to
    int newid;
    int id=snakeHeadCell;
    switch(World[snakeHeadCell]){
    case 8 : //up
        newid = id - Nx;
        break;
    case 4 : //left
        newid = id - 1;
        break;
    case 5 : //down
        newid = id + Nx;
        break;
    case 6 : //right
        newid = id + 1;
        break;
    default : //dead or not there
        return -1;
    }
    // depending on the object in newid our snake can move, grow or die
    switch(World[newid]){
    case 0 : // move
        World[newid]=World[id];
        return 0;
    case 1 : // grow
        World[newid]=World[id];
        setCell(randomObjId(),1); // create random food cell
        return 1;
    default : // die, die, die my darling!
        World[newid]=9;  // 9 in head means dead
        return -1;
    }
}

void CAbase::moveSnake(){
    // snake moves inside world, to preven unnecessary steps and evaluations
    // we evaluate snake cells only, ommiting other
    if (0==moveSnakeHead()){ //if head moves normally forward, move other parts
        // now we move body and tail cells
        int targetCellId=snakeHeadCell;
        int snakePartId=nextSnakePart(snakeHeadCell);
        //snakePart==10 is our tail, after that we just abort
        // check if snake is not dead, and we are still moving snake parts
        while( (World[snakeHeadCell]!=9) & (World[snakePartId]>9)){
            //move that cell to the one that was moved previously
            World[targetCellId]=World[snakePartId];
            targetCellId=snakePartId;
            snakePartId=nextSnakePart(snakePartId);
        }
    }
}

void CAbase::setDir(int newDir){
    //check if there is a cell, smaller then head in that new direction, no move is possible then!
    int newid;
    int id=snakeHeadCell;
    switch(newDir){
    case 8 : //up
        newid = id - Nx;
        break;
    case 4 : //left
        newid = id - 1;
        break;
    case 5 : //down
        newid = id + Nx;
        break;
    case 6 : //right
        newid = id + 1;
        break;
    default : //dead or not there
        return;
    }
    if (World[newid]<10){ // if not tail/body
        World[id]=newDir;
    };
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
