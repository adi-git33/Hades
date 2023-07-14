
#include "Map.h"
#include <iostream>
#include <cstring>
#include <Queue>

using namespace std;

Map::Map()
{
    FloorName = strdup("Default");
    Rooms = new Room((char *)"Start");
    NumOfRooms = 0;
    CurrentRoom = Rooms;
}

Map::Map(char *NewFloorName)
{
    FloorName = strdup(NewFloorName);
    Rooms = new Room((char *)"Start");
    NumOfRooms = 0;
    CurrentRoom = Rooms;
}

Map::~Map()
{
    free(FloorName);
    if (Rooms != NULL)
        delete[] Rooms;
    if (CurrentRoom != NULL)
        delete[] CurrentRoom;
}

Map::Map(const Map &CopyMap)
{
    FloorName = strdup(CopyMap.FloorName);
    Rooms = CopyMap.Rooms;
    NumOfRooms = CopyMap.NumOfRooms;
}

Map &Map::operator=(const Map &AssignedMap)
{
    FloorName = strdup(AssignedMap.FloorName);
    Rooms = AssignedMap.Rooms;
    NumOfRooms = AssignedMap.NumOfRooms;
    return *this;
}

const Map Map::operator+(const Map &AddedMap)
{
    Map TmpMap = NULL;
    if (CurrentRoom == NULL || AddedMap.Rooms == NULL)
    {
        cout << "Map doesn't exist." << endl;
        return TmpMap;
    }

    if (strcmp(FloorName, AddedMap.FloorName) == 0)
    {
        cout << "Map already exists." << endl;
        return TmpMap;
    }

    TmpMap = *this;
    Map TmpAddedMap = AddedMap;
    Room *TmpRoom = this->GetUnfullRoom(this->Rooms);
    Room *TmpAddedRoom = TmpAddedMap.GetUnfullRoom(TmpMap.Rooms);

    int TmpRoomDirection = TmpRoom->CheckEmptyDirection();
    int AddedRoomDirection = TmpAddedRoom->CheckEmptyDirection();

    if (TmpRoomDirection == 0)
    {
        if (AddedRoomDirection == 0)
        {
            TmpRoom->SetNorth(TmpAddedRoom);
            TmpAddedRoom->SetNorth(TmpRoom);
            return TmpMap;
        }

        else if (AddedRoomDirection == 1)
        {
            TmpRoom->SetNorth(TmpAddedRoom);
            TmpAddedRoom->SetSouth(TmpRoom);
            return TmpMap;
        }

        else if (AddedRoomDirection == 2)
        {
            TmpRoom->SetNorth(TmpAddedRoom);
            TmpAddedRoom->SetWest(TmpRoom);
            return TmpMap;
        }

        else
        {
            TmpRoom->SetNorth(TmpAddedRoom);
            TmpAddedRoom->SetEast(TmpRoom);
            return TmpMap;
        }
    }

    else if (TmpRoomDirection == 1)
    {
        if (AddedRoomDirection == 0)
        {
            TmpRoom->SetSouth(TmpAddedRoom);
            TmpAddedRoom->SetNorth(TmpRoom);
            return TmpMap;
        }

        else if (AddedRoomDirection == 1)
        {
            TmpRoom->SetSouth(TmpAddedRoom);
            TmpAddedRoom->SetSouth(TmpRoom);
            return TmpMap;
        }

        else if (AddedRoomDirection == 2)
        {
            TmpRoom->SetSouth(TmpAddedRoom);
            TmpAddedRoom->SetWest(TmpRoom);
            return TmpMap;
        }

        else
        {
            TmpRoom->SetSouth(TmpAddedRoom);
            TmpAddedRoom->SetEast(TmpRoom);
            return TmpMap;
        }
    }

    else if (TmpRoomDirection == 2)
    {
        if (AddedRoomDirection == 0)
        {
            TmpRoom->SetWest(TmpAddedRoom);
            TmpAddedRoom->SetNorth(TmpRoom);
            return TmpMap;
        }

        else if (AddedRoomDirection == 1)
        {
            TmpRoom->SetWest(TmpAddedRoom);
            TmpAddedRoom->SetSouth(TmpRoom);
            return TmpMap;
        }

        else if (AddedRoomDirection == 2)
        {
            TmpRoom->SetWest(TmpAddedRoom);
            TmpAddedRoom->SetWest(TmpRoom);
            return TmpMap;
        }

        else
        {
            TmpRoom->SetWest(TmpAddedRoom);
            TmpAddedRoom->SetEast(TmpRoom);
            return TmpMap;
        }
    }

    else
    {
        if (AddedRoomDirection == 0)
        {
            TmpRoom->SetEast(TmpAddedRoom);
            TmpAddedRoom->SetNorth(TmpRoom);
            return TmpMap;
        }

        else if (AddedRoomDirection == 1)
        {
            TmpRoom->SetEast(TmpAddedRoom);
            TmpAddedRoom->SetSouth(TmpRoom);
            return TmpMap;
        }

        else if (AddedRoomDirection == 2)
        {
            TmpRoom->SetEast(TmpAddedRoom);
            TmpAddedRoom->SetWest(TmpRoom);
            return TmpMap;
        }

        else
        {
            TmpRoom->SetEast(TmpAddedRoom);
            TmpAddedRoom->SetEast(TmpRoom);
            return TmpMap;
        }
    }
}

