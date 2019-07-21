/**
 * @file main.cpp
 * @brief CotN.exe main file
 * @author Eric Heidel, Sean Herridge-Berry, Michelle Le, Erica Nordin
 * @date Implementation phase due March 13th, 2017
 */
#include "Character.h"
#include "Dice.h"
#include "Enemy.h"
#include "Environments.h"
#include "Inventory.h"
#include "Item.h"
#include "Merchant.h"
#include "SaveLoad.h"

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main()
{
     //CPPUnit Tests
    //CPPUNIT TEST RUN
    // Get the top level suite from the registry
    CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

    // Adds the test to the list of test to run
    CppUnit::TextUi::TestRunner runner;
    runner.addTest( suite );

    // Change the default outputter to a compiler error format outputter
    runner.setOutputter( new CppUnit::CompilerOutputter( &runner.result(),
                                                       std::cerr ) );
    // Run the tests.
    bool wasSucessful = runner.run();
    //END CPPUNIT TEST RUN

    if(wasSucessful)   //if tests pass, run game.
    {
        Environments ev;
        Character* Ch; //= new Character();
        getInCombat() = false;
        SaveLoad sl;
        //vector<bool> enemyDefeated = getEnemyDefeated();
        int menuChoice = 0;
        int ansNum;
        string ans;
        bool fightA = false;
        bool fightB = false;
        bool invEmptied = false;
        bool fromCrypt = false;
        bool hasKey = false;

        ev.printText(gameStart);    //splash page

        cout << "Type 'save' in any numerical menu while not in combat to save your game." << endl;
        cout << "Would you like to play a new game or load your previous game?" << endl
        << "1: New game" << endl
        << "0: Load game" << endl;
        bool startVal;
        cin >> startVal;
        //if(!startVal) //if load, write over default character
            Ch = sl.loadGame(startVal);
            ev.pauseGame();
//player enters the tavern
//for (int i = 0; i<numEnemies; i++)
  //          cout << getEnemyDefeated[i] << " ";
        ev.printText(tavern);
        menuChoice = ev.menu(tavern, Ch);
        switch(menuChoice)
        {
            case 1:
            {
                system("clear");
                cout << "We really think you should hear him out..." << endl;
                ev.pauseGame();
                menuChoice = 3;
                goto quest;
            }
            case 2:
            {
                system("clear");
                cout << "Man that was a good beer... Lets listen to the old man." << endl;
                ev.pauseGame();
                menuChoice = 3;
                goto quest;
            }
            case 3:
            {
                quest:
                system("clear");
                cout << "After what a longwinded story about a long lost love who" << endl
                     << "went missing long ago, you find out about a piece of jewelry that he" << endl
                     << "wishes could be returned to him, if the body of his love" << endl
                     << "can be found somewhere beyond the forest." << endl
                     << endl;
                ev.pauseGame();
                break;
            }
        }
        //player leaves the tavern
        //player enters bazaar
        //for (int i = 0; i<numEnemies; i++)
        //    cout << getEnemyDefeated[i] << " ";
        //cout << "Mugger defeated?" << enemyDefeated[1] << endl;
        //ev.pauseGame();
        if(!getEnemyDefeated()[1])
            {
                ev.printText(bazaar);
                menuChoice = ev.menu(bazaar, Ch);
                switch(menuChoice)
                {
                case 1:
                    {
                        fightA = true;
                        break;
                    }
                case 2:
                    {
                        ///< @todo use charisma stat to talk way out of conflict
                        cout << "You try to talk your way out of it but he's too sneaky!" << endl;
                        cout << "He's got you trapped in a corner. You have no choice but to fight!" << endl;
                        fightA = true;
                        ev.pauseGame();
                        break;
                    }
                case 3:
                    {
                        system("clear");
                        cout << "You wuss out and hand over your stuff" << endl;
                        (Ch->getInv()).Empty();
                        invEmptied = true;
                        Character* Ch2;
                        Ch = Ch2;
                        //cout << "Your inventory has been emptied" << endl;
                        (Ch->getInv()).DisplayInventory();
                        cout << endl;
                        fightA = false;
                        ev.pauseGame();
                        break;
                    }
                }
                if (fightA)
                {
                    getInCombat() = 1;
                    Enemy* En = new Enemy(Mugger);
                    system("clear");
                    cout<<"Mugger: \"Gimme all your shit\""<<endl;
                    cout<<"You get first strike!"<<endl;
                    do
                    {
                        if (Ch->SpAttCount > 0)
                        {
                            //Ch->SpAttCount--;
                            //segmentation fault being thrown
                        }
                        if (En->bIsStunned)
                        {
                            En->bIsStunned = false;
                        }
                        switchstartA:
                        cout<<"What would you like to do?\n1. Attack!\n2. Use/Equip Item!\n";
                        if (Ch->SpAttCount > 0)
                        {
                            cout << "Cooldown: " << Ch->SpAttCount << " turns left.\n";
                        }
                        cout << "3. Special Attack!\n";
                        cout << "4. Check Enemy!\n";
                        cout << endl;
                        if (En->getHealth() <= 10)
                            cout << "5. Spare" <<endl;
                        cin>>ans;
                        ev.checkAns(ans, ansNum, Ch);
                        cout<<endl;
                        if (ansNum!=-1)
                            system("clear");
                        switch(ansNum){
                            case 1: Ch->hitRoll(En);
                                break;
                            case 2:
                            {
                                int choice;
                                cout << "Which Item would you like to use ?" << endl;
                                Ch->getInv().DisplayInventoryName();
                                cin >> choice;
                                cout<<endl;
                                Ch->useItem(choice);
                                break;
                            }
                        case 3:
                            if (Ch->SpAttCount > 0)
                            {
                                cout << "You can't use that yet\n"<<endl;
                                goto switchstartA;
                            }
                            else
                                Ch->specialAttack(En);
                        break;
                        case 4:
                            En->outHealth();
                            break;
                        case 5:
                            if (En->getHealth() <= 10)
                            {
                                En->dropItem(Ch);
                                goto mugendfight;
                                break;
                            }
                            else
                                goto defaultsw;
                        default: defaultsw:
                            cout<<"You bumbled around like an idiot for a bit and now everyone is looking at you funny. *Pick an actual option dingus*"<<endl;
                            goto switchstartA;
                        }
                        if (En->checkHP())
                        {
                            goto mugendfight;
                        }
                        if(En->bIsStunned == false)
                        {
                            En->speak();
                            En->hitRoll(Ch);
                        }
                    }while (En->getHealth() > 0);
                    delete En;
                mugendfight:
                    cout << "You've won the fight!" << endl;
                    getEnemyDefeated()[1] = 1;
                    ev.pauseGame();
                }
                else
                {
                    system("clear");
                    cout << "Well you got out of that pickle and managed to keep just your dagger" << endl;
                    cout << "You should probably head over to the merchant's area of the Bazaar" << endl;
                    getEnemyDefeated()[1] = 1;
                    ev.pauseGame();
                }

            }
        //player leaves the bazaar
        //heads to the merchant's

        system("clear");
        if(invEmptied)
        {
            cout << "After that fiasco with the mugger, you think it's a good idea to head to your" << endl;
            cout << "favourite local merchant to stock up before continuing on the quest" << endl;
        }
        else
        {
            cout << "You think it wise to visit your favourite local merchant to stock up before" << endl;
            cout << "continuing on the quest" << endl;
        }
        cout << endl;
        cout << endl;

        // This will be removed once SaveLoad has been implemented.
        //makeDefMerchInv();
        //
        // The default inventory and Merchant are each being created, but the merchant is not being constructed with the default inventory.
        Merchant m;

    merchant:
        string choice;
        m.speak();
        cout << endl;

        bool shopping = 1;

        //merchOverview:
        do {
            if(!fromCrypt)
            {
                cout << "You notice that he looks a bit distracted today..." << endl;
            }
        cout << "What would you like to do here?" << endl;
        cout << "1. Leave" << endl;
        cout << "2. Shop" << endl;
        cout << "3. Try your luck at swiping something" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        ev.checkAns(choice,ansNum, Ch);
        //resulting merchant operations
        switch(ansNum)
        {
        case 1:
            {
                shopping = 0;
                break;
            }
        case 2:
            {
            shop:
                cout << "Here are my wares:" << endl;
                m.displayWares();

                int itAns;
                string itemChoice;
                Item *aPotion = new SpecialItem(potion);
                Item *aSwordShield = new Weapon(swordshield);
                Item *aBow = new Weapon(bow);
                Item *aLongsword = new Weapon(longsword);

                //size_t itemPrice;
                do{
                    cout << endl
                    << "What item would you like to buy?" << endl
                    << "1: Health potion (" << aPotion->getPrice() << " gold)" << endl
                    << "2: Sword and shield (" << aSwordShield->getPrice() << " gold)" << endl
                    << "3: Bow (" << aBow->getPrice() << " gold)" << endl
                    << "4: Longsword (" << aLongsword->getPrice() << " gold)" << endl
                    << "5: Nevermind, I don't want to buy anything." << endl
                    << "You have " << Ch->getMoney() << " gold." << endl;
                    cin >> itemChoice;
                    cout << endl;
                    ev.checkAns(itemChoice,itAns, Ch);
                }while (itAns<1 || itAns>5);

                    switch(itAns){
                    case 1:
                        m.sell(potion, Ch); // Every item except potion is claimed to not have
                        break;
                    case 2:
                        m.sell(swordshield, Ch);
                        break;
                    case 3:
                        m.sell(bow, Ch);
                        break;
                    case 4:
                        m.sell(longsword, Ch);
                        break;
                    case 5:
                        //This one isn't working right now for some reason.
                        break;
                    default:
                        throw switchcase_error("You shouldn't have been able to do that");
                    }

                    int nextAns;
                    string nextThing;

                    do{
                    cout << "Would you like to keep shopping?" << endl
                    << "1: Yes" << endl
                    << "2: No" << endl
                    << "3: Try to steal" << endl;
                    cin >> nextThing;
                    ev.checkAns(nextThing,itAns, Ch);
                    }while (itAns <1 || itAns>3);

                    switch(itAns){
                    case 1:
                        goto shop;
                    case 2:
                        shopping = 0;
                        break;
                    case 3:
                        goto steal;
                    default:
                        throw switchcase_error("You shouldn't have been able to do that");
                    }
                    delete aPotion; delete aSwordShield; delete aLongsword; delete aBow;
                    break;

            }
        case 3:
            {
                steal:
                cout << "You try to sneak in a five-finger discount" << endl;
                m.theft(Ch);

                int nextAns;
                string nextThing;

                do{
                    cout << "What would you like to do now?" << endl
                    << "1: Try to steal again" << endl
                    << "2: Shop with actual money, as if you're not a nasty criminal" << endl
                    << "3: Leave" << endl;
                    cin >> nextThing;
                    ev.checkAns(nextThing,nextAns, Ch);
                    }while (nextAns <1 || nextAns>3);

                    switch(nextAns){
                    case 1:
                        goto steal;
                    case 2:
                        goto shop;
                    case 3:
                        shopping = 0;
                        break;
                    default:
                        throw switchcase_error("You shouldn't have been able to do that");
                    }
            }
        }
        }while (shopping == 1);
        if(fromCrypt)
        {
            goto cryptMenu;
        }
        ev.pauseGame();
        //player leaves merchant
        //player enters the forest environment
        if(!getEnemyDefeated()[2] || !getEnemyDefeated()[3])
        {
            ev.printText(forest);
            fightA = false;
            vector<Item> vec = (Ch->getInv().GetInventory());
            bool hasHoney = false;
        forestmenu:
            menuChoice = ev.menu(forest, Ch);
            switch(menuChoice)
            {
            case 1:
                {
                    if(getEnemyDefeated()[3])
                        hasHoney = true;
                    if(hasHoney)
                    {
                        system("clear");
                        cout << "Nothing more to do around here." << endl;
                        goto forestmenu;
                    }
                    else
                    {
                        system("clear");
                        cout << "To the left path in the forest, you are confronted with" << endl;
                        cout << "a swarm of angry bees!" << endl;
                        fightA = true;
                        break;
                    }
                }
            case 2:
                {
                    if(getEnemyDefeated()[2])
                        break;
                    if(hasHoney)
                    {
                        system("clear");
                        cout << "You are confronted with a bear!" << endl;
                        cout << "That honey might come in handy after all!" << endl;
                        fightB = true;
                    }
                    else
                    {
                        system("clear");
                        cout << "You are confronted with a bear!" << endl;
                        cout << "The bear swipes at you and you trip on a rock" << endl;
                        cout << "while trying to escape from the bear." << endl;
                        cout << "You get away, but he gets his claw in anyway" << endl;
                        Ch->takeDamage(5);
                        goto forestmenu;
                    }
                }
            case 3:
                {
                    system("clear");
                    cout << "You step on a bear trap!" << endl;
                    Ch->takeDamage(5);
                    cout << "Nothing else of importance down here..." << endl;
                    goto forestmenu;
                }
            }
            if(fightA)
            {
                getInCombat() = 1;
                Enemy* En = new Enemy(Bees);
                cout << "Bees: \"Bzzzzzzzzzz\"" << endl;
                cout << "You get first strike!" << endl;
                do
                {
                    //int ans;
                    if (Ch->SpAttCount > 0)
                        Ch->SpAttCount--;
                    if (En->bIsStunned)
                    {
                        En->bIsStunned = false;
                    }
                switchstartB:
                    cout << "What would you like to do?\n1. Attack!\n2. Use/Equip Item!\n3. Special Attack!\n4. Check Enemy!";
                    if (Ch->SpAttCount > 0)
                        cout << "Cooldown: " << Ch->SpAttCount << " turns left.";
                    cout << endl;
                    cin >> ans;
                    cout << endl;
                    ev.checkAns(ans, ansNum, Ch);
                    if (ansNum!=-1)
                        system("clear");
                    switch (ansNum) {
                    case 1: Ch->hitRoll(En);
                        break;
                    case 2: {int choice;
                        cout << "Which Item would you like to use?" << endl;
                        Ch->getInv().DisplayInventoryName();
                        cin >> choice;
                        cout << endl;
                        Ch->useItem(choice);
                        break;
                    }
                    case 3:
                        if (Ch->SpAttCount > 0)
                        {
                            cout << "You can't use that yet\n" << endl;
                            goto switchstartB;
                        }
                        else
                            Ch->specialAttack(En);
                        break;
                    case 4:
                        En->outHealth();
                        break;
                    default:
                        cout << "You bumbled around like an idiot for a bit and now everyone is looking at you funny. *Pick an actual option dingus*" << endl;
                        goto switchstartB;
                    }
                    if (En->checkHP())
                    {
                        goto beeendfight;
                    }
                    if (En->bIsStunned == false)
                    {
                        En->speak();
                        En->hitRoll(Ch);
                    }
                } while (En->getHealth() > 0);
            beeendfight:
                cout << "You've won the fight!" << endl;
                getEnemyDefeated()[3] = 1;
                fightA = false;
                hasHoney = true;
                goto forestmenu;
                delete En; En = nullptr;
            }
            if(fightB)
            {
                getInCombat() = 1;
                Enemy* En = new Enemy(Bear);
                cout << "Bear: \"RAWRR\"" << endl;
                cout << "You get first strike!" << endl;
                do
                {
                    //int ans;
                    if (Ch->SpAttCount > 0)
                        Ch->SpAttCount--;
                    if (En->bIsStunned)
                    {
                        En->bIsStunned = false;
                    }
                switchstartC:
                    cout << "What would you like to do?\n1. Attack!\n2. Use/Equip Item!\n3. Special Attack!\n4. Check Enemy!";
                    if (Ch->SpAttCount > 0)
                        cout << "Cooldown: " << Ch->SpAttCount << " turns left.";
                    cout << endl;
                    cin >> ans;
                    cout << endl;
                    ev.checkAns(ans, ansNum, Ch);
                    if (ansNum!=-1)
                        system("clear");

                    switch (ansNum) {
                    case 1: Ch->hitRoll(En);
                        break;
                    case 2: {int choice;
                        cout << "Which Item would you like to use?" << endl;
                        Ch->getInv().DisplayInventoryName();
                        cin >> choice;
                        cout << endl;
                        Ch->useItem(choice);
                        break;
                    }
                    case 3:
                        if (Ch->SpAttCount > 0)
                        {
                            cout << "You can't use that yet\n" << endl;
                            goto switchstartC;
                        }
                        else
                            Ch->specialAttack(En);
                        break;
                    case 4:
                        En->outHealth();
                        break;
                    default:
                        cout << "You bumbled around like an idiot for a bit and now everyone is looking at you funny. *Pick an actual option dingus*" << endl;
                        goto switchstartC;
                    }
                    if (En->checkHP())
                    {
                        goto bearendfight;
                    }
                    if (En->bIsStunned == false)
                    {
                        En->speak();
                        En->hitRoll(Ch);
                    }
                } while (En->getHealth() > 0);
            bearendfight:
                getEnemyDefeated()[2] = 1;
                cout << "You've won the fight!" << endl;
                cout << "Lets get out of the forest while we still can!" << endl;
                delete En; En = nullptr;
            }
        }
        //Player leaves forest
        //Player enters the crypt
    cryptMenu:
        if(!getEnemyDefeated()[0] || !getEnemyDefeated()[4] || !getEnemyDefeated()[5])
        {
            ev.printText(crypt);
            menuChoice = ev.menu(crypt, Ch);
            vector<Item> vec = (Ch->getInv().GetInventory());
            for(int i = 0; i < vec.size(); i++)
                if(vec[i].getName() == "Master Key")
                    hasKey = true;
            switch(menuChoice)
            {
                case 1:
                    cout << "You get spooked by some bats!" << endl;
                    break;
                case 2:
                    {
                        if(hasKey)
                            fightB = true;
                        else
                        {
                            cout << endl << "The door is locked" << endl;
                            goto cryptMenu;
                        }
                        break;
                    }
                case 3:
                    {
                        cout << "You encounter a chest!" << endl;
                        fightA = true;
                    }
                case 4:
                    {
                        fromCrypt = true;
                        goto merchant;
                    }
            }
            if(fightA)
            {
                getInCombat() = 1;
                Enemy* En = new Enemy(Mimic);
                cout << "You go to open the chest, when suddenly it springs to life!" << endl;
                cout << "Mimic: \"Tricked you!\"" << endl;
                cout << "You get first strike!" << endl;
                do
                {
                    int ans;
                    if (Ch->SpAttCount > 0)
                        Ch->SpAttCount--;
                    if (En->bIsStunned)
                    {
                        En->bIsStunned = false;
                    }
                switchstart:
                    cout << "What would you like to do?\n1. Attack!\n2. Use/Equip Item!\n3. Special Attack!\n4. Check Enemy!";
                    if (Ch->SpAttCount > 0)
                        cout << "Cooldown: " << Ch->SpAttCount << " turns left.";
                    cout << endl;
                    cin >> ans;
                    cout << endl;
                    system("clear");
                    switch (ans) {
                    case 1: Ch->hitRoll(En);
                        break;
                    case 2: {int choice;
                        cout << "Which Item would you like to use?" << endl;
                        Ch->getInv().DisplayInventoryName();
                        cin >> choice;
                        cout << endl;
                        Ch->useItem(choice);
                        break;
                    }
                    case 3:
                        if (Ch->SpAttCount > 0)
                        {
                            cout << "You can't use that yet\n" << endl;
                            goto switchstart;
                        }
                        else
                            Ch->specialAttack(En);
                        break;
                    case 4:
                        En->outHealth();
                        break;
                    default:
                        cout << "You bumbled around like an idiot for a bit and now everyone is looking at you funny. *Pick an actual option dingus*" << endl;
                        goto switchstart;
                    }
                    if (En->checkHP())
                    {
                        goto mimicendfight;
                    }
                    if (En->bIsStunned == false)
                    {
                        En->speak();
                        En->hitRoll(Ch);
                    }
                } while (En->getHealth() > 0);
            mimicendfight:
                cout << "You've won the fight!" << endl;
                fightA = false;
                getEnemyDefeated()[0] = 1;
                hasKey = true;
                delete En; En = nullptr;
            }
            if(fightB)
            {
                getInCombat() = 1;
                Enemy* En = new Enemy(Necromancer);
                cout << "Necromancer: \"You're either very brave or very stupid to enter my crypt... Prepare to die.\"" << endl;
                cout << "You get first strike!" << endl;
                do
                {
                    int ans;
                    if (Ch->SpAttCount > 0)
                        Ch->SpAttCount--;
                    if (En->bIsStunned)
                    {
                        En->bIsStunned = false;
                    }
                switchstartD:
                NecroFight:
                    cout << "What would you like to do?\n1. Attack!\n2. Use/Equip Item!\n3. Special Attack!\n4. Check Enemy!";
                    if (Ch->SpAttCount > 0)
                        cout << "Cooldown: " << Ch->SpAttCount << " turns left.";
                    cout << endl;
                    cin >> ans;
                    cout << endl;
                    system("clear");
                    switch (ans) {
                    case 1: Ch->hitRoll(En);
                        break;
                    case 2: {int choice;
                        cout << "Which Item would you like to use?" << endl;
                        Ch->getInv().DisplayInventoryName();
                        cin >> choice;
                        cout << endl;
                        Ch->useItem(choice);
                        break;
                    }
                    case 3:
                        if (Ch->SpAttCount > 0)
                        {
                            cout << "You can't use that yet\n" << endl;
                            goto switchstartD;
                        }
                        else
                            Ch->specialAttack(En);
                        break;
                    case 4:
                        cout << "You can't really tell how injured he is..." << endl;
                        break;
                    default:
                        cout << "You bumbled around like an idiot for a bit and now everyone is looking at you funny. *Pick an actual option dingus*" << endl;
                        goto switchstartD;
                    }
                    if (En->checkHP())
                    {
                        goto Necroendfight;
                    }
                    if (En->bIsStunned == false)
                    {
                        En->speak();
                        En->hitRoll(Ch);
                    }
                    if (En->getHealth() <= 50 && getEnemyDefeated()[5] == false)
                    {
                        cout << "Necromancer: \"Enough of this! Arise my minions!\"" << endl;
                        cout << "You must have weakened the necromancer a fair bit, as he was only able to summon one Zombie" << endl;
                        goto ZombieFight;
                    }
                } while (En->getHealth() > 0);
            Necroendfight:
                cout << "You've won the fight!" << endl;
                delete En; En = nullptr;
                //Zombie fight happens when the Necromancer hits half health.
            ZombieFight:
                Enemy* zombie = new Enemy(Zombie);
                cout << "Zombie: \"Rgggrrrrrr\"" << endl;
                cout << "You get first strike!" << endl;
                do
                {
                    int ans;
                    if (Ch->SpAttCount > 0)
                        Ch->SpAttCount--;
                    if (zombie->bIsStunned)
                    {
                        zombie->bIsStunned = false;
                    }
                switchstartE:
                    cout << "What would you like to do?\n1. Attack!\n2. Use/Equip Item!\n3. Special Attack!\n4. Check Enemy!";
                    if (Ch->SpAttCount > 0)
                        cout << "Cooldown: " << Ch->SpAttCount << " turns left.";
                    cout << endl;
                    cin >> ans;
                    cout << endl;
                    system("clear");
                    switch (ans) {
                    case 1: Ch->hitRoll(zombie);
                        break;
                    case 2: {int choice;
                        cout << "Which Item would you like to use?" << endl;
                        Ch->getInv().DisplayInventoryName();
                        cin >> choice;
                        cout << endl;
                        Ch->useItem(choice);
                        break;
                    }
                    case 3:
                        if (Ch->SpAttCount > 0)
                        {
                            cout << "You can't use that yet\n" << endl;
                            goto switchstartE;
                        }
                        else
                            Ch->specialAttack(zombie);
                        break;
                    case 4:
                        zombie->outHealth();
                        break;
                    default:
                        cout << "You bumbled around like an idiot for a bit and now everyone is looking at you funny. *Pick an actual option dingus*" << endl;
                        goto switchstartE;
                    }
                    if (zombie->checkHP())
                    {
                        goto NecroFight;
                    }
                    if (zombie->bIsStunned == false)
                    {
                        zombie->speak();
                        zombie->hitRoll(Ch);
                    }
                } while (zombie->getHealth() > 0);
                delete zombie; zombie = nullptr;
                goto NecroFight;
            }
        }
        //END OF GAME
        ev.printText(gameEnd);
        menuChoice = ev.menu(gameEnd, Ch);
    return 0;
    } // end if(wasSucessful)
    else
    {
    return 1;
    }
}






