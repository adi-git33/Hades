
#pragma once
#include "Monster.h"
#include "Item.h"
#include "Direction.h"
#include <iostream>

using std::ostream;

class Room
{
private:
    char *RoomName;
    Item *Items;
    Monster *Monsters;
    Room *North;
    Room *South;
    Room *East;
    Room *West;
    int ItemArrSize;
    int MonsterArrSize;
    bool Visited;

public:
    Room();
    Room(char *NewRoomName);
    Room(char *NewRoomName, Item *RoomsItems, int RoomItemSize, Monster *RoomsMonsters, int RoomMonsterSize);
    ~Room();
    Room(const Room &CopyRoom);
    // Getter
    inline char *GetRoomName() { return RoomName; };
    inline Room *GetNorth() { return North; };
    inline Room *GetSouth() { return South; };
    inline Room *GetWest() { return West; };
    inline Room *GetEast() { return East; };
    inline int GetItemArrSize() { return ItemArrSize;};
    inline int GetMonsterArrSize() { return MonsterArrSize;};
    inline bool GetVisited() { return Visited;};
    // Setter
    void SetNorth(Room *AddedRoom);
    void SetSouth(Room *AddedRoom);
    void SetWest(Room *AddedRoom);
    void SetEast(Room *AddedRoom);
    inline void SetVisited(bool SettedVisited) {Visited = SettedVisited;};
    // Operators
    Room &operator=(const Room &AssignedRoom);
    friend ostream &operator<<(ostream &os, const Room *CurrentRoom);
    Room &operator+=(const Room &AddedRoom);
    // Funcs
    bool CheckIfFull(); // returns true if there is no location to add a room
    int CheckEmptyDirection();
};
