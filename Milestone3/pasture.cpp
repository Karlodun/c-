#include "pasture.h"

Pasture::Pasture()
{
    Locations = new int [Population];
    Age = new int [Population];
}

Pasture::~Pasture()
{
    delete [] Locations;
    delete [] Age;
}

int Pasture::Grow(int newID){
    // create and fill BackPack:
    BackPack = new int [Population];
    for (int i=0; i<Population; i++) BackPack[i]=Locations[i];
    // increase population, fix Locations length and copy BackPack back
    Population++;
    Locations = new int [Population];
    for (int i=0; i<Population; i++) Locations[i]=BackPack[i];
    // add new animal to locations:
    Locations[Population]=newID;

    // procede with Age
    for (int i=0; i<Population; i++) BackPack[i]=Age[i];
    Age = new int [Population];
    for (int i=0; i<Population; i++) Age[i]=BackPack[i];
    Age[Population]=0;

    delete [] BackPack;
    return newID;
}

int Pasture::Decay(int deadID){
    Population--;
    BackPack = new int [Population];
    // drop id of dead animal
    // copy all values before dead animal
    for (int i=0; i<deadID; i++) BackPack[i]=Locations[i];
    // copy all values after dead animal
    for (int i=deadID; i<=Population; i++) BackPack[i]=Locations[i+1];
    // recreate and fill Locations
    Locations = new int [Population];
    for (int i=0; i<=Population; i++) Locations[i]=BackPack[i];

    // procede with Age
    for (int i=0; i<deadID; i++) BackPack[i]=Age[i];
    // copy all values after dead animal
    for (int i=deadID; i<=Population; i++) BackPack[i]=Age[i+1];
    // recreate and fill Locations
    Age = new int [Population];
    for (int i=0; i<=Population; i++) Age[i]=BackPack[i];

    delete [] BackPack;
    return deadID;
}

int Pasture::Move(int herdID, int newID, int newIDType){
    /* randomization could be realized with a herdIds shuffle
     * like:
     * random_shuffle(std::begin(herdIDs), std::end(herdIDs));
     * neither the necessary variables, nor functionality is implemented here
     * since there is just no need
     */
    if (newIDType==1) Age[herdID]=0;//we had some food, reset age
     else Age[herdID]++; // we had no food, thus olden
    if (Age[herdID]>maxAge) return 0;  // we tell the caller, that cell has reached end of life
     else Locations[herdID] = newID;
    return 1;
}

