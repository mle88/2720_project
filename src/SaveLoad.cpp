/**
*   @file   SaveLoad.cpp
*   @brief  Implementation file for SaveLoad class
*   @author Erica Nordin
*   @date   Implementation phase due March 13th, 2017
*/
#include "SaveLoad.h"

void SaveLoad::saveGame(Character *Ch)
{
    //for(int i=0; i<numEnemies; i++){
    //    cout << getEnemyDefeated()[i] << " ";
    //}
    //MerchInv is updated successfully while selling, but reverts back to default values somewhere before entering this function.
    ofstream outFile;
    outFile.open("./src/saveGame.txt");
    //string s = "Save Game Details Go Here";
    //outFile << s << endl;

    // Environments


    // Character

    // Character inventory
    outFile << ((Ch->Inv).inventory).size() << endl;
    for (unsigned int i = 0; i < ((Ch->Inv).inventory).size(); i++)
        outFile << ((Ch->Inv).inventory)[i].getEnumVal() << " ";
    outFile << endl;
    // Current weapon
    outFile << (Ch->w)->getEnumVal() << endl;
    // Health
    outFile << Ch->hp << endl;

    // Money
    outFile << Ch->money << endl;

    //NPCs

    for(unsigned int i=0; i<numEnemies; i++)
        outFile << getEnemyDefeated()[i] << " ";
    outFile << endl;

    //cout << ""
    for(unsigned int i=0; i<MerchantInvSize; i++){
        //MerchInv.itemAtIndex(i);
        //outFile << (MerchInv.itemAtIndex(i))->enumVal << " ";
        outFile << getMerchInv().enumIntAtIndex(i) << " ";
        //cout << getMerchInv().enumIntAtIndex(i) << " ";
    }
    outFile << endl;

    outFile.close();
    cout << endl << "Game saved successfully!" << endl;
}
Character * SaveLoad::loadGame(bool newGame)
{
    ifstream inFile;
    if(newGame)
    {
        inFile.open("./src/newGame.txt");
    }
    else
    {
        inFile.open("./src/saveGame.txt");
    }
    Character *Ch = new Character();
    //read in required information

    // Character

    // Character inventory



    int itemInt;
    item itemEnum;
    Item *newItem;

    int numCharItems; // The number of items in the inventory

    inFile >> numCharItems;

    for(int i=0; i<numCharItems; i++){
        inFile >> itemInt;
        itemEnum = intToEnum(itemInt);
        if (itemInt >= 1 && itemInt <= 4)
            newItem = new Weapon(itemEnum);
        else if (itemInt == 5)
            newItem = new Item(itemEnum);
        else if (itemInt >= 6 && itemInt <= 8)
            newItem = new SpecialItem(itemEnum);
        else
            throw read_in_error("Something goofed while reading in the character's items");
        Ch->addToInv(newItem);
    }

    // Current weapon
    int weaponInt;

    inFile >> weaponInt;
    Weapon currWeapon(intToEnum(weaponInt));
    Ch->equipItem(currWeapon);
    // Health

    int newHP;
    inFile >> newHP;
    Ch->setHP(newHP);

    // Money
    size_t newMoney;
    inFile >> newMoney;
    Ch->setMoney(newMoney);

    //NPCs

    bool z;
    for(int i=0; i<numEnemies; i++){

        inFile >> z;
        getEnemyDefeated().at(i) = z;
    }
    //for (int i = 0; i<numEnemies; i++)
    //        cout << getEnemyDefeated()[i] << " ";
    //inFile >> merchVisited;
    //Inventory merchIn; // placeholder

    for(unsigned int i=0; i<MerchantInvSize; i++){
        inFile >> itemInt;
        itemEnum = intToEnum(itemInt);
        if (itemInt >= 2 && itemInt <= 4)
            newItem = new Weapon(itemEnum);
        else if (itemInt == 5)
            newItem = new SpecialItem(itemEnum);
        else
            throw read_in_error("The merchant should not have that item");
        getMerchInv().AddItem(newItem);
    }/*
    for(int i=0; i<MerchantInvSize; i++){
        cout << MerchInv.enumIntAtIndex(i) << " ";
    }*/

    inFile.close();
    return Ch;
    delete newItem; delete Ch;
}