Map &Map::operator+=(Map &AddedMap)
{
    if (CurrentRoom == NULL || AddedMap.Rooms == NULL)
    {
        cout << "Map doesn't exist." << endl;
        return *this;
    }

    if (strcmp(FloorName, AddedMap.FloorName) == 0)
    {
        cout << "Map already exists." << endl;
        return *this;
    }

    Room *TmpRoom = CurrentRoom;
    int TmpRoomDirection = TmpRoom->CheckEmptyDirection();
    if (TmpRoomDirection == -1)
    {
        TmpRoom = this->GetUnfullRoom(this->Rooms);
        TmpRoomDirection = TmpRoom->CheckEmptyDirection();
    }


    Room *TmpAddedRoom = AddedMap.CurrentRoom;
    int AddedRoomDirection = TmpAddedRoom->CheckEmptyDirection();
    if (AddedRoomDirection == -1)
    {
        TmpAddedRoom = AddedMap.GetUnfullRoom(AddedMap.Rooms);
        AddedRoomDirection = TmpAddedRoom->CheckEmptyDirection();
    }

    if (TmpRoomDirection == 0)
    {
        if (AddedRoomDirection == 0)
        {
            TmpRoom->SetNorth(TmpAddedRoom);
            TmpAddedRoom->SetNorth(TmpRoom);
            return *this;
        }

        else if (AddedRoomDirection == 1)
        {
            TmpRoom->SetNorth(TmpAddedRoom);
            TmpAddedRoom->SetSouth(TmpRoom);
            return *this;
        }

        else if (AddedRoomDirection == 2)
        {
            TmpRoom->SetNorth(TmpAddedRoom);
            TmpAddedRoom->SetWest(TmpRoom);
            return *this;
        }
        else
        {
            TmpRoom->SetNorth(TmpAddedRoom);
            TmpAddedRoom->SetEast(TmpRoom);
            return *this;
        }
    }

    else if (TmpRoomDirection == 1)
    {
        if (AddedRoomDirection == 0)
        {
            TmpRoom->SetSouth(TmpAddedRoom);
            TmpAddedRoom->SetNorth(TmpRoom);
            return *this;
        }

        else if (AddedRoomDirection == 1)
        {
            TmpRoom->SetSouth(TmpAddedRoom);
            TmpAddedRoom->SetSouth(TmpRoom);
            return *this;
        }

        else if (AddedRoomDirection == 2)
        {
            TmpRoom->SetSouth(TmpAddedRoom);
            TmpAddedRoom->SetWest(TmpRoom);
            return *this;
        }

        else
        {
            TmpRoom->SetSouth(TmpAddedRoom);
            TmpAddedRoom->SetEast(TmpRoom);
            return *this;
        }
    }

    else if (TmpRoomDirection == 2)
    {
        if (AddedRoomDirection == 0)
        {
            TmpRoom->SetWest(TmpAddedRoom);
            TmpAddedRoom->SetNorth(TmpRoom);
            return *this;
        }

        else if (AddedRoomDirection == 1)
        {
            TmpRoom->SetWest(TmpAddedRoom);
            TmpAddedRoom->SetSouth(TmpRoom);
            return *this;
        }

        else if (AddedRoomDirection == 2)
        {
            TmpRoom->SetWest(TmpAddedRoom);
            TmpAddedRoom->SetWest(TmpRoom);
            return *this;
        }

        else
        {
            TmpRoom->SetWest(TmpAddedRoom);
            TmpAddedRoom->SetEast(TmpRoom);
            return *this;
        }
    }

    else
    {
        if (AddedRoomDirection == 0)
        {
            TmpRoom->SetEast(TmpAddedRoom);
            TmpAddedRoom->SetNorth(TmpRoom);
            return *this;
        }

        else if (AddedRoomDirection == 1)
        {
            TmpRoom->SetEast(TmpAddedRoom);
            TmpAddedRoom->SetSouth(TmpRoom);
            return *this;
        }

        else if (AddedRoomDirection == 2)
        {
            TmpRoom->SetEast(TmpAddedRoom);
            TmpAddedRoom->SetWest(TmpRoom);
            return *this;
        }

        else
        {
            TmpRoom->SetEast(TmpAddedRoom);
            TmpAddedRoom->SetEast(TmpRoom);
            return *this;
        }
    }
}

