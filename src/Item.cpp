/**
 *    @file   Item.cpp
 *    @brief  Implementation file for Item class
 *    @author Michelle Le
 *    @date   Implementation phase due March 13th, 2017
 *    @todo   This is going to changed so it is pure virtual
 */

#include "Item.h"
#include <fstream>
#include<iostream>


Item::Item(item a)
{

}

Item::Item(const Item& a){
price = a.getPrice();
name = a.getName();
description = a.getDescription();
enumVal = a.getEnumVal();
bisUsable = getisUsable();
bisEquippable = getisEquippable();
}


bool Item::getisEquippable(){
    return bisEquippable;
}

std::string Item::getDescription() const
{
    return description;
}

std::string Item::getName() const
{
   return name;
}

size_t Item::getPrice() const
{
   return price;
}

int Item::getEnumVal() const
{
   return enumVal;
}

bool Item::operator==(const Item& a)
{
    if(this->enumVal==a.enumVal)
      return true;
    return false;
}

std::ostream& operator<<(std::ostream& os, const Item& item)
{
   return os << "Item {" << item.getName() << " " << item.getPrice() << " " << "}";

}

item intToEnum(int itemInt){
    item itemEnum;
    switch(itemInt){
        case 1:
            itemEnum = dagger;
            break;
        case 2:
            itemEnum = swordshield;
            break;
        case 3:
            itemEnum = longsword;
            break;
        case 4:
            itemEnum = bow;
            break;
        case 5:
            itemEnum = potion;
            break;
        case 6:
            itemEnum = amulet;
            break;
        case 7:
            itemEnum = honey;
            break;
        case 8:
            itemEnum = key;
            break;
        case 9:
            itemEnum = gold;
            break;
        default:
            throw read_in_error("Item not recognized");
    }

    return itemEnum;
}
