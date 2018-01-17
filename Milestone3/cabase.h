#ifndef CABASE_H
#define CABASE_H

#include <cstddef>

using namespace std;

class CAbase
{
    /* Used values on map/World:
     * 0 : empty
     * 1 : living cell / food
     * 2 : wall
     * 3 : pasture
     * 4 : raptor
     * 5 : snake
     */

     public :
          // world metrics and arrays
          int Nx, Ny, worldSize;
          int alive=0, World_age=0;
          int *World = NULL;
          int *newWorld = NULL;

          // constructor
          CAbase(int size_x, int size_y);
          // destructor:
          ~CAbase();

          void resizeWorld(int size_x, int size_y); // returns size if World
          void createWorld(); // returns size of World
          int cellId(int x, int y); // returns actual id for x and y coordinates
          // flip a Cell in World between empty(0) and alive(1)
          void flipCell(int x, int y){flipCell(cellId(x,y));}
          void flipCell(int id);
          // evolve a Cell of world and save in newWorld
          int evolveCell(int x, int y){return evolveCell(cellId(x,y));}
          int evolveCell(int id);
          // count all living neighbors, needed for evolveCell
          int livingNeighbors(int x, int y){return livingNeighbors(cellId(x,y));}
          int livingNeighbors(int id);

          // get next cell where special cells can go, depending on type
          int moveSpecialCell(int x, int y, int celltype){return moveSpecialCell(cellId(x,y), celltype);}
          int moveSpecialCell(int id, int celltype);

          int randomObjId(); // returns id of a random empty cell

          void evolveWorld(); // no return needed
          // returns cell data
          int getCell(int x, int y){return getCell(cellId(x,y));}
          int getCell(int id);
          // sets cell data in actual world
          void setCell(int x, int y, int status){setCell(cellId(x,y), status);}
          void setCell(int id, int status);
          // since arrays in returs are a bit complicated in c++
          // we'll use 3 functions for world size returns
          void clearWorld(); // clears world
};

#endif // CABASE_H
