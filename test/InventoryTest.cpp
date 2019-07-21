/**
 *    @file   InventoryTest.cpp
 *    @brief  implementation file for InventoryTest class
 *    @author Michelle Le
 *    @date   Implementation phase due March 13th, 2017
 */

#include "InventoryTest.hpp"
#include "Weapon.h"
#include "SpecialItem.h"
#include "Inventory.h"
#include <iostream>
CPPUNIT_TEST_SUITE_REGISTRATION(InventoryTest);

void InventoryTest::testInventory()
{
    Inventory a;


    CPPUNIT_ASSERT_EQUAL((a.GetInventory()).empty(), true);
    CPPUNIT_ASSERT(a.GetInventory().size()==0);

}
void InventoryTest::testAddItem()
{
    Inventory a;
    Item* bo = new Weapon(bow);
    a.AddItem(bo);
    Item * sws = new Weapon(swordshield);
    Item * amu = new SpecialItem(amulet);

    CPPUNIT_ASSERT(a.GetInventory()[0] == *bo);
    a.AddItem((sws));
    CPPUNIT_ASSERT(!(a.GetInventory()[1]==*bo));
   //a.DisplayInventory();
    CPPUNIT_ASSERT(a.GetInventory()[1]==*sws);
    a.AddItem((amu));
    CPPUNIT_ASSERT(a.GetInventory()[2]==*amu );
    delete sws;
    delete amu;
    delete bo;

}
void InventoryTest::testRemoveItem()
{
    Inventory a;
    Item* bo = new Weapon(bow);
    a.AddItem(bo);
    Item * sws = new Weapon(swordshield);
    Item * amu = new SpecialItem(amulet);

    a.RemoveItem(bo);

    a.AddItem(amu);a.DisplayInventory();

//    CPPUNIT_ASSERT(a.RemoveItem(sws)== false);

    CPPUNIT_ASSERT(!(a.GetInventory()[2]== *amu));
//    CPPUNIT_ASSERT(a.RemoveItem(bo) == true);

    delete sws;
    delete amu;
    delete bo;

}
void InventoryTest::testRemoveRandomItem()
{
    Inventory a;
    Inventory b;
    Item* bo = new Weapon(bow);
    a.AddItem(bo);
    b.AddItem(bo);
    Item * sws = new Weapon(swordshield);
    Item * amu = new SpecialItem(amulet);
    a.AddItem(amu);
    b.AddItem(sws);
    //cant test this cause its random
    //CPPUNIT_ASSERT_THROW(a.removeRandomItem(), switchcase_error);
    //a.DisplayInventory();
    //merch cannot have this so i tested this
    CPPUNIT_ASSERT(b.removeRandomItem() != amulet);

    delete sws;
    delete amu;
    delete bo;
}
void InventoryTest::testGetInventory()
{
    Inventory bo1;
    Inventory fail;
    Inventory bo2;
    Item* bo = new Weapon(bow);
    bo1.AddItem(bo);
    //CPPUNIT_ASSERT_EQUAL(bo1.GetInventory(),bo2.GetInventory());

}
void InventoryTest::testEmpty()
{
    Inventory a;
    Inventory b;
    Item* bo = new Weapon(bow);
    a.AddItem(bo);
    Item * sws = new Weapon(swordshield);
    Item * amu = new SpecialItem(amulet);
    a.AddItem(amu);
    a.AddItem(sws);
    //testing size before empty
    CPPUNIT_ASSERT(a.GetInventory().size() != b.GetInventory().size());

    a.Empty();

    CPPUNIT_ASSERT(a.GetInventory().size() == b.GetInventory().size());

    delete sws;
    delete amu;
    delete bo;

}
