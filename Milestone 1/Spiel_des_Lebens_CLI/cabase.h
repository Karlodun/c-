#ifndef CABASE_H
#define CABASE_H

#include <cstddef>

using namespace std;

class CAbase
{
     private :
    // worldSize is there just to prevent repetitive calculation where possible
          int Nx, Ny, worldSize, alive=0, World_age=0;
          int *World = NULL;
          int *newWorld = NULL;
     public :
          // constructor
          CAbase(int size_x, int size_y);
          // destructor:
          ~CAbase();
          void resizeWorld(int size_x, int size_y); // returns size if World
          void createWorld(); // returns size of World
          int cellId(int x, int y); // returns actual id for x and y coordinates
          // evolve a Cell of world and save in newWorld
          void evolveCell(int x, int y);
          int evolveCell(int id);
          // cound all living neighbors, needed for evolveCell
          int livingNeighbors(int x, int y);
          int livingNeighbors(int id);

          void evolveWorld(); // no return needed
          // returns cell data
          int getCell(int x, int y);
          int getCell(int id);
          // sets cell data in actual world
          void setCell(int x, int y, int status);
          void setCell(int id, int status);
          // since arrays in returs are a bit complicated in c++
          // we'll use 3 functions for world size returns
          int getworldWidth(); // width of world
          int getworldHeigh(); // heigh of world
          int getworldSize(); // total number of cells
          void clearWorld(); // clears world
};



#endif // CABASE_H
