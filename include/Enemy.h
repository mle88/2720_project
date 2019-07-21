/**
*   @file   Enemy.h
*   @brief  Allows the creation of different enemies based on the EnemyType enumeration, stored in the Enemy identity attribute.
*   @author Erica Nordin
*   @date   Implementation phase due March 13th, 2017
*/

class Character;
using namespace std;

#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <string>
#include "Character.h"
#include "Dice.h"
#include "SaveLoad.h"
#include <vector>

enum EnemyType {Mimic, Mugger, Bear, Bees, Necromancer, Zombie};
static const size_t numEnemies = 6;

vector<bool> &getEnemyDefeated();


/**
* @brief Allows the creation of different enemies based on the EnemyType enumeration, stored in the Enemy identity attribute.
*/
class Enemy //: public NPC
{
    friend class SaveLoad;
public:
    /**
    * @brief Enemies are constructed upon arrival in the appropriate environments if the interaction hasn't occurred yet.
    The EnemyType is passed as a parameter and the Enemy's attack, defense, and health are set based on their type.
    * @param id The specific type of enemy.
    */
    Enemy(EnemyType id);
    ~Enemy() {}
    /**
    * @brief Called when an enemies health drops to 0 or lower. Adds special items to the main character's inventory based on the EnemyType, and
    updates the enemyDefeated array to prevent the enemy from respawning.
    * @param ch The Character object
    */
    void dropItem(Character *ch);
    /**
    * @brief Called by the main character's hitRoll method. Calls a damage roll to determine the amount of damage to the enemy,
    and subtracts the damage from their health. Calls dropItem if the enemy's health drops to 0 or lower.
    * @param attackerStat The main character's attack strength, based on their attack attribute and a hit roll.
    * @param ch The Character object
    */
    void takeDamage(int attackerRoll, Character *ch);
    /**
    * @brief Calculates the enemy's attack strength, based on their attack attribute and a hit roll. Calls the main character's takeDamage method.
    * @param ch The Character object
    */
    void hitRoll(Character *ch, bool bGuaranteedHit = 0);
    /**
    * @return defense attribute
    */
    size_t getDefense();

    int getHealth();

    bool checkHP();

    void speak();

    void Stunned();

    bool bIsStunned = false;

	void outHealth(); //outputs health in a string
private:
    size_t attack;      ///< The enemy's attack attribute, which impacts the damage dealt to to the main character.
    size_t defense;     ///< The enemy's defense attribute, which impacts the main character's hit rolls.
    int health;      ///< The enemy's remaining hp. If it drops below 0, the enemy dies.
    size_t dex;         ///< The enemy's dexterity. Increases their chance to hit you.
    size_t strength;    ///< The enemy's strength. Increases damage.
    EnemyType identity; ///< The specific identity of the enemy that determines its other attributes and whether it drops an item upon death.


};

#endif // ENEMY_H
