/**
*	@file	Character.cpp
*	@brief	Implementation file for character class.
*	@author Eric Heidel
*	@date	Implementation phase due March 13th, 2017
*/

#include "Character.h"
#include "Dice.h"
#include "Weapon.h"
#include "Item.h"

bool& getInCombat(){
    static bool inCombat = 0;
    return inCombat;
}

Character::Character()
{
    w = new Weapon(dagger);
	attack = 6;
	defense = 14;
	hp = 40;
	money = 100;
	dex = 4;
	charisma = 3;
	courage = 1;
	strength = 2;

}

Character::~Character()
{
    delete w;
}

void Character::addToInv(Item *Item)
{
	Inv.AddItem(Item);
}

void Character::loseAllItems(){
    Inv.Empty();
}

void Character::takePotion(Item I)
{
	if (hp > 0 && hp < 25)
	{
        this->hp += 15;
	    cout << "You regained 15 HP! You now have " << hp << " HP!" << endl;
		this->hp += 15;
		Inv.RemoveItem(new Item(potion));
	}
	else if ((maxHP - 15) <= hp && hp < maxHP)
	{
		this->hp = maxHP;
		cout << "You've fully restored your HP!" << endl;
		Inv.RemoveItem(new Item(potion));
	}
	else
	{
		cout << "You already have full hp!" << endl;
	}
}

void Character::takeDamage (size_t attackerRoll)
{
    hp -= attackerRoll;
    cout << "You took " << attackerRoll << " damage: ";
	cout<<hp<<" health remaining"<<endl;
	/*if (hp <= 0)
		gameoverfunction
	*/
}

//Do we want the money check to happen in changeMoney, or in the shopkeeper NPC?
void Character::changeMoney(int amount)
{
    this->money += amount;
    //this->getMoney() + amount;
}

void Character::equipItem(Item *equip)
{
if (w != nullptr)
{
getInv().AddItem(w);
}
w = static_cast<Weapon*>(equip);
switch(equip->getEnumVal()){
case 1:
    setDexterity(4);
    setStrength(2);
    setAttack(6);
    setDefense(14);
    setCharisma(3);
    setCourage(1);
    break;
case 2:
    setDexterity(1);
    setStrength(4);
    setAttack(6);
    setDefense(16);
    setCharisma(2);
    setCourage(4);
    break;
case 3:
    setDexterity(2);
    setStrength(3);
    setAttack(8);
    setDefense(14);
    setCharisma(1);
    setCourage(5);
    break;
case 4:
    setDexterity(5);
    setStrength(0);
    setAttack(6);
    setDefense(13);
    setCharisma(5);
    setCourage(3);
    break;



    }
}

void Character::equipItem(Item equip)
{
Inv.AddItem(w);

Inv.RemoveItem(equip);
switch(equip.getEnumVal()){
case 1:
    cout << "we got here at least?"<<endl;
    w = new Weapon(dagger);
    setDexterity(4);
    setStrength(2);
    setAttack(6);
    setDefense(14);
    setCharisma(3);
    setCourage(1);
    break;
case 2:
    {
    w = new Weapon(swordshield);
    setDexterity(1);
    setStrength(4);
    setAttack(6);
    setDefense(16);
    setCharisma(2);
    setCourage(4);
    break;
    }
case 3:
    {
    w = new Weapon(longsword);
    setDexterity(2);
    setStrength(3);
    setAttack(8);
    setDefense(14);
    setCharisma(1);
    setCourage(5);
    break;
    }
case 4:{
     w = new Weapon(bow);
    setDexterity(5);
    setStrength(0);
    setAttack(6);
    setDefense(13);
    setCharisma(5);
    setCourage(3);
    break;
}
    }
}

void Character::hitRoll(Enemy *En)
{
    size_t Roll;
	Dice d;
    Roll = d.seedroll(20);
    cout<<"You rolled a "<< Roll << "(roll) + " << dex << "(dex) = " << Roll + dex << endl;
    if (Roll == 20)
    {
        cout<<"CRITICAL HIT!!!"<<endl;
        En->takeDamage((d.seedroll(attack) + strength) * 2, this);
    }
    else if (Roll + dex > En->getDefense())
    {
        cout<<"You hit your enemy!"<<endl;
        En->takeDamage(d.seedroll(attack) + strength, this);
    }
    else
        cout<<"You missed :("<<endl;
}

