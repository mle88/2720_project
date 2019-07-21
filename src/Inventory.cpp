/**
 *    @file   Inventory.cpp
 *    @brief  Implementation file for Inventory class
 *    @author Michelle Le
 *    @date   Implementation phase due March 13th, 2017
 */

#include "Inventory.h"
#include "Weapon.h"
#include"SpecialItem.h"
#include <iostream>
#include <vector>
using namespace std;
Inventory::Inventory()
{

}

Inventory::Inventory(const Inventory& inv){
    Item * k;
    for (int i = 0; i<(inv.GetInventory()).size(); i++){
        k = inv.itemAtIndex(i);
        this->AddItem(k);
    }
    //std::cout << "End of Inventory copy constructor" << std::endl;
    //this->DisplayInventoryName();
}

void Inventory::operator=(const Inventory& in)
{
    this->inventory=in.GetInventory();
}


void Inventory::AddItem(Item *a)
{
   inventory.push_back(*a);
   //need to do a bound check

}

bool Inventory::RemoveItem(Item *a)
{
    bool removed = 0;
       for (int i = 0; i < inventory.size(); i++)
        if(inventory[i] == *a)
        {
            inventory.erase(inventory.begin() + i);
            removed = 1;
            return removed;
        }
    return removed;

}

    /*//The remove function was causing problems so I changed it, should work now -Eric
   for (int i = 0; i < inventory.size(); i++)
        if(inventory[i] == *a)
        {
            inventory.erase(inventory.begin() + i);
            removed = 1;
            return removed;
        }
    return removed;

    //The old algorithm, in case you still want it.
  /* for(iter = inventory.begin(); iter!=inventory.end(); iter++)
   {
      if (*iter == *a)
      {
        inventory.erase(iter);
      }
   }
       for (int i =0 ; i < inventory.size(); i++)
    {
                vector<Item>::iterator it = inventory.begin();
                    if((*it) == *a){
                        it= inventory.erase(it);
                        removed = 1;
                    }
                    else{
                        it++;
                    }


        }
        return removed;

}*/
bool Inventory::RemoveItem(Item a)
{
    bool removed = 0;
    //The remove function was causing problems so I changed it, should work now -Eric
   for (int i = 0; i < inventory.size(); i++)
        if(inventory[i] == a)
        {
            inventory.erase(inventory.begin() + i);
            removed = 1;
            return removed;
        }
        return removed;
}

bool Inventory::RemoveItem(item a)
{
   bool removed = 0;
    //The remove function was causing problems so I changed it, should work now -Eric
   for (int i = 0; i < inventory.size(); i++)
        if(inventory[i].getEnumVal() == a)
        {
            inventory.erase(inventory.begin() + i);
            removed = 1;
            return removed;
        }
        return removed;
}

item Inventory::removeRandomItem(){
    Dice d;
    //Item *i;
    int invIndex, id;
    item enumID;
    invIndex = d.seedroll(inventory.size()) - 1;
    id = inventory[invIndex].getEnumVal();
    //i = new Item(intToEnum(id));
    switch(id){
    case 2:
        enumID = swordshield;
        break;
    case 3:
        enumID = longsword;
        break;
    case 4:
        enumID = bow;
        break;
    case 5:
        enumID = potion;
        break;
    default:
        throw switchcase_error("The merchant shouldn't have that item");
    }
    inventory.erase(inventory.begin() + invIndex);
    return enumID;
}



std::vector<Item>Inventory::GetInventory() const
{
   return this->inventory;
}

void Inventory::DisplayInventoryName()
{
    if(inventory.empty() == true)
   {
      std::cout<<"There is nothing here"<<std::endl;

   }
   else
   {
    int i = 1;
    for(iter = inventory.begin(); iter != inventory.end(); iter++)
    {
       std::cout << i << ": " << iter->getName() << std::endl;
       i++;
    }
   }
}

void Inventory::DisplayInventory()
{
    // Seg fault when calling inventory.empty or inventory.begin
    if(inventory.empty() == true)
   {
      std::cout<<"There is nothing here"<<std::endl;
      return;
   }
   for(iter = inventory.begin(); iter != inventory.end(); iter++)
   {

      std::cout << "Name: " << iter->getName() << "\nDescription: "<< iter->getDescription()
	   << " " << std::endl << std::endl;
   }
}


//emptys the inventory but adds the dagger since its a permanent item
void Inventory::Empty()
{

   inventory.clear();
   std::cout<<"Your Inventory is now empty"<<std::endl;
    //inventory.push_back(new Weapon(dagger));
}

Item * Inventory::itemAtIndex(int i) const{
    // inventory[i] is an Item, but getEnumVal is not working on it.
    item m = intToEnum(inventory[i].getEnumVal());
    Item *x = new Item(m);
    return x;
}

int Inventory::enumIntAtIndex(int i){
    return (inventory.at(i)).getEnumVal();
}


