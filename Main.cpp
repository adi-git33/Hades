
#include "Game.h"
#include <iostream>
#include <cstring>

using namespace std;

int main()
{

    Item ItemsCollection[7]{
        Item((char *)"Charon's Obol", 0),
        Item((char *)"Centaur Heart", 1),
        Item((char *)"Pom of Power", 2),
        Item((char *)"Daedalus Hammer", 2),
        Item((char *)"Gemstones", 1),
        Item((char *)"Chthonic Keys", 3),
        Item((char *)"Nectar", 3)};

    int ItemSetSize = 2;

    Item ItemsSet1[2]{
        ItemsCollection[0],
        ItemsCollection[4]};

    Item ItemsSet2[2]{
        ItemsCollection[1],
        ItemsCollection[2]};

    Item ItemsSet3[2]{
        ItemsCollection[5],
        ItemsCollection[0]};

    Item ItemsSet4[2]{
        ItemsCollection[3],
        ItemsCollection[6]};

    Item ItemsSet5[2]{
        ItemsCollection[1],
        ItemsCollection[0]};

    Monster MonsterCollection[9]{
        Monster((char *)"Snakestones", 1),
        Monster((char *)"Slam-Dancer", 1),
        Monster((char *)"Bloodless", 2),
        Monster((char *)"King Vermin", 5),
        Monster((char *)"Megagorgon", 3),
        Monster((char *)"Spreader", 1),
        Monster((char *)"Flame Wheel", 1),
        Monster((char *)"Numbskull", 1),
        Monster((char *)"Voidstone", 4)};

    Monster MonstersInRoom1[3]{
        MonsterCollection[0],
        MonsterCollection[2],
        MonsterCollection[6]};

    Monster MonstersInRoom2[2]{
        MonsterCollection[5],
        MonsterCollection[8]};

    Monster MonstersInRoom3[3]{
        MonsterCollection[4],
        MonsterCollection[1],
        MonsterCollection[3]};

    Monster MonstersInRoom4[3]{
        MonsterCollection[7],
        MonsterCollection[1],
        MonsterCollection[0]};

    Monster MonstersInRoom5[3]{
        MonsterCollection[2],
        MonsterCollection[1],
        MonsterCollection[5]};

    int MonsterSetSize2 = 2;
    int MonsterSetSize3 = 3;

    Room RoomsCollection[10]{
        Room((char *)"Zagreus's Room", ItemsSet1, ItemSetSize, MonstersInRoom4, MonsterSetSize3),
        Room((char *)"Taenarum Cave", ItemsSet1, ItemSetSize, MonstersInRoom2, MonsterSetSize2),
        Room((char *)"Area of Punishment", ItemsSet3, ItemSetSize, MonstersInRoom3, MonsterSetSize3),
        Room((char *)"River Lether", ItemsSet5, ItemSetSize, MonstersInRoom5, MonsterSetSize3),
        Room((char *)"Elysium", ItemsSet2, ItemSetSize, MonstersInRoom1, MonsterSetSize3),
        Room((char *)"River Styx", ItemsSet4, ItemSetSize, MonstersInRoom2, MonsterSetSize2),
        Room((char *)"Eternity", ItemsSet2, ItemSetSize, MonstersInRoom4, MonsterSetSize3),
        Room((char *)"Lake Acheron", ItemsSet3, ItemSetSize, MonstersInRoom5, MonsterSetSize3),
        Room((char *)"River Phlegethon", ItemsSet4, ItemSetSize, MonstersInRoom1, MonsterSetSize3),
        Room((char *)"Lake Lethe", ItemsSet5, ItemSetSize, MonstersInRoom3, MonsterSetSize3)};

    Data HadesData(RoomsCollection, 10);
    Game Hades(HadesData);

    Map Tartarus((char *)"Tartarus");
    HadesData.AddMap(Tartarus);

    Hades.SetData(HadesData);
    Hades.SetCurrentMap(Tartarus);

    Tartarus.AddRoom(RoomsCollection[2], North);
    cout << Tartarus.GetCurrentRoom() << endl;

    Tartarus.AddRoom(RoomsCollection[0], West);
    Tartarus.SetCurrentRoom(Tartarus.GetRooms()->GetWest());
    cout << Tartarus.GetCurrentRoom() << endl;

    Tartarus.AddRoom(RoomsCollection[2], North);
    cout << Tartarus.GetRooms() << endl;

    Map Elysium((char *)"Elysium");
    HadesData.AddMap(Elysium);
    Hades.SetData(HadesData);
    
    Elysium.AddRoom(RoomsCollection[2], East);
    cout << Elysium.GetCurrentRoom() << endl;

    Elysium.AddRoom(RoomsCollection[9], West);

    Elysium += Tartarus;
    cout << Elysium.GetCurrentRoom() << endl;

}
