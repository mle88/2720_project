/**
 *    @file   WeaponTest.hpp
 *    @brief  Test file for SpecialItem class
 *    @author Michelle Le
 *    @date   Implementation phase due March 13th, 2017
 */
#ifndef WEAPONTEST_H
#define WEAPONTEST_H

#include "Weapon.h"
#include "WeaponTest.hpp"

#include <cppunit/extensions/HelperMacros.h>

class WeaponTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(WeaponTest);
    CPPUNIT_TEST(testWeapon);
    CPPUNIT_TEST(testgetisEquippable);
    CPPUNIT_TEST_SUITE_END();
public:
    /**
    *   @brief tests weapon constructor
    */
    void testWeapon();

    /**
    *   @brief tests is Equippable boolean getter
    */
    void testgetisEquippable();
};

#endif /* WeaponTest_hpp */
