/**
 *   @file   Environments.cpp
 *   @brief  Implementation file for Environments.h
 *   @author Sean Herridge-Berry
 *   @date   Implementation phase due March 13th, 2017
 */

 #include "Environments.h"
 #include "Exceptions.h"

 #include <cctype>
 #include <fstream>
 #include <iomanip>
 #include <iostream>

 using namespace std;

 Environments::Environments(): pause('\0') {}

 int Environments::menu(Env e, Character * Ch)
 {
    switch(e)
    {
    case bazaar:
        {
            cout << endl
             << "What do you want to do!?" << endl
             << "1. Fight the mugger!" << endl
             << "2. Try to talk your way out of it!" << endl
             << "3. Just give him what he wants." << endl
             << "4. Help" << endl
             << "Enter your choice: ";
            cin >> choiceStr;
            cout << endl;
            checkAns(choiceStr,choiceNum, Ch);

	    while(choiceNum < 1 || choiceNum > 3)
            {
                if(choiceNum == 4)
                {
                    cout << "Enter 1, 2, or 3 to make your choice based on the menu options." << endl;
                    cout << "What do you want to do!?" << endl
                    << "1. Fight the mugger!" << endl
                    << "2. Try to talk your way out of it!" << endl
                    << "3. Just give him what he wants." << endl
                    << "4. Help" << endl
                    << "Enter your choice: ";
                    cin >> choiceStr;
                    cout << endl;
                    checkAns(choiceStr,choiceNum, Ch);
                }
                else
                {
                    if(choiceNum!=-1)
                        cout << "Invalid option, please try again: ";
                    cin >> choiceStr;
                    cout << endl;
                    checkAns(choiceStr,choiceNum, Ch);
                }
            }
            switch(choiceNum)
            {
                case 1:
                    cout << "You fight the mugger!" << endl;
                    break;
                case 2:
                    cout << "You try to talk your way out of it!" << endl;
                    break;
                case 3:
                    cout << "You fold to his demands." << endl;
                    break;
            }
            this->pauseGame();
            break;

            // Interaction with Merchant following Mugger

        }
    case crypt:
        {
            cout << "What do you want to do!?" << endl
                 << "1. Go Left!" << endl
                 << "2. Go Straight!" << endl
                 << "3. Go Right!" << endl
                 << "4. Go back for supplies!" << endl
                 << "5. Help" << endl
                 << "Enter your choice: ";
            cin >> choiceStr;
            cout << endl;
            checkAns(choiceStr,choiceNum, Ch);
            while(choiceNum < 1 || choiceNum > 4)
            {
                if(choiceNum == 5)
                {
                    cout << "Enter 1, 2, 3, or 4 to make your choice based on the menu options." << endl << endl;
                    cout << "What do you want to do!?" << endl
                    << "1. Go Left!" << endl
                    << "2. Go Straight!" << endl
                    << "3. Go Right!" << endl
                    << "4. Go back for supplies!" << endl
                    << "5. Help" << endl
                    << "Enter your choice: ";
                    cin >> choiceStr;
                    cout << endl;
                    checkAns(choiceStr,choiceNum, Ch);
                }
                else
                {
                    if(choiceNum!=-1)
                        cout << "Invalid option, please try again: ";
                    cin >> choiceStr;
                    cout << endl;
                    checkAns(choiceStr,choiceNum, Ch);
                }
            }
            switch(choiceNum)
            {
                case 1:
                    cout << "You go Left!" << endl;
                    break;
                case 2:
                    cout << "You go Straight!" << endl;
                    break;
                case 3:
                    cout << "You go Right!" << endl;
                    break;
                case 4:
                    cout << "You go back for supplies!" << endl;
                    break;
            }
            this->pauseGame();
            break;
        }
    case forest:
        {
            cout << endl
                 << "What do you want to do!?" << endl
                 << "1. Go Left!" << endl
                 << "2. Go Straight!" << endl
                 << "3. Go Right!" << endl
                 << "4. Go back for supplies!" << endl
                 << "5. Help" << endl
                 << "Enter your choice: ";
            cin >> choiceStr;
            cout << endl;
            checkAns(choiceStr,choiceNum, Ch);

            while(choiceNum < 1 || choiceNum > 4)
            {
                if(choiceNum == 5)
                {
                    cout << "Enter 1, 2, 3, or 4 to make your choice based on the menu options." << endl;
                    cout << "What do you want to do!?" << endl
                    << "1. Go Left!" << endl
                    << "2. Go Straight!" << endl
                    << "3. Go Right!" << endl
                    << "4. Go back for supplies!" << endl
                    << "5. Help" << endl
                    << "Enter your choice: ";
                    cin >> choiceStr;
                    cout << endl;
                    checkAns(choiceStr,choiceNum, Ch);
                }
                else
                {
                    if(choiceNum!=-1)
                        cout << "Invalid option, please try again: ";
                    cin >> choiceStr;
                    cout << endl;
                    checkAns(choiceStr,choiceNum, Ch);
                }
            }
            switch(choiceNum)
            {
                case 1:
                    cout << "You go Left!" << endl;
                    break;
                case 2:
                    cout << "You go Straight!" << endl;
                    break;
                case 3:
                    cout << "You go Right!" << endl;
                    break;
                case 4:
                    cout << "You go back for supplies!" << endl;
                    break;
            }
            this->pauseGame();
            break;
        }
    case gameEnd:
        {
            cout << endl
                 << "What do you want to do!?" << endl
                 << "1. Start Fresh." << endl
                 << "2. Quit." << endl
                 << "Enter your choice: ";
            cin >> choiceStr;
            cout << endl;
            checkAns(choiceStr,choiceNum, Ch);
            while(choiceNum < 1 || choiceNum > 2)
            {
                if(choiceNum!=-1)
                cout << "Invalid option, please try again: ";
                cin >> choiceStr;
                cout << endl;
            checkAns(choiceStr,choiceNum, Ch);
            }
            switch(choiceNum)
            {
                case 1:
                    cout << "Here we go again!" << endl;
                    break;
                case 2:
                    cout << "Thank you for playing!" << endl;
                    this->pauseGame();
                    exit(EXIT_SUCCESS);
            }
            break;
        }
    case tavern:
        {
            envMenu:
            cout << endl
                 << "What do you want to do!?" << endl
                 << "1. Ignore the old man." << endl
                 << "2. Buy another round." << endl
                 << "3. Accept the quest." << endl
                 << "4. Help" << endl
                 << "Enter your choice: ";
            cin >> choiceStr;
            cout << endl;
            checkAns(choiceStr,choiceNum,Ch);
            while(choiceNum < 1 || choiceNum > 3)
            {
                if(choiceNum == 4)
                {
                    cout << "Enter 1, 2, or 3 to make your choice based on the menu options." << endl;
                    cout << "What do you want to do!?" << endl
                    << "1. Ignore the old man." << endl
                    << "2. Buy another round." << endl
                    << "3. Accept the quest." << endl
                    << "4. Help" << endl
                    << "Enter your choice: ";
                    cin >> choiceStr;
                    cout << endl;
                    checkAns(choiceStr,choiceNum, Ch);
                }
                else
                {
                    if(choiceNum!=-1)
                    cout << "Invalid option, please try again: ";
                    cin >> choiceStr;
                    cout << endl;
                    checkAns(choiceStr,choiceNum,Ch);
                }
            }
            switch(choiceNum)
            {
                case 1:
                    cout << "You ignore him!" << endl;
                    break;
                case 2:
                    cout << "You buy another round of ale!" << endl;
                    break;
                case 3:
                    cout << "You accept!" << endl;
                    break;
            }
            this->pauseGame();
            break;
        }
    default:
        throw wrong_env{"Invalid environment argument for menu"};
    }
    return choiceNum;
 }

 void Environments::printText(Env e)
 {
    system("clear"); // Comment this out during unit testing
    ifstream inFile;
    string text;
    switch(e)
    {
       case bazaar:
        {
            inFile.open("./src/bazaar.txt");
            break;
        }
       case crypt:
        {
            inFile.open("./src/crypt.txt");
            break;
        }
       case forest:
        {
            inFile.open("./src/forest.txt");
            break;
        }
        case gameEnd:
        {
            inFile.open("./src/gameEnd.txt");
            break;
        }
        case gameStart:
        {
            inFile.open("./src/gameStart.txt");
            break;
        }
        case tavern:
        {
            inFile.open("./src/tavern.txt");
            break;
        }
        default:
            throw wrong_env{"Invalid Environment for printing text"};
    }
    getline(inFile, text);
    while(!inFile.eof())
    {
        cout << text << endl;
        getline(inFile, text);
    }
    inFile.close();
    if(e == gameStart)
    {
        cout << endl;
        cout << setw(42) << "Enter any character to continue...";
        cin >> pause;
    }
 }

 void Environments::pauseGame()
 {
    cout << "Enter any character to continue...";
    cin >> pause;
 }

void Environments::checkAns(string& ph, int& x, Character *Ch)
{
   bool isDigit = true;
   bool saved = false;
   for (auto & c: ph) c = tolower(c);
   if(ph == "save")
   {
        if (getInCombat()){
            //throw read_in_error("Cannot save while in combat");
            cout << "Cannot save while in combat" << endl;
            saved = true;
        }
        else{
            SaveLoad sl;
            sl.saveGame(Ch);
        }
   }
   if (ph.length() >= 1)
   {
      for (const auto& i : ph)
      {
	 if(!isdigit(i) && i != '.')
	 {
	    isDigit = false;
	    break;
	 }
      }
      if (isDigit)
      {
        x = atoi(ph.c_str());
      }
      if(saved)
        x = -1;
    }
}
