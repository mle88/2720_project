/**
*   @file   EnemyTest.h
*   @brief  Test file for Enemy class
*   @author Erica Nordin
*   @date   Implementation phase due March 13th, 2017
*/

#ifndef ENEMYTEST_H
#define ENEMYTEST_H
#include <cppunit/extensions/HelperMacros.h>
#include "Enemy.h"

/**
 *@brief test file for Enemy class
 */
class EnemyTest : public CppUnit::TestFixture{
    CPPUNIT_TEST_SUITE(EnemyTest);
    CPPUNIT_TEST(TestConstructor);
    CPPUNIT_TEST(TestDropItem);
    CPPUNIT_TEST(TestTakeDamage);
    CPPUNIT_TEST(TestHitRoll);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
    /**
    *   @brief  Tests that creating an enemy doesn't crash
    */
    void TestConstructor();
    /**
    *   @brief  Tests that dropItem doesn't crash
    */
    void TestDropItem();
    /**
    *   @brief  Tests that takeDamage doesn't crash
    */
    void TestTakeDamage();
    /**
    *   @brief  Tests that hitRoll doesn't crash
    */
    void TestHitRoll();
private:
    Character *ch;
    Enemy *en;

};


#endif // MERCHANTTEST_H

