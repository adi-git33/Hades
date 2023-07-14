
#include <cstring>
#include "Room.h"

using namespace std;

Room::Room()
{
    RoomName = strdup("Default");
    Items = new Item[6];
    if (Items == NULL)
    {
        cout << "Null argument Room Items Array" << endl;
        throw(1);
    }
    Monsters = new Monster[6];
    if (Monsters == NULL)
    {
        cout << "Null argument Room Monsters Array" << endl;
        throw(1);
    }
    North = NULL;
    South = NULL;
    East = NULL;
    West = NULL;
    ItemArrSize = 0;
    MonsterArrSize = 0;
    Visited = false;
}

Room::Room(char *NewRoomName)
{
    RoomName = strdup(NewRoomName);
    Items = new Item[6];
    if (Items == NULL)
    {
        cout << "Null argument Room Items Array" << endl;
        throw(1);
    }
    Monsters = new Monster[6];
    if (Monsters == NULL)
    {
        cout << "Null argument Room Monsters Array" << endl;
        throw(1);
    }
    North = NULL;
    South = NULL;
    East = NULL;
    West = NULL;
    ItemArrSize = 0;
    MonsterArrSize = 0;
    Visited = false;
}

Room::Room(char *NewRoomName, Item *RoomsItems, int RoomItemSize, Monster *RoomsMonsters, int RoomMonsterSize)
{
    RoomName = strdup(NewRoomName);
    ItemArrSize = RoomItemSize;
    MonsterArrSize = RoomMonsterSize;

    Items = new Item[6];
    if (Items == NULL)
    {
        cout << "Room constractor Items Array Null Argument" << endl;
        throw(1);
    }
    Items = RoomsItems;

    Monsters = new Monster[6];
    if (Monsters == NULL)
    {
        cout << "Room Constractor Monster Array Null Argument" << endl;
        throw(1);
    }
    Monsters = RoomsMonsters;

    Visited = false;
    North = NULL;
    South = NULL;
    East = NULL;
    West = NULL;
}

Room::~Room()
{
    if (RoomName != NULL)
        free(RoomName);

    if (Items != NULL)
        free(Items);

    if (Monsters != NULL)
        free(Monsters);

    if (North != NULL)
        delete[] North;
    if (South != NULL)
        delete[] South;
    if (West != NULL)
        delete[] West;
    if (East != NULL)
        delete[] East;
}

Room::Room(const Room &CopyRoom)
{
    RoomName = strdup(CopyRoom.RoomName);

    cout << ItemArrSize << endl;
    cout << CopyRoom.ItemArrSize << endl;

    ItemArrSize = CopyRoom.ItemArrSize;
    MonsterArrSize = CopyRoom.MonsterArrSize;

    Items = CopyRoom.Items;

    Monsters = CopyRoom.Monsters;

    North = CopyRoom.North;
    South = CopyRoom.South;
    West = CopyRoom.West;
    East = CopyRoom.East;
    Visited = CopyRoom.Visited;
}

void Room::SetNorth(Room *AddedRoom)
{
    if (North == NULL)
    {
        North = AddedRoom;
        cout << "The room(s) got added to the north side" << endl;
    }
    else
        cout << "not available option" << endl;
}

void Room::SetSouth(Room *AddedRoom)
{
    if (South == NULL)
    {
        South = AddedRoom;
        cout << "The room(s) got added to the south side" << endl;
    }
    else
        cout << "not available option" << endl;
}

void Room::SetWest(Room *AddedRoom)
{
    if (West == NULL)
    {
        West = AddedRoom;
        cout << "The room(s) got added to the west side" << endl;
    }
    else
        cout << "not available option" << endl;
}

void Room::SetEast(Room *AddedRoom)
{
    if (East == NULL)
    {
        East = AddedRoom;
        cout << "The room(s) got added to the east side" << endl;
    }
    else
        cout << "not available option" << endl;
}

Room &Room::operator=(const Room &AssignedRoom)
{

    RoomName = strdup(AssignedRoom.RoomName);

    ItemArrSize = AssignedRoom.ItemArrSize;
    MonsterArrSize = AssignedRoom.MonsterArrSize;

    Items = AssignedRoom.Items;
    Monsters = AssignedRoom.Monsters;

    North = AssignedRoom.North;
    South = AssignedRoom.South;
    West = AssignedRoom.West;
    East = AssignedRoom.East;
    return *this;
}

ostream &operator<<(ostream &os, const Room *CurrentRoom)
{
    Item *TmpItems = CurrentRoom->Items;
    os << "\t--Room Items--" << endl;
    if (CurrentRoom->ItemArrSize == 0)
        os << "There are no items in this room." << endl;

    for (int i = 0; i < CurrentRoom->ItemArrSize; i++)
    {
        os << (i + 1) << ") " << TmpItems[i].GetItemName() << ", Rarity: ";
        TmpItems[i].PrintRarity();
        os << endl;
    }

    os << "\t--Room Monsters--" << endl;
    Monster *TmpMonsters = CurrentRoom->Monsters;

    if (CurrentRoom->MonsterArrSize == 0)
        os << "There are no monsters in this room." << endl;

    for (int i = 0; i < CurrentRoom->MonsterArrSize; i++)
        os << (i + 1) << ") " << TmpMonsters[i].GetMobName() << ",  Level: " << TmpMonsters[i].GetMobLevel() << endl;

    return os;
}

