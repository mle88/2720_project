/**
 *    @file   InventoryTest.hpp
 *    @brief  Test file for Inventory class
 *    @author Michelle Le
 *    @date   Implementation phase due March 13th, 2017
 */
#ifndef INVENTORYTEST_H
#define INVENTORYTEST_H

#include "Inventory.h"
#include "InventoryTest.hpp"

#include <cppunit/extensions/HelperMacros.h>


class InventoryTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(InventoryTest);
    CPPUNIT_TEST(testInventory);
    CPPUNIT_TEST(testAddItem);
    CPPUNIT_TEST(testRemoveItem);
    CPPUNIT_TEST(testRemoveRandomItem);
    CPPUNIT_TEST(testGetInventory);
    //CPPUNIT_TEST(testDisplayName);
    //CPPUNIT_TEST(testDisplayInv);
    CPPUNIT_TEST(testEmpty);
    CPPUNIT_TEST_SUITE_END();
public:
    /**
    *   @brief tests inventory constructor
    */
    void testInventory();
    /**
    *   @brief tests adding item from inventory
    */
    void testAddItem();
    /**
    *   @brief tests removing item from inventory
    */
    void testRemoveItem();
    /**
    *   @brief tests removing random item
    */
    void testRemoveRandomItem();
    /**
    *   @brief tests inventory getter
    */
    void testGetInventory();

    /**
    *   @brief tests emptying inventory
    */
    void testEmpty();
};

#endif /* InventoryTest_hpp */