Room *Map::CheckExistingRoomRec(Room *MapRoomList, Room *CheckRoom)
{
    if (MapRoomList == nullptr)
        return MapRoomList;

    queue<Room *> RoomQueue;

    MapRoomList->SetVisited(false);
    RoomQueue.push(MapRoomList);

    while (RoomQueue.empty() == false)
    {
        Room *CurrRoom = RoomQueue.front();
        CurrRoom->SetVisited(false);
        RoomQueue.pop();

        if (CurrRoom->GetNorth() != NULL && CurrRoom->GetNorth()->GetVisited() == true)
            RoomQueue.push(CurrRoom->GetNorth());

        if (CurrRoom->GetSouth() != NULL && CurrRoom->GetSouth()->GetVisited() == true)
            RoomQueue.push(CurrRoom->GetSouth());

        if (CurrRoom->GetWest() != NULL && CurrRoom->GetWest()->GetVisited() == true)
            RoomQueue.push(CurrRoom->GetWest());

        if (CurrRoom->GetEast() != NULL && CurrRoom->GetEast()->GetVisited() == true)
            RoomQueue.push(CurrRoom->GetEast());
    }

    MapRoomList->SetVisited(true);
    RoomQueue.push(MapRoomList);

    Room *FindRoom = new Room((char *)"FindRoom");

    while (!RoomQueue.empty())
    {
        Room *CurrRoom = RoomQueue.front();
        if (strcmp(CurrRoom->GetRoomName(), CheckRoom->GetRoomName()) == 0)
            FindRoom = CurrRoom;
        RoomQueue.pop();

        if ((CurrRoom->GetNorth()) != NULL && (!CurrRoom->GetNorth()->GetVisited()))
            RoomQueue.push(CurrRoom->GetNorth());

        if ((CurrRoom->GetSouth()) != NULL && (!CurrRoom->GetSouth()->GetVisited()))
            RoomQueue.push(CurrRoom->GetSouth());

        if ((CurrRoom->GetWest()) != NULL && (!CurrRoom->GetWest()->GetVisited()))
            RoomQueue.push(CurrRoom->GetWest());

        if ((CurrRoom->GetEast()) != NULL && (!CurrRoom->GetEast()->GetVisited()))
            RoomQueue.push(CurrRoom->GetEast());
    }
    if (strcmp(FindRoom->GetRoomName(), "FindRoom") == 0)
        return NULL;
    else
        return FindRoom;
}

Room *Map::GetUnfullRoom(Room *CheckedRooms)
{
    if (CheckedRooms == nullptr)
        return CheckedRooms;

    queue<Room *> RoomQueue;

    CheckedRooms->SetVisited(false);
    RoomQueue.push(CheckedRooms);

    while (RoomQueue.empty() == false)
    {
        Room *CurrRoom = RoomQueue.front();
        CurrRoom->SetVisited(false);
        RoomQueue.pop();

        if (CurrRoom->GetNorth() != NULL && CurrRoom->GetNorth()->GetVisited() == true)
            RoomQueue.push(CurrRoom->GetNorth());

        if (CurrRoom->GetSouth() != NULL && CurrRoom->GetSouth()->GetVisited() == true)
            RoomQueue.push(CurrRoom->GetSouth());

        if (CurrRoom->GetWest() != NULL && CurrRoom->GetWest()->GetVisited() == true)
            RoomQueue.push(CurrRoom->GetWest());

        if (CurrRoom->GetEast() != NULL && CurrRoom->GetEast()->GetVisited() == true)
            RoomQueue.push(CurrRoom->GetEast());
    }

    CheckedRooms->SetVisited(true);
    RoomQueue.push(CheckedRooms);

    Room *FindRoom = new Room((char *)"FindRoom");

    while (!RoomQueue.empty())
    {
        Room *CurrRoom = RoomQueue.front();
        if (CurrRoom->CheckIfFull() == false)
        {
            FindRoom = CurrRoom;
            RoomQueue.pop();
            break;
        }

        if ((CurrRoom->CheckIfFull() == true) && (!CurrRoom->GetNorth()->GetVisited()))
            RoomQueue.push(CurrRoom->GetNorth());

        if ((CurrRoom->CheckIfFull() == true) && (!CurrRoom->GetSouth()->GetVisited()))
            RoomQueue.push(CurrRoom->GetSouth());

        if ((CurrRoom->CheckIfFull() == true) && (!CurrRoom->GetWest()->GetVisited()))
            RoomQueue.push(CurrRoom->GetWest());

        if ((CurrRoom->CheckIfFull() == true) && (!CurrRoom->GetEast()->GetVisited()))
            RoomQueue.push(CurrRoom->GetEast());
    }
    return FindRoom;
}

