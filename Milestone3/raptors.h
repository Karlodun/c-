#ifndef RAPTORS_H
#define RAPTORS_H

#include <cstddef>


class Raptors
{
public:
    Raptors();
    ~Raptors();

    int Population = 0; // amount of Raptors animals
    int maxAge=10; // if animal surpasses this age it dies
    int *Locations = NULL;  // cell ids of all the Raptors animals
    int *Age = NULL;  // age of all the Raptors animals
    int *BackPack = NULL;  // used for array changes

    int Grow(int newID);  //returns the world id where the animal should be set
    int Decay(int deadID);  //returns the world id where animal should be removed
    int Move(int herdID, int newID, int newIDType);  // expected types: 0 for empty, 1 for food
};

#endif // RAPTORS_H
