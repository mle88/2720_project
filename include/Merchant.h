/**
*   @file   Merchant.h
*   @brief  The merchant that is encountered in the Bazaar, from whom the main character can buy special items and an infinite supply of health potions.
*   @author Erica Nordin
*   @date   Implementation phase due March 13th, 2017
*   @todo   Write theft and purchase functions
*/

#ifndef MERCHANT_H
#define MERCHANT_H

#include <iostream>
#include <string>
#include <SpecialItem.h>
#include <Character.h>
#include <Inventory.h>

/**
*   @brief The merchant that is encountered in the Bazaar, from whom the main character can buy special items and an infinite supply of health potions.
*/

static const size_t MerchantInvSize = 5;
//static Inventory defaultMerchInv;
//static bool merchVisited = 0;

Inventory& getMerchInv();




//void makeDefMerchInv();
/**
 *@brief merchant interactions in bazaar
 */
class Merchant
{
    friend class SaveLoad;
public:
    /**
    *   @brief The merchant constructor, which copies the contents of the static inventory to the merchant object.
    */
    Merchant();
    /**
    *   @brief destructor
    */
    ~Merchant();
    /** @brief Dialogue options with the merchant. */
    void speak();
    /**
    *   @brief Removes the parameter item from the merchant's inventory, and replaces it with a potion.
    Adds the item to the characters inventory, and removes the appropriate amount of gold.
    *   @param i The item to be removed from the merchant's inventory.
    *   @param c The character object.
    */
    void sell(item i, Character *c); // Parameter type item
    /**
    *   @brief Prints the Merchant's inventory
    */
    void displayWares();
    /**
    *   @brief Attempts theft. If the dice roll is sufficiently high, a random item is removed from the merchant's inventory and replaced with a potion.
    The  item is added to the character's inventory.
    *   @param i The item to be removed from the merchant's inventory.
    *   @param c The character object.
    */
    void theft(Character *c);
    ////**
    //*   @brief Allows the character to steal from the merchant, buy items, or leave.
    //*/
    //void interaction();
private:
    Inventory sellable; ///< The merchant's inventory of items that can be purchased or stolen by the character.
    // Inventory items;
};

#endif // MERCHANT_H
