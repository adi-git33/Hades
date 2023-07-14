#include "Monster.h"
#include <iostream>
#include <cstring>

using namespace std;

Monster::Monster(){
    MobName = strdup("Default");
    Level = 0;
}

Monster::Monster(char *NewMobName, int NewLevel)
{
    MobName = strdup(NewMobName);
    Level = NewLevel;
}

Monster::~Monster()
{
    free(MobName);
}

Monster::Monster(const Monster &CopyMonster)
{
    MobName = strdup(CopyMonster.MobName);
    Level = CopyMonster.Level;
}

Monster &Monster::operator=(const Monster &AssignMonster)
{
    MobName = strdup(AssignMonster.MobName);
    Level = AssignMonster.Level;
    return *this;
}

Monster Monster::operator++(int)
{
    Monster MonsterTmp = *this;
    ++Level;
    return MonsterTmp;
};

Monster &Monster::operator+=(const Monster &AddedMonster)
{
    if (Level < 5)
    {
        Level += AddedMonster.Level;
        return *this;
    }
    else
        return *this;
}