void Character::specialAttack(Enemy *En)
{
    switch(w->getEnumVal())
    {
    case 1:
    cout<<"You charge your enemy, aiming for the neck"<<endl;
    size_t Roll;
	Dice d;
    Roll = d.randroll(20);
    cout<<"You rolled a "<< Roll << "(roll) + " << dex << "(dex) - 5 = " << Roll + dex - 5<< endl;
    if (Roll + dex - 5 > En->getDefense())
    {
        cout<<"CRITICAL HIT!!"<<endl;
        En->takeDamage((d.randroll(attack) + strength) * 3, this);
    }
    else
        cout<<"You missed :("<<endl;

    break;
    case 2:
    {
    cout<< "You charge into your enemy full force and launch your shield forward!" << endl;
    size_t Roll;
	Dice d;
    Roll = d.randroll(20);
    cout<<"You rolled a "<< Roll << "(roll) + " << dex << "(strength) = " << Roll + dex << endl;
    if (Roll == 20)
    {
        cout<<"CRITICAL HIT!!!"<<endl;
        En->takeDamage((d.randroll(attack) + strength) * 2, this);
          En->Stunned();
    }
    else if (Roll + strength > En->getDefense())
    {
        cout<<"You smash your shield into your foes face, disorienting him."<<endl;
        En->takeDamage((d.randroll(attack)) + strength, this);
        En->Stunned();
    }
    else
        cout<<"You missed"<<endl;
    break;
    }
    case 3:
            {
    cout<< "You see the enemy begin to swing at you" << endl;
    size_t Roll;
	Dice d;
    Roll = d.randroll(20);
    cout<<"You rolled a "<< Roll << "(roll) + " << dex << "(dex) = " << Roll + dex << endl;
    if (Roll + dex >= En->getDefense() - 2)
    {
        if (Roll + strength > 12)
        {
            Roll = d.randroll(20);
            cout<<"You riposte the enemy with immense skill, and swing for the neck!"<<endl;
            cout<<"CRITICAL HIT!!!"<<endl;
            En->takeDamage((d.randroll(attack) + strength) * 2, this);
            En->Stunned();
            break;
        }
        else
        {
        cout<<"You parry the enemy, and riposte quickly!"<<endl;
        En->takeDamage((d.randroll(attack)) + strength, this);
        En->Stunned();
        break;
        }
    }
    else
        cout<< "You attempt to parry the enemy. Keyword is attempt, as you've failed horribly."<<endl;
        En->hitRoll(this, 1);
        En->Stunned();
        break;


    }
    case 4:
    cout<< "You grab several arrows from your quiver and begin to nock them... " << endl;
    do{
    size_t Roll;
    Dice d;
    Roll = d.randroll(20);
    cout<<"You rolled a "<< Roll << "(roll) + " << dex << "(dex) = " << Roll + dex << endl;
    if (Roll == 20)
    {
        cout<<"CRITICAL HIT!!!"<<endl;
        En->takeDamage((d.randroll(attack) + dex) * 2, this);
    }
    else if (Roll + dex > En->getDefense())
    {
        En->takeDamage((d.randroll(attack)) + dex, this);
        cout<<"Your arrow hits the target, you nock the next arrow"<<endl;
        if (En->checkHP() == 1){
            cout << "You continue shooting mindlessly, until you notice that your foe is already dead, stuffed with hundreds of arrows."<<endl;
            goto endNock;
        }
    }
    else
    {
        cout<<"You missed, your enemy takes this chance to strike!"<<endl;
        goto endNock;
    }
    }while(true);
    endNock:
    break;
    }
    SpAttCount = 3;
}

void Character::useItem(int x)
{
    Item I = getInv().GetInventory()[x - 1];
    if (I.getisEquippable())
    {
        cout<<"just to check"<<endl;
        this->equipItem(I);
    }
    else if(I.getName() == "Potion")
    {
        this->takePotion(I);
    }


}

//void Character::theftFailed(){
//    Inv.Empty();
//}

void Character::setAttack(size_t newAtt)
{
	this->attack = newAtt;
}

void Character::setDefense(size_t newDef)
{
	this->defense = newDef;
}

void Character::setDexterity(size_t newDex)
{
	this->dex = newDex;
}

void Character::setCourage(size_t newCour)
{
	this->courage = newCour;
}

void Character::setCharisma(size_t newChar)
{
	this->charisma = newChar;
}

void Character::setStrength(size_t newStr)
{
	this->strength = newStr;
}

void Character::setHP(int newHP){
    this->hp = newHP;
}

void Character::setMoney(size_t newMoney){
    this->money = newMoney;
}

size_t Character::getAttack()
{
	return this->attack;
}

size_t Character::getDefense()
{
	return this->defense;
}

size_t Character::getDexterity()
{
	return this->dex;
}

size_t Character::getCourage()
{
	return this->courage;
}

size_t Character::getCharisma()
{
	return this->charisma;
}

size_t Character::getStrength()
{
	return this->strength;
}

Weapon Character::getWeapon()
{
    return *w;
}

size_t Character::getMoney()
{
    return money;
}

int Character::getHP()
{
    return hp;
}

Inventory& Character::getInv()
{
    return Inv;
}
