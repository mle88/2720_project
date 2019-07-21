/**
 *   @file   Environments.h
 *   @brief  Pure Virtual superclass to Bazaar, Crypt, Forest, GameEnd and Tavern
 *   @author Sean Herridge-Berry
 *   @date   Implementation phase due March 13th, 2017
 */
#ifndef ENVIRONMENTS_H
#define ENVIRONMENTS_H

#include "Character.h"

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
*   enums to identify environment
*/
enum Env {bazaar, crypt, forest, gameEnd, gameStart, tavern};


/**
 *   @brief Pure Virtual superclass to Bazaar, Crypt, Forest, GameEnd and Tavern
 */
class Environments
{
    friend class SaveLoad;
public:
    /**
    *   @brief  Environments constructor
    */
    Environments();

    /**
     *   @brief  menu for Environments
     *   @return int returns the menu selection from the user
     *   @throw wrong_env when wrong Env enum type entered
     */
    int menu(Env, Character*);

    /**
     *   @brief  prints descriptive text for each environment
     *   @throw wrong_env when wrong Env enum type entered
     */
    void printText(Env);

    /**
    *   @brief pauses game to let user read descriptive text
    */
    void pauseGame();

    /**
     *   @brief checks input for digit to match menu
     */
    void checkAns(string&,int&, Character *);

  protected:

    string choiceStr;
    int choiceNum;
    char pause;
};

#endif // ENVIRONMENTS_H
