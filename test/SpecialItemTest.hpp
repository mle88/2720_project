/**
 *    @file   SpecialItemTest.hpp
 *    @brief  Test file for SpecialItem class
 *    @author Michelle Le
 *    @date   Implementation phase due March 13th, 2017
 */
#ifndef SPECIALITEMTEST_H
#define SPECIALITEMTEST_H

#include "SpecialItem.h"
#include "SpecialItemTest.hpp"

#include <cppunit/extensions/HelperMacros.h>
#include <stdio.h>

class SpecialItemTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(SpecialItemTest);
    CPPUNIT_TEST(testSpecialItem);
    CPPUNIT_TEST(testgetisEquippable);
    CPPUNIT_TEST_SUITE_END();
public:
    /**
    *   @brief  tests special item constructor
    */
    void testSpecialItem();
    /**
    *   @brief tests is equippable getter
    */
    void testgetisEquippable();
};

#endif //SPECIALITEMTEST_H
