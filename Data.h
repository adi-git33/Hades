#pragma once
#include "Map.h"

class Data
{
private:
    Map *MapsData;
    Room *RoomsData;
    int NumOfMaps;

public:
    Data();
    Data(Room *NewRoomsData, int RoomArrSize);
    ~Data();
    // Getters
    // Setters
    // Operators
    // Funcs
    Map* AddMap(Map &NewMap);
};
