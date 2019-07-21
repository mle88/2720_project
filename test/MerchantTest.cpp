/**
*   @file   MerchantTest.cpp
*   @brief  Implementation file for MerchantTest class
*   @author Erica Nordin
*   @date   Implementation phase due March 13th, 2017
*/

#include "MerchantTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(MerchantTest);

void MerchantTest::setUp(){
    ch = new Character();
    m = new Merchant();
}

void MerchantTest::tearDown(){
    delete m;
    delete ch;
}

void MerchantTest::TestConstructor(){
    Merchant *me;
    CPPUNIT_ASSERT_NO_THROW(me = new Merchant());
    delete me;
}

void MerchantTest::TestSell(){
    CPPUNIT_ASSERT_NO_THROW(m->sell(potion, ch));
}

void MerchantTest::TestDisplayWares(){
    CPPUNIT_ASSERT_NO_THROW(m->displayWares());
}

void MerchantTest::TestTheft(){
    CPPUNIT_ASSERT_NO_THROW(m->theft(ch));
}
