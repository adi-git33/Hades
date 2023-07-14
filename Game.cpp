#include "Game.h"
#include <iostream>
#include <cstring>

using namespace std;

Game::Game(Data &Newdata)
{
    CurrentMap = NULL;
    GameData = Newdata;
}

Game::~Game()
{
    delete[] CurrentMap;
}