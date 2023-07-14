
#pragma once
#include "Rarity.h"

class Item
{
    private:
    char* ItemName;
    int ItemRarity;

    public:
    Item();
    Item(char* NewItemName, int NewRarity);
    ~Item();
    Item(const Item &CopyItem);
    // Getters
    inline char* GetItemName() {return ItemName;};
    inline int GetItemRarity() {return ItemRarity;};
    //Operators
    Item &operator=(const Item &AssignedItem);
    Item operator++(int);
    Item &operator++();
    const Item operator+(const Item &AddedItem);
    Item &operator+=(const Item &AddedItem);
    // Funcs
    void PrintRarity();
};