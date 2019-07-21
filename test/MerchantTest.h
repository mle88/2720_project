/**
*   @file   MerchantTest.h
*   @brief  Test file for Merchant class
*   @author Erica Nordin
*   @date   Implementation phase due March 13th, 2017
*/

#ifndef MERCHANTTEST_H
#define MERCHANTTEST_H
#include <cppunit/extensions/HelperMacros.h>
#include "Merchant.h"
/**
 *@brief test file for Merchant class
 */
class MerchantTest : public CppUnit::TestFixture{
    CPPUNIT_TEST_SUITE(MerchantTest);
    CPPUNIT_TEST(TestConstructor);
    CPPUNIT_TEST(TestSell);
    CPPUNIT_TEST(TestDisplayWares);
    CPPUNIT_TEST(TestTheft);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
    /**
    *   @brief  Tests that creating a merchant doesn't crash
    */
    void TestConstructor();
    /**
    *   @brief  Tests that selling an item doesn't crash
    */
    void TestSell();
    /**
    *   @brief  Tests that displaying the merchant's inventory doesn't crash
    */
    void TestDisplayWares();
    /**
    *   @brief  Tests that stealing from the merchant doesn't crash
    */
    void TestTheft();

private:
    Character *ch;
    Merchant *m;

};


#endif // MERCHANTTEST_H
