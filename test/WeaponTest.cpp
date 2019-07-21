/**
 *    @file   WeaponTest.cpp
 *    @brief  implementation file for WeaponTest class
 *    @author Michelle Le
 *    @date   Implementation phase due March 13th, 2017
 */

#include "SpecialItem.h"
#include "WeaponTest.hpp"

#include <string>

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(WeaponTest);

void WeaponTest::testWeapon ()
{
    Item* dag = new Weapon(dagger);
    Item* lsw = new Weapon(longsword);
    string lswName = "Longsword";
    size_t lswPrice = 60;
    string lswDesc = "Finely refined steel\nAbility: Parry and Riposte\nParry your opponent and strike back! Unless you mess up...\nDex: 2\nStrength: 3\nDefense: 14\nAttack: 8";

    CPPUNIT_ASSERT_EQUAL( (lsw==dag) , false );

    CPPUNIT_ASSERT_EQUAL(lsw->getName(), lswName );

    CPPUNIT_ASSERT_EQUAL(lsw->getPrice(), lswPrice);

    CPPUNIT_ASSERT_EQUAL(lsw->getDescription(), lswDesc);

    CPPUNIT_ASSERT_EQUAL(lsw->getEnumVal(), 3);




}

void WeaponTest::testgetisEquippable()
{
    Item* lsw= new Weapon(longsword);
    CPPUNIT_ASSERT_EQUAL(lsw->getisEquippable(), true);
}