Room *Map::AddRoom(Room &AddedRoom, Direction NewRoomDirection)
{
    if (strcmp(CurrentRoom->GetRoomName(), "Start") == 0)
    {
        CurrentRoom = &AddedRoom;
        Rooms = &AddedRoom;
        NumOfRooms = 1;
        return Rooms;
    }
    Room *FindRoom = new Room();
    FindRoom = CheckExistingRoomRec(Rooms, &AddedRoom);

    if (FindRoom != NULL)
    {
        if (strcmp(FindRoom->GetRoomName(), AddedRoom.GetRoomName()) == 0)
        {
            *FindRoom += AddedRoom;
            CurrentRoom = FindRoom;
            return CurrentRoom;
        }
    }
    if (CurrentRoom->CheckIfFull() == true)
        CurrentRoom = this->GetUnfullRoom(Rooms);
    int AddedDirection = AddedRoom.CheckEmptyDirection();

    if (NewRoomDirection == North)
    {
        if (CurrentRoom->GetNorth() != NULL)
        {
            cout << "There is already a room in this direction." << endl;
            return Rooms;
        }
        else if (AddedDirection == 0)
        {
            CurrentRoom->SetNorth(&AddedRoom);
            AddedRoom.SetNorth(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
        else if (AddedDirection == 1)
        {
            CurrentRoom->SetNorth(&AddedRoom);
            AddedRoom.SetSouth(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
        else if (AddedDirection == 2)
        {
            CurrentRoom->SetNorth(&AddedRoom);
            AddedRoom.SetWest(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
        else
        {
            CurrentRoom->SetNorth(&AddedRoom);
            AddedRoom.SetEast(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
    }

    else if (NewRoomDirection == South)
    {
        if (CurrentRoom->GetSouth() != NULL)
        {
            cout << "There is already a room in this direction." << endl;
            return Rooms;
        }
        else if (AddedDirection == 0)
        {
            CurrentRoom->SetSouth(&AddedRoom);
            AddedRoom.SetNorth(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
        else if (AddedDirection == 1)
        {
            CurrentRoom->SetSouth(&AddedRoom);
            AddedRoom.SetSouth(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
        else if (AddedDirection == 2)
        {
            CurrentRoom->SetSouth(&AddedRoom);
            AddedRoom.SetWest(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
        else
        {
            CurrentRoom->SetSouth(&AddedRoom);
            AddedRoom.SetEast(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
    }

    else if (NewRoomDirection == West)
    {
        if (CurrentRoom->GetWest() != NULL)
        {
            cout << "There is already a room in this direction." << endl;
            return Rooms;
        }
        else if (AddedDirection == 0)
        {
            CurrentRoom->SetWest(&AddedRoom);
            AddedRoom.SetNorth(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
        else if (AddedDirection == 1)
        {
            CurrentRoom->SetWest(&AddedRoom);
            AddedRoom.SetSouth(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
        else if (AddedDirection == 2)
        {
            CurrentRoom->SetWest(&AddedRoom);
            AddedRoom.SetWest(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
        else
        {
            CurrentRoom->SetWest(&AddedRoom);
            AddedRoom.SetEast(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
    }

    else
    {
        if (CurrentRoom->GetSouth() != NULL)
        {
            cout << "There is already a room in this direction." << endl;
            return Rooms;
        }
        else if (AddedDirection == 0)
        {
            CurrentRoom->SetEast(&AddedRoom);
            AddedRoom.SetNorth(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
        else if (AddedDirection == 1)
        {
            CurrentRoom->SetEast(&AddedRoom);
            AddedRoom.SetSouth(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
        else if (AddedDirection == 2)
        {
            CurrentRoom->SetEast(&AddedRoom);
            AddedRoom.SetWest(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
        else
        {
            CurrentRoom->SetEast(&AddedRoom);
            AddedRoom.SetEast(CurrentRoom);
            NumOfRooms++;
            return Rooms;
        }
    }
}
