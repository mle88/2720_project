/**
*   @file   CharacterTest.cpp
*   @brief  Implementation file for CharacterTest class
*   @author Eric Heidel
*   @date   Implementation phase due March 13th, 2017
*/

#include "Character.h"
#include "CharacterTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(CharacterTest);

void CharacterTest::TestTakeDamage()
{
    Character Ch;// = Character();
    Ch.takeDamage(5); //uses set Hp function
    CPPUNIT_ASSERT(Ch.getHP() == 35);
    CPPUNIT_ASSERT(Ch.getHP() != 30);
}

void CharacterTest::TestChangeMoney()
{
    Character Ch;// = Character();
    Ch.changeMoney(10);
    CPPUNIT_ASSERT(Ch.getMoney() == 110);
    CPPUNIT_ASSERT(Ch.getMoney() != 115);
}

void CharacterTest::TestEquipItem()
{
    Character Ch;// = Character();
    Weapon *W = new Weapon(dagger);
    Weapon X = Weapon(longsword);
    Ch.equipItem(W);
    CPPUNIT_ASSERT(Ch.getWeapon() == *W);
    Ch.equipItem(X);
    CPPUNIT_ASSERT(!(Ch.getWeapon() == *W));
    CPPUNIT_ASSERT(Ch.getWeapon() == X);
    delete W;
}

void CharacterTest::TestSetAttack()
{
    Character Ch;// = Character();

    Ch.setAttack(10);
    CPPUNIT_ASSERT(Ch.getAttack() == 10);
    CPPUNIT_ASSERT(Ch.getAttack() != 6);
}

void CharacterTest::TestSetDef()
{
    Character Ch;// = Character();

    Ch.setDefense(10);
    CPPUNIT_ASSERT(Ch.getDefense() == 10);
    CPPUNIT_ASSERT(Ch.getDefense() != 6);
}

void CharacterTest::TestSetDex()
{
    Character Ch;// = Character();

    Ch.setDexterity(10);
    CPPUNIT_ASSERT(Ch.getDexterity() == 10);
    CPPUNIT_ASSERT(Ch.getDexterity() != 6);
}

void CharacterTest::TestSetCour()
{
    Character Ch;// = Character();

    Ch.setCourage(10);
    CPPUNIT_ASSERT(Ch.getCourage() == 10);
    CPPUNIT_ASSERT(Ch.getCourage() != 6);
}

void CharacterTest::TestsetCharisma()
{
    Character Ch;// = Character();

    Ch.setCharisma(10);
    CPPUNIT_ASSERT(Ch.getCharisma() == 10);
    CPPUNIT_ASSERT(Ch.getCharisma() != 6);
}

void CharacterTest::TestSetStr()
{
    Character Ch;// = Character();

    Ch.setStrength(10);
    CPPUNIT_ASSERT(Ch.getStrength() == 10);
    CPPUNIT_ASSERT(Ch.getStrength() != 6);
}
