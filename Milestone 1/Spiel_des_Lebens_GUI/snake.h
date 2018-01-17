#ifndef Snake_H
#define Snake_H

#include <cstddef>

using namespace std;


class Snake
{
    /* our Snake has a head only at beginning, rest is body and comes after eating some food.
     * Snake is saved as 5's in our world, in a good object oriented version we would save references to objects, instead of numbers
     * that would allow to have any number of Snakes
     */
public:
    // Snake data
    int Direction = 8;  // direction in which the Snake should move itself
    int Status = 0; // 0 = not exist, 1 = alive, 2 = dead
    int length = 0; //
    int *Body = NULL;  // first item is head, last is tail
    int *BodyStep = NULL;  // used to grow Snake

    Snake();   // instatiates the snake array
    ~Snake();  // unsets all arrays and kills itself
    int move(int newCellid); // moves (evolves) all Snake cells, returns tail id to drop
    int grow(int newCellid); // Snake grows
    void setDir(int newDir);
};

#endif // Snake_H
