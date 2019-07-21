/**
 *    @file   CharacterTest.h
 *    @brief  Test file for Character Class
 *    @author Eric Heidel
 *    @date   Implementation phase due March 13th, 2017
 */

#ifndef CHARACTERTEST_H_INCLUDED
#define CHARACTERTEST_H_INCLUDED
#include <cppunit/extensions/HelperMacros.h>
#include "Character.h"

/**
 *@brief Test file for Character class
 */
class CharacterTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(CharacterTest);
    CPPUNIT_TEST(TestTakeDamage);
    CPPUNIT_TEST(TestChangeMoney);
    CPPUNIT_TEST(TestEquipItem);
    CPPUNIT_TEST(TestSetAttack);
    CPPUNIT_TEST(TestSetDef);
    CPPUNIT_TEST(TestSetDex);
    CPPUNIT_TEST(TestSetCour);
    CPPUNIT_TEST(TestsetCharisma);
    CPPUNIT_TEST(TestSetStr);
    CPPUNIT_TEST_SUITE_END();

public:
    /**
    *   @brief tests take damage function
    */
    void TestTakeDamage();
    /**
    *   @brief tests change money function
    */
    void TestChangeMoney();
    /**
    *   @brief tests equip item function
    */
    void TestEquipItem();
    /**
    *   @brief tests set attack function
    */
    void TestSetAttack();
    /**
    *   @brief tests set defense function
    */
    void TestSetDef();
    /**
    *   @brief tests set dexterity function
    */
    void TestSetDex();
    /**
    *   @brief tests set courage function
    */
    void TestSetCour();
    /**
    *   @brief tests set charisma
    */
    void TestsetCharisma();
    /**
    *   @brief tests set strength
    */
    void TestSetStr();
};

#endif // CHARACTERTEST_H_INCLUDED
