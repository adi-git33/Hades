#include "Data.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

Data::Data()
{
    RoomsData = NULL;
    MapsData = NULL;
}

Data::Data(Room *NewRoomsData, int RoomArrSize)
{
    RoomsData = new Room[RoomArrSize];
    RoomsData = NewRoomsData;
    MapsData = new Map[6];
    if (MapsData == NULL)
    {
        cout << "Null argument Map Constractor" << endl;
        throw(1);
    }
    MapsData = NULL;
    NumOfMaps = 0;
}

Data::~Data()
{
    delete[] RoomsData;
    delete[] MapsData;
}

Map *Data::AddMap(Map &NewMap)
{
    if (MapsData == NULL)
    {
        Map *Tmp = &NewMap;
        MapsData = Tmp;
        NumOfMaps = 1;
        return MapsData;
    }

    if (strcmp(MapsData->GetFloorName(), NewMap.GetFloorName()) == 0)
    {
        cout << "error, cannot have maps with the same name" << endl;
        return MapsData;
    }

    NumOfMaps++;

    if (NumOfMaps > 6)
    {
        cout << "Cannot add more maps" << endl;
        NumOfMaps = 6;
        return MapsData;
    }
    else
    {
        MapsData[NumOfMaps - 1] = NewMap;
        return MapsData;
    }
}
