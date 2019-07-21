/**
*   @file   Weapon.cpp
*   @brief  Implementation file for Weapon class
*   @author Michelle Le
*   @date   Implementation phase due March 13th, 2017
*/

#include "Weapon.h"

Weapon::Weapon(item a):Item(a)
{
    switch(a)
    {
    case dagger:
        {
        price = 0;
        name = "Dagger";
        description = "Quick and Sharp\nAbility: Critical Strike\nSacrifice -5 on a dice roll(Roll + dex) to strike a critical spot for x3 damage\nDex: 4\nStrength: 2\nAttack: 6\nDefense: 14";
        enumVal = 1;
        bisEquippable = true;
        break;
        }
    case swordshield:
    {
        price = 50;
        name = "Sword and Shield";
        description = "A balanced weapon\nAbility: Shield Bash\nCharge into your opponent at full force, stunning him if you hit.\nDex: 1\nStrength 4\nDefense: 16\nAttack: 6";
        enumVal = 2;
        bisEquippable = true;
        break;
    }
    case longsword:
        {
        price = 60;
        name = "Longsword";
        description = "Finely refined steel\nAbility: Parry and Riposte\nParry your opponent and strike back! Unless you mess up...\nDex: 2\nStrength: 3\nDefense: 14\nAttack: 8";
        enumVal = 3;
        bisEquippable = true;
        break;
        }
    case bow:
        {
        price = 35;
        name =  "Bow";
        description = "A stringed piece of wood\nAbility: Quick Nock\nShoot, then keep shooting until you miss.\nDex: 5\nStrength: 0\nDefense: 13\nAttack 6";
        enumVal = 4;
        bisEquippable = true;
        break;
        }
    }
}

//not neccesary anymore since the character carrries the stats
/*size_t Weapon::get_bonus()
{
   return bonus;
}

size_t Weapon::get_attack()
{
   return attack;
}

size_t Weapon::get_mod_attack()
{
   return get_bonus() + get_attack();
}*/
