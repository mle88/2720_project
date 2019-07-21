
/**
*   @file   SaveLoadTest.h
*   @brief  Test file for SaveLoad class
*   @author Erica Nordin
*   @date   Implementation phase due March 13th, 2017
*/

#ifndef SAVELOADTEST_H
#define SAVELOADTEST_H
#include <cppunit/extensions/HelperMacros.h>
#include "SaveLoad.h"
/**
 *@brief test file for SaveLoad class
 */
class SaveLoadTest : public CppUnit::TestFixture{
    CPPUNIT_TEST_SUITE(SaveLoadTest);
    CPPUNIT_TEST(TestSave);
    CPPUNIT_TEST(TestNew);
    CPPUNIT_TEST(TestLoad);

    CPPUNIT_TEST_SUITE_END();

public:
    /**
    *   @brief  Confirms that saving does not crash
    */
    void TestSave();
    /**
    *   @brief  Confirms that new game does not crash
    */
    void TestNew();
    /**
    *   @brief  Confirms that load game does not crash
    */
    void TestLoad();
};


#endif // MERCHANTTEST_H
