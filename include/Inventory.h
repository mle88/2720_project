/**
 *   @file   Inventory.h
 *   @brief  Class to set up and have operations for Character's and Merchant's Inventory
 *   @author Michelle Le
 *   @date   Implementation phase due March 13th, 2017
 */
#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"
#include "Dice.h"
#include <typeinfo>

/**
*   @brief Class to set up and have operations for character's inventory
*/
class Inventory
{
    friend class SaveLoad;
  public:
    /**
    * @brief The Inventory constructor.
    */
   Inventory();
   /**
   *    @brief Inventory copy constructor
   *    @param inv Inventory to be copied
   */
   Inventory(const Inventory& inv);

    /**
    *   @brief overloaded assignment operator
    */
    void operator= (const Inventory& in);

    /**
    * @brief Adds Items to the inventory
    */
   void AddItem(Item *a);
    /**
    * @brief Adds Items to the inventory
    *
    */
   bool RemoveItem(Item *a);
   bool RemoveItem(Item a);
   bool RemoveItem(item a);
   /**
   *    @brief Removes a random item from the inventory if a dice roll exceeds a particular value. Used for stealing from the merchant.
   *    @return item The enumVal of the item that was removed.
   */
   item removeRandomItem();
    /**
    * @brief Getter for the inventory.
    * @return vector GetIventory
    */
   std::vector<Item> GetInventory() const;

    /**
    * @brief Displays Inventory
    *
    */
   void DisplayInventory();

    /**
    * @brief Empties the whole inventory except for dagger
    *
    */
   void Empty();

   void DisplayInventoryName();

   /**
   *    @brief Returns the item at index i
   *    @param i The inventory index
   *    @return Item The item located at index i
   */
   Item * itemAtIndex(int i) const;

   int enumIntAtIndex(int i);

private:
   std::vector<Item> inventory;
   std::vector<Item>::iterator iter;
};

#endif /* Inventory_hpp */
