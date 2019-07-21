/**
 *    @file   SpeciaItemTest.cpp
 *    @brief  implementation file for SpecialItemTest class
 *    @author Michelle Le
 *    @date   Implementation phase due March 13th, 2017
 */

#include "Item.h"
#include "SpecialItem.h"
#include "SpecialItemTest.hpp"
#include "Weapon.h"

#include <string>

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(SpecialItemTest);

void SpecialItemTest::testSpecialItem ()
{

    Item* dag = new Weapon(dagger);
    Item* amu = new SpecialItem(amulet);

    string amuName = "Amulet";
    size_t amuPrice = 0;
    string amuDesc = "Use this for special cases";

    CPPUNIT_ASSERT_EQUAL( (amu==dag) , false );

    CPPUNIT_ASSERT_EQUAL(amu->getName(), amuName );

    CPPUNIT_ASSERT_EQUAL(amu->getPrice(), amuPrice);

    CPPUNIT_ASSERT_EQUAL(amu->getDescription(), amuDesc);

    CPPUNIT_ASSERT_EQUAL(amu->getEnumVal(), 6);

    delete dag;
    delete amu;

}

void SpecialItemTest::testgetisEquippable()
{
    Item* amu= new SpecialItem(amulet);
    CPPUNIT_ASSERT_EQUAL(amu->getisEquippable(), false);
    delete amu;
}
