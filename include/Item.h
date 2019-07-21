/**
 *    @file   Item.h
 *    @brief  Implementation file for Item class
 *    @author Michelle Le
 *    @date   Implementation phase due March 13th, 2017
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Exceptions.h"

/**
 *   @brief  Creating items
 *   @param item lists all types of items
 */

enum item{dagger=1, swordshield=2, longsword=3, bow=4, potion=5, amulet=6, honey=7, key=8, gold=9  };

/**
 *   @brief  Parent Class to create other items such as special items and weapons
 */
class Item
{
    friend class SaveLoad;
public:
    /**
    * @brief The Item constructor.
    * @param item, takes in enum item to determine price and description
    */
   Item(item a);
   /**
   *    @brief Item copy constructor
   *    @param Item to be copied
   */
   Item(const Item& a);
    /**
    * @brief Getter for the name of the item
    * @return string of the name.
    */
    /**
    * @brief The Item deconstructor.
    */
   virtual ~Item(){}
   std::string getName() const;
    /**
    * @brief Getter for the description of the item
    * @return string of the description.
    */
   std::string getDescription() const;
    /**
    * @brief Getter for the price of the item
    * @return size_t of the price.
    */
   size_t getPrice() const;
    /**
    * @brief Getter for the int corresponds to the item's enum identity
    * @return int the item's enum identity
    */
   int getEnumVal() const;
    /**
    * @brief overloaded comparison operator to compare Items
    * @return true if the item is the same.
    */
   bool operator==(const Item& a);

    bool getisEquippable();

    bool getisUsable(){return bisUsable;}

protected:
   size_t price;
   std::string name;
   std::string description;
   int enumVal;
   bool bisUsable;
   bool bisEquippable = false;
};

item intToEnum(int itemName);


#endif //Item.h
