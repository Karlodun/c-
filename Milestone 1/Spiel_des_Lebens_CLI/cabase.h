#ifndef CABASE_H
#define CABASE_H

#include <cstddef>

using namespace std;

class CAbase
{
     public :
          // world metrics and arrays
          int Nx, Ny, worldSize;
          int alive=0, World_age=0;
          int *World = NULL;
          int *newWorld = NULL;

          // snake data
          int snakeHeadCell = 0; // cell id where snake head resides, head has biggest number
          int snakeStatus = 0; // 0 = not exist, 1 = alive, 2 = dead

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

          int randomObjId(); // returns id of a random empty cell
          void setSnakeHead(int id); // places snakes head with direction, and saves heads id
          int nextSnakePart(int id); // looks for next snake part, so that we don't have to check the whole field again
          int newSnakeId(int id, int direction);  // calculates the id, where the next snake part should be moved
          int moveSnakeHead();  // moves snakes part in specific direction and checks snakes status
          void moveSnake(); //moves (evolves) all snake cells (only)
          void setDir(int newDir);

          void evolveWorld(); // no return needed
          // returns cell data
          int getCell(int x, int y){return getCell(cellId(x,y));};
          int getCell(int id);
          // sets cell data in actual world
          void setCell(int x, int y, int status){setCell(cellId(x,y), status);}
          void setCell(int id, int status);
          // since arrays in returs are a bit complicated in c++
          // we'll use 3 functions for world size returns
          void clearWorld(); // clears world
};

#endif // CABASE_H
