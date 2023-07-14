#pragma once
#include "Data.h"

class Game
{   private:
    Map* CurrentMap;
    Data GameData;

    public:
    Game(Data &NewData);
    ~Game();
    // Getters
    // Setters
    inline void SetData(Data &NewData) {GameData = NewData;};
    inline void SetCurrentMap(Map &NewMap) {CurrentMap = &NewMap;};
    // Operators
    // Funcs
};