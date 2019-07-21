/**
*	@file	Character.h
*	@brief	Class to manage the character's stats.
*	@author Eric Heidel
*	@date	Implementation phase due March 13th, 2017
*/

class Enemy;

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Enemy.h"
#include "Inventory.h"
#include "Item.h"
#include "Weapon.h"


bool& getInCombat();
static const int maxHP = 40;   ///< Characters max hp. When using potions or regenerating health, hp can not go over this value.

/**
*	@brief Manages the character's stats, is created once at the beginning of the game.
*/
class Character
{
    friend class SaveLoad;
public:
    //Character(){}
	Character();
	~Character();
	/**
	*	@brief called when adding an item to character's inventory
	*	@param item Item to add to inventory.
	*/
	void addToInv(Item *item);
	/**
	*   @brief Calls Inventory::Empty()
	*/
	void loseAllItems();
	/**
	*	@brief called when user uses take potion command, regenerates health.
	*/
	void takePotion(Item I);
	/**
	*	@brief Called by Enemy's dealDamage() function. Only called if the attack got through the hit phase.
	*	Uses damage roll as a parameter. Checks if player has greater than 0 hp, and calls characterDie() function
	*	if the player has run out of health.
	*	@param attackerRoll The enemies attack roll, based off enemies attack stat and roll.
	*/
	void takeDamage(size_t attackerRoll);
	/**
	*	@brief Called when spending or earning money.
	*	@param amount The amount of money spent or earned.
	*/
	void changeMoney(int amount);
	/**
	*	@brief Called when equiping new weapon or item.
	*	@param equip The item that was equipped.
	*/
	void equipItem(Item *equip);
	void equipItem(Item equip);
	/**
	*	@brief Called when equipping new weapon, changes attack stat.
	*	@param newAtt New attack stat value.
	*/
	void setAttack(size_t newAtt);
	/**
	*	@brief Called when equipping new weapon , changes defense stat.
	*	@param newDef New defense stat value.
	*/
	void setDefense(size_t newDef);
	/**
	*	@brief Called when equipping new weapon, changes Dex stat.
	*	@param newDex New dexterity stat value.
	*/
	void setDexterity(size_t newDex);
	/**
	*	@brief Called when equipping new weapon, changes courage stat.
	*	@param newCour New Courage stat value.
	*/
	void setCourage(size_t newCour);
	/**
	*	@brief Called when equipping new weapon, changes charisma stat.
	*	@param newChar New charism stat value.
	*/
	void setCharisma(size_t newChar);
	/**
	*	@brief Called when equipping new weapon, changes Strength stat.
	*	@param newStrength New strength stat value.
	*/
	void setStrength(size_t newStr);
	/**
	*   @brief Sets HP
	*   @param int HP to be set
	*/
	void setHP(int newHP);
	/**
	*   @brief Sets money
	*   @param size_t amount to be set
	*/
	void setMoney(size_t newMoney);

	int getHP();
    /**
	*	@brief Called when accessing characters attack.
	*/
	size_t getAttack();
	/**
	*	@brief Called when accessing characters defense.
	*/
	size_t getDefense();
	/**
	*	@brief Called when accessing characters dexterity.
	*/
	size_t getDexterity();
	/**
	*	@brief Called when accessing characters courage.
	*/
	size_t getCourage();
	/**
	*	@brief Called when accessing characters charisma.
	*/
	size_t getCharisma();
	/**
	*	@brief Called when accessing characters strength.
	*/
	size_t getStrength();
	/**
	*	@brief Called when accessing characters Money.
	*/
	size_t getMoney();
	/**
	*	@brief Called when accessing characters Inventory.
	*/
	Inventory& getInv();
	/**
	*	@brief Called when accessing characters weapon.
	*/
	Weapon getWeapon();
	/**
	*	@brief Called when attacking an enemy to see if the attack hits.
	*	@param En Enemy being attacked, where we get enemy defense,etc.
	*/
	void hitRoll(Enemy *En);
	/**
	*	@brief Called when special attacking an enemy to see if the special attack hits.
	*	@param En Enemy being attacked, where we get enemy defense,etc.
	*/
	void specialAttack(Enemy *En);

    int SpAttCount = 0; //Cooldown on SpAttack
	/**
	*	@brief Called when using or equiping an item.
	*	@param I Item being used or equipped
	*/
    void useItem(int I);

    int money;   ///< Character's money, used to buy items.

private:

	size_t attack;  ///< Character's attack attribute, impacts the damage dealt to the damage.

	size_t defense; ///< Character's defense attribut, impacts the enemies hit chance.

	int hp;      ///< Characters current hp. If it drops below 0, it's game over.

	size_t dex;     ///< Characters dex, affects reactionary rolls, increases chance to hit.

	size_t charisma;///< Characters charisma, used to talk yourself out of situations, barter(?), etc.

	size_t courage; ///< Characters courage, affects rolls to maintain composure in the presense of great danger.

	size_t strength; ///< Characters strength, constant addition to the damage dealt.

	Inventory Inv; ///< Characters inventory.

	Weapon *w = nullptr;       ///< Characters current weapon, affects all of the stats above.
};
#endif // CHARACTER_H
