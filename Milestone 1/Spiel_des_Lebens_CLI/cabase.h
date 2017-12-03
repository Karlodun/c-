#ifndef CABASE_H
#define CABASE_H

#include <cstddef>

using namespace std;

class CAbase
{
     private :
    // worldSize is there just to prevent repetitive calculation where possible
          int *World = NULL;
          int *newWorld = NULL;
          int moveDir = 0; // stop,up,left,down,right: 0,8,4,2,6
          int snakeHeadCell = 0; // cell id where snake head resides, head has biggest number
          int snakeStatus = 0; // 0 = not exist, 1 = alive, 2 = dead
     public :
          int Nx, Ny, worldSize;
          int alive=0, World_age=0;
          // constructor
          CAbase(int size_x, int size_y);
          // destructor:
          ~CAbase();
          void resizeWorld(int size_x, int size_y); // returns size if World
          void createWorld(); // returns size of World
          int cellId(int x, int y); // returns actual id for x and y coordinates
          // flip a Cell in World
          void flipCell(int x, int y);
          void flipCell(int id);
          // evolve a Cell of world and save in newWorld
          int evolveCell(int x, int y);
          int evolveCell(int id);
          // cound all living neighbors, needed for evolveCell
          int livingNeighbors(int x, int y);
          int livingNeighbors(int id);

          int randomObjId(); // for random placement
          void setSnakeHead(int id); //
          int nextSnakePart(int id); // just with id, since no manual move intended
          int newSnakeId(int id, int direction);
          void moveSnakeCell(int id, int direction);
          int moveSnake(); //returns 1 if OK, 2 on death
          void setDir(int newDir);

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