Room &Room::operator+=(const Room &AddedRoom)
{
    int TmpItemAddSize = AddedRoom.ItemArrSize;
    int tmpItemSize = ItemArrSize;

    Item *TmpAddedItems = new Item[6];
    if (TmpAddedItems == NULL)
    {
        cout << "Room Operator+= Items array NULL argument" << endl;
        throw(1);
    }
    for (int i = 0; i < TmpItemAddSize; i++)
        TmpAddedItems[i] = AddedRoom.Items[i];

    Item *TmpItems = new Item[6];
    if (TmpItems == NULL)
    {
        cout << "Room Operator+= Items array NULL argument" << endl;
        throw(1);
    }
    for (int i = 0; i < tmpItemSize; i++)
        TmpItems[i] = Items[i];

    int Index = -3;
    int DoubleItem = 0;
    int ItemLegendary = 0;


    for (int i = 0; i < TmpItemAddSize; i++)
    {
        for (int j = 0; j < tmpItemSize; j++) // search for existing item
        {
            if (strcmp(TmpItems[j].GetItemName(), TmpAddedItems[i].GetItemName()) == 0)
            {
                if (Index >= 0)
                    DoubleItem++;

                Index = j;

                if (TmpItems[j].GetItemRarity() == 3)
                    ItemLegendary++;
            }
        }

        if (Index >= 0)
        {

            if (ItemLegendary > DoubleItem) // already has legendary with this name, add new item to array
            {

                Item TmpNewItem(TmpAddedItems[i].GetItemName(), 0);
                ItemArrSize++;
                if (ItemArrSize > 6)
                {
                    cout << "Room Items full, cannot add new item." << endl;
                    ItemArrSize = 6;
                    break;
                }
                else
                    Items[ItemArrSize - 1] = TmpNewItem;
            }
            else // item already exist, rank up the doubled item in his last apperance
            {
                Items[Index]++;
            }
        }
        else // item doesnt exist, add item to array
        {
            Item TmpNewItem(TmpAddedItems[i].GetItemName(), TmpAddedItems[i].GetItemRarity());
            ItemArrSize++;
            if (ItemArrSize > 6)
            {
                cout << "Room Items full, cannot add new item." << endl;
                ItemArrSize = 6;
                break;
            }
            else
                Items[ItemArrSize - 1] = TmpNewItem;
        }
        Index = -3;
        DoubleItem = 0;
        ItemLegendary = 0;
    }

    Monster *TmpAddedMonsters = new Monster[6];
    if (TmpAddedMonsters == NULL)
    {
        cout << "Room Operator+= Monster array NULL argument" << endl;
        throw(1);
    }
    TmpAddedMonsters = AddedRoom.Monsters;

    Monster *TmpMonsters = new Monster[6];
    if (TmpMonsters == NULL)
    {
        cout << "Room Operator+= Monster array NULL argument" << endl;
        throw(1);
    }
    TmpMonsters = Monsters;

    Index = -3;
    int DoubleMob = 0;
    int MobLevelFive = 0;

    int TmpMobAddSize = AddedRoom.MonsterArrSize;
    int TmpMobSize = MonsterArrSize;

    for (int i = 0; i < TmpMobAddSize; i++)
    {
        for (int j = 0; j < TmpMobSize; j++) // search for existing item
        {
            if (strcmp(TmpMonsters[j].GetMobName(), TmpAddedMonsters[i].GetMobName()) == 0)
            {
                if (Index >= 0)
                    DoubleMob++;

                Index = j;

                if (TmpMonsters[j].GetMobLevel() == 5)
                    MobLevelFive++;
            }
        }

        if (Index >= 0)
        {

            if (MobLevelFive > DoubleMob) // already has legendary with this name, add new item to array
            {
                Monster TmpMonster(TmpAddedMonsters[i].GetMobName(), 1);
                MonsterArrSize++;
                if (MonsterArrSize > 6)
                {
                    cout << "Room Monsters full, cannot add new Monster." << endl;
                    MonsterArrSize = 6;
                    break;
                }
                else
                    Monsters[MonsterArrSize - 1] = TmpMonster;
            }
            else // item already exist, rank up the doubled item in his last apperance
            {
                Monsters[Index]++;
            }
        }
        else // item doesnt exist, add item to array
        {
            Monster TmpNewMonster(TmpAddedMonsters[i].GetMobName(), TmpAddedMonsters[i].GetMobLevel());
            MonsterArrSize++;
            if (MonsterArrSize > 6)
            {
                cout << "Room Monsters full, cannot add new Monster." << endl;
                MonsterArrSize = 6;
                break;
            }
            else
                Monsters[MonsterArrSize - 1] = TmpNewMonster;
        }
        Index = -3;
        int DoubleMob = 0;
        int MobLevelFive = 0;
    }
    return *this;
}

bool Room::CheckIfFull()
{
    if ((North != NULL) && (South != NULL) && (West != NULL) && (East != NULL))
        return true;
    else
        return false;
}

int Room::CheckEmptyDirection()
{
    if (North == NULL)
        return 0;
    else if (South == NULL)
        return 1;
    else if (West == NULL)
        return 2;
    else if (East == NULL)
        return 3;
    else
        return -1;
}
