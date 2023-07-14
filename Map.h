#pragma once
#include "Room.h"

class Map
{
private:
    char *FloorName;
    Room *Rooms;
    int NumOfRooms;
    Room *CurrentRoom;

public:
Map();
    Map(char *NewFloorName);
    ~Map();
    Map(const Map &CopyMap);
    // Getters
    inline Room *GetCurrentRoom() { return CurrentRoom; };
    inline Room *GetRooms() { return Rooms; };
    inline char *GetFloorName() { return FloorName; };
    // Setters
    inline void SetCurrentRoom(Room *NewCurrRoom) { CurrentRoom = NewCurrRoom; };
    // Operators
    Map &operator=(const Map &AssignedMap);
    const Map operator+(const Map &AddedMap);
    Map &operator+=(Map &AddedMap);
    // Funcs
    Room *CheckExistingRoomRec(Room *MapRoomList, Room *CheckRoom);
    Room *GetUnfullRoom(Room *CheckedRooms);
    Room *AddRoom(Room &AddedRoom, Direction NewRoomDirection);
};