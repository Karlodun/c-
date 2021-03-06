#ifndef PASTURE_H
#define PASTURE_H

#include <cstddef>


class Pasture
{
public:
    Pasture();
    ~Pasture();

    int Population = 0; // amount of pasture animals
    int maxAge=10; // if animal surpasses this age it dies
    int *Locations = NULL;  // cell ids of all the pasture animals
    int *Age = NULL;  // age of all the pasture animals
    int *BackPack = NULL;  // used for array changes

    int Grow(int newID);  //returns the world id where the animal should be set
    int Decay(int deadID);  //returns the world id where animal should be removed
    int Move(int herdID, int newID, int newIDType);  // expected types: 0 for empty, 1 for food
};

#endif // PASTURE_H
