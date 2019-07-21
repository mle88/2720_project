/**
 *    @file   Weapon.h
 *    @brief  Weapon class definition file
 *    @author Michelle Le
 *    @date   Implementation phase due March 13th, 2017
 */

#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

/**
 *   @brief derived class weapons from superclass items
 */
class Weapon:public Item
{
    friend class SaveLoad;
  public:
    /**
    * @brief The Weapon constructor.
    * @param item, takes in enum item to determine price and description
    */
   Weapon(item b);
    /**
    * @brief The Weapon deconstructor.
    */
   virtual ~Weapon(){}
    /**
    * @brief Getter for bonus value of die roll
    * @return size_t of the bonus
    */
   size_t get_bonus();
    /**
    * @brief Getter for attack value of Weapon
    * @return the attack value
    */
   size_t get_attack();
    /**
    * @brief Getter for total attack value of Weapon after the die roll
    * @return the attack value+the bonus value
    */
   size_t get_mod_attack();
    /**
    * @brief Setter for bonus total attack value of Weapon after the die roll
    */
   void set_bonus(size_t a);
    /**
    * @brief Getter for Charisma value of Weapon
    * @return the Charisma value
    */
   size_t getCharisma();
    /**
    * @brief Getter for Courage value of Weapon
    * @return the Courage value
    */
   size_t getCourage();
    /**
    * @brief Getter for Defense value of Weapon
    * @return the Defense value
    */
   size_t getDefense();
   /**
    * @brief Getter for Dexterity value of Weapon
    * @return the Dexterity value
    */
   size_t getDexterity();
   /**
    * @brief Getter for Strength value of Weapon
    * @return the Strength value
    */
   size_t getStrength();

   bool getisWeapon(){return bisWeapon;}

protected:
   size_t attack;
   size_t bonus;
   size_t charisma;
   size_t courage;
   size_t defense;
   size_t dexterity;
   size_t strength;
   bool bisWeapon = 1;

};

#endif
