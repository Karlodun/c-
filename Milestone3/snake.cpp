#include "Snake.h"

Snake::Snake()
{
    Body = new int[length];
}

Snake::~Snake(){
    delete [] Body;
    delete [] BodyStep;
}

int Snake::move(int newCellid){
    /* Snake is moved by moving the head to new cell
     * and by dropping the tail.
     */
    int tailId=Body[0];
    for (int i=0; i<length; i++) Body[i]=Body[i+1];
    Body[-1] = newCellid;
    return tailId;
}

int Snake::grow(int newCellid){
    length++;
    BodyStep = new int[length];
    for (int i=0; i<length; i++) BodyStep[i]=Body[i];
    Body = new int[length];
    for (int i=0; i<length; i++) Body[i]=BodyStep[i];
    Body[length]=newCellid;
    delete [] BodyStep;
    return newCellid;
}
