#pragma once

class Monster
{
    private:
    char* MobName;
    int Level;

    public:
    Monster();
    Monster(char* NewMobName, int NewLevel);
    ~Monster();
    Monster(const Monster& CopyMonster);
    // Getters
    inline char* GetMobName() {return MobName;};
    inline int GetMobLevel() {return Level;};
    // Operators
    Monster& operator=(const Monster &AssignMonster);
    Monster operator++(int);
    Monster& operator+=(const Monster &AddedMonster);

};