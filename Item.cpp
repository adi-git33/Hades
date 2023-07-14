
#include "Item.h"
#include <iostream>
#include <cstring>

using namespace std;

Item::Item(){
    ItemName = strdup("Default");
    ItemRarity = 0;
}

Item::Item(char *NewItemName, int NewRarity)
{
    ItemName = strdup(NewItemName);
    ItemRarity = NewRarity;
}

Item::~Item()
{
    free(ItemName);
}

Item::Item(const Item &CopyItem)
{
    ItemName = strdup(CopyItem.ItemName);
    ItemRarity = CopyItem.ItemRarity;
}

Item &Item::operator=(const Item &AssignedItem)
{
    ItemName = strdup(AssignedItem.ItemName);
    ItemRarity = AssignedItem.ItemRarity;
    return *this;
}

Item Item::operator++(int)
{
    Item temp = *this;
    if (ItemRarity != 3)
        ItemRarity++;

    return temp;
}

Item &Item::operator++()
{
    if (ItemRarity != 3)
        ItemRarity++;

    return *this;
}

const Item Item::operator+(const Item &AddedItem)
{
    Item AddedResult(ItemName, ItemRarity);
    if (ItemRarity + AddedItem.ItemRarity > 3)
        AddedResult.ItemRarity = 3;
    else
        AddedResult.ItemRarity = ItemRarity + AddedItem.ItemRarity;
    return AddedResult;
}

Item &Item::operator+=(const Item &AddedItem)
{
    if (ItemRarity + AddedItem.ItemRarity > 3)
        ItemRarity = 3;
    else
        ItemRarity += AddedItem.ItemRarity;
    return *this;
}

void Item::PrintRarity()
{
    if (ItemRarity == 0)
        cout << "Common";
    else if (ItemRarity == 1)
        cout << "Uncommon";
    else if (ItemRarity == 2)
        cout << "Epic";
    else if (ItemRarity == 3)
        cout << "Legendary";
}