/*//Mimic Fight
//    getInCombat() = 1;
	Enemy* En = new Enemy(Mimic);
	cout << "You go to open the chest, when suddenly it springs to life!" << endl;
	cout << "Mimic: \"Tricked you!\"" << endl;
	cout << "You get first strike!" << endl;
	do
	{
		//int ans;
		if (Ch->SpAttCount > 0)
			Ch->SpAttCount--;
		if (En->bIsStunned)
		{
			En->bIsStunned = false;
		}
	switchstart:
		cout << "What would you like to do?\n1. Attack!\n2. Use/Equip Item!\n3. Special Attack!\n4. Check Enemy!";
		if (Ch->SpAttCount > 0)
			cout << "Cooldown: " << Ch->SpAttCount << " turns left.";
		cout << endl;
		cin >> ans;
		cout << endl;
		ev.checkAns(ans, ansNum, Ch);
		if (ansNum!=-1)
            system("clear");
		switch (ansNum) {
		case 1: Ch->hitRoll(En);
			break;
		case 2: {int choice;
			cout << "Which Item would you like to use?" << endl;
			Ch->getInv().DisplayInventoryName();
			cin >> choice;
			cout << endl;
			Ch->useItem(choice);
			break;
		}
		case 3:
			if (Ch->SpAttCount > 0)
			{
				cout << "You can't use that yet\n" << endl;
				goto switchstart;
			}
			else
				Ch->specialAttack(En);
			break;
		case 4:
			En->outHealth();
			break;
		default:
			cout << "You bumbled around like an idiot for a bit and now everyone is looking at you funny. *Pick an actual option dingus*" << endl;
			goto switchstart;
		}
		if (En->checkHP())
		{
			goto mimicendfight;
		}
		if (En->bIsStunned == false)
		{
			En->speak();
			En->hitRoll(Ch);
		}
	} while (En->getHealth() > 0);
mimicendfight:
	cout << "You've won the fight!" << endl;

	//Necromancer fight
	getInCombat() = 1;
	Enemy* En = new Enemy(Necromancer);
	cout << "Necromancer: \"You're either very brave or very stupid to enter my crypt... Prepare to die.\"" << endl;
	cout << "You get first strike!" << endl;
	do
	{
		//int ans;
		if (Ch->SpAttCount > 0)
			Ch->SpAttCount--;
		if (En->bIsStunned)
		{
			En->bIsStunned = false;
		}
	switchstart:
		cout << "What would you like to do?\n1. Attack!\n2. Use/Equip Item!\n3. Special Attack!\n4. Check Enemy!";
		if (Ch->SpAttCount > 0)
			cout << "Cooldown: " << Ch->SpAttCount << " turns left.";
		cout << endl;
		cin >> ans;
		cout << endl;
		ev.checkAns(ans, ansNum, Ch);
		if (ansNum!=-1)
            system("clear");
		switch (ansNum) {
		case 1: Ch->hitRoll(En);
			break;
		case 2: {int choice;
			cout << "Which Item would you like to use?" << endl;
			Ch->getInv().DisplayInventoryName();
			cin >> choice;
			cout << endl;
			Ch->useItem(choice);
			break;
		}
		case 3:
			if (Ch->SpAttCount > 0)
			{
				cout << "You can't use that yet\n" << endl;
				goto switchstart;
			}
			else
				Ch->specialAttack(En);
			break;
		case 4:
			cout << "You can't really tell how injured he is..." << endl;
			break;
		default:
			cout << "You bumbled around like an idiot for a bit and now everyone is looking at you funny. *Pick an actual option dingus*" << endl;
			goto switchstart;
		}
		if (En->checkHP())
		{
			goto Necroendfight;
		}
		if (En->bIsStunned == false)
		{
			En->speak();
			En->hitRoll(Ch);
		}
		if (En->getHealth() <= 50 && getEnemyDefeated()[5] == false)
		{
			cout << "Necromancer: \"Enough of this! Arise my minions!\"" << endl;
			cout << "You must have weakened the necromancer a fair bit, as he was only able to summon one Zombie" << endl;
			goto ZombieFight;
			NecroFight:
		}
	} while (En->getHealth() > 0);
Necroendfight:
	cout << "You've won the fight!" << endl;
	//Zombie fight happens when the Necromancer hits half health.
ZombieFight:
	Enemy* Zombie = new Enemy(Zombie);
	cout << "Zombie: \"Rgggrrrrrr\"" << endl;
	cout << "You get first strike!" << endl;
	do
	{
		//int ans;
		if (Ch->SpAttCount > 0)
			Ch->SpAttCount--;
		if (Zombie->bIsStunned)
		{
			Zombie->bIsStunned = false;
		}
	switchstart:
		cout << "What would you like to do?\n1. Attack!\n2. Use/Equip Item!\n3. Special Attack!\n4. Check Enemy!";
		if (Ch->SpAttCount > 0)
			cout << "Cooldown: " << Ch->SpAttCount << " turns left.";
		cout << endl;
		cin >> ans;
		cout << endl;
		ev.checkAns(ans, ansNum, Ch);
		if (ansNum!=-1)
            system("clear");
		switch (ansNum) {
		case 1: Ch->hitRoll(Zombie);
			break;
		case 2: {int choice;
			cout << "Which Item would you like to use?" << endl;
			Ch->getInv().DisplayInventoryName();
			cin >> choice;
			cout << endl;
			Ch->useItem(choice);
			break;
		}
		case 3:
			if (Ch->SpAttCount > 0)
			{
				cout << "You can't use that yet\n" << endl;
				goto switchstart;
			}
			else
				Ch->specialAttack(Zombie);
			break;
		case 4:
			Zombie->outHealth();
			break;
		default:
			cout << "You bumbled around like an idiot for a bit and now everyone is looking at you funny. *Pick an actual option dingus*" << endl;
			goto switchstart;
		}
		if (Zombie->checkHP())
		{
			goto NecroFight;
		}
		if (Zombie->bIsStunned == false)
		{
			Zombie->speak();
			Zombie->hitRoll(Ch);
		}
	} while (Zombie->getHealth() > 0);
	goto NecroFight;
}
*/
