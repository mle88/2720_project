/**
 *   @file   SaveLoad.h
 *   @brief  Class to make saving / loading possible
 *   @author Erica Nordin
 *   @date   Implementation phase due March 13th, 2017
 */
#ifndef SAVELOAD_H
#define SAVELOAD_H

#include <fstream>
#include "Merchant.h"
#include "Enemy.h"
#include "Exceptions.h"
#include "Character.h"
#include "Item.h"
#include "Inventory.h"

using namespace std;

/**
*   @brief  Class to make saving / loading possible
*/
class SaveLoad
{
public:
    /**
     *  @brief saveGame prints specific data to textfile
     *  @param  ofstream& output file stream object
     *  @param Character object
     */
    void saveGame(Character *Ch);
    /**
     *  @brief loadGame reads specific data from textfile
     *  @param  ifstream&   input file stream object
     *  @param  bool    true/false if newGame or not
     *  @return Character object
     */
    Character * loadGame(bool);

private:
    ofstream outFile;   ///< outfile
    ifstream inFile;    ///< infile
};

#endif // SAVELOAD_H
