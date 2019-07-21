/**
*   @file   EnemyTest.cpp
*   @brief  Implementation file for EnemyTest class
*   @author Erica Nordin
*   @date   Implementation phase due March 13th, 2017
*/

#include "EnemyTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(EnemyTest);

void EnemyTest::setUp(){
    ch = new Character();
    en = new Enemy(Mimic);
}

void EnemyTest::tearDown(){
    delete ch;
    delete en;
}

void EnemyTest::TestConstructor(){
    Enemy *e;
    CPPUNIT_ASSERT_NO_THROW(e = new Enemy(Necromancer));
    delete e;
}

void EnemyTest::TestDropItem(){
    CPPUNIT_ASSERT_NO_THROW(en->dropItem(ch));
}

void EnemyTest::TestTakeDamage(){
    CPPUNIT_ASSERT_NO_THROW(en->takeDamage(10, ch));
}

void EnemyTest::TestHitRoll(){
    CPPUNIT_ASSERT_NO_THROW(en->hitRoll(ch, 1));
}
