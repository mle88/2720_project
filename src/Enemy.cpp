/**
 *    @file    Enemy.cpp
 *    @brief   Implementation file for Enemy class
 *    @author  Erica Nordin
 *    @date    Implementation phase due March 13th, 2017
 */
#include <Enemy.h>
//#include <iostream>
vector<bool> &getEnemyDefeated(){
    static vector<bool> enemyDefeated(numEnemies, 0);
    return enemyDefeated;
}

Enemy::Enemy(EnemyType id) : identity(id) {

    switch (identity) {
    case Mimic: // Balanced
        attack = 6;
        defense = 12;
        health = 70;
        dex = 2;
        strength = 1;
        break;
    case Mugger: // Early enemy, easy to beat
        attack = 4;
        defense = 10;
        health = 50;
        dex = 3;
        strength = 0;
        break;
    case Bear: // High attack, but easy to hit
        attack = 8;
        defense = 8;
        health = 80;
        dex = 0;
        strength = 3;
        break;
    case Bees: // Low health, but hard to hit
        attack = 4;
        defense = 16;
        health = 20;
        dex = 4;
        strength = 1;
        break;
    case Necromancer: // Hardest enemy in all respects
        attack = 10;
        defense = 16;
        health = 100;
        dex = 3;
        strength = 3;
	case Zombie: //Necromancer minion
		attack = 4;
		defense = 10;
		health = 20;
		dex = 0;
		strength = 2;



        break;
    }
}

void Enemy::dropItem(Character *ch){
    // Drop a bit of money and an item
    bool defeatEndsCombat = 1;
    Item *i;
    bool doesDrop = 0;
    switch (identity) {
    case Mimic:
        getEnemyDefeated()[0] = 1;
        i = new SpecialItem(key);
		cout << "The mimics arms and legs fold back into the chest. You peak inside..." << endl;
        cout << "The mimic had a key! Perhaps it opens the door you passed on the way in..." << endl;
		cout << "Gained 50 Gold!" << endl;
		ch->changeMoney(50);
        doesDrop = 1;
        break;
    case Mugger:
        getEnemyDefeated()[1] = 1;
		cout << "Mugger \"H-How could this happen...\"" << endl;
		cout << "As the Mugger lay pitifully before you, you figured it would be kind of ironic if you mugged him, so you did. Gained 100 gold!" << endl;
		ch->changeMoney(100);
        break;
    case Bear:
        getEnemyDefeated()[2] = 1;
		if (health <= 0)
			cout << "The Bear slumps over dead." << endl;
		else
			cout << "The Bear runs off with his honey. Hopefully he doesn't come back" << endl;
		cout << "The Bear drops some gold. I don't think that's normal...?" << endl;
		ch->changeMoney(50);
        break;
    case Bees:
        getEnemyDefeated()[3] = 1;
        i = new SpecialItem(honey);
		cout << "Destroying the swarm of bees has allowed you to take their delicious honey. \nThey also dropped some gold, why did they have that..." << endl;
        doesDrop = 1;
        for(int i=0; i<numEnemies; i++){
        cout << getEnemyDefeated()[i] << " ";
    }
        break;

    case Necromancer:
        getEnemyDefeated()[4] = 1;
        i = new SpecialItem(amulet);
        cout << "You remove the amulet from the Necromancer's neck. His body disintegrates into dust." << endl;
        doesDrop = 1;
        break;
	case Zombie:
		getEnemyDefeated()[5] = 1;
		cout << "The Zombie collapses before you, time to switch your focus back to the Necromancer!" << endl;
		cout << "Necromancer: \"Impossible!\"" << endl;
		defeatEndsCombat = 0;
		break;
    if (doesDrop){
        Item *k = i;
        ch->addToInv(k);
        delete k; k = nullptr;
    }
    }
    if (defeatEndsCombat)
        getInCombat() = 0;
    delete i;
    i = nullptr;
}

void Enemy::takeDamage(int attackerRoll, Character *ch){
    health -= attackerRoll;
    cout<<"You dealt "<<attackerRoll<<" damage!"<<endl;
    if (health <= 0){
        cout << "You have defeated your enemy!" << endl;
        this->dropItem(ch);
    }
}

void Enemy::hitRoll(Character *ch, bool bGuaranteedHit){
    if (bGuaranteedHit)
        goto Hit;

    size_t roll;
    Dice d;
    roll = d.seedroll(20) + dex;
	if (roll > ch->getDefense()) {
	Hit:
		switch (identity) {
		case Mugger:
			cout << "The Mugger thrusts his knife into your kidney, that must have hurt." << endl;
			break;
		case Bear:
			cout << "The Bear claws at your stomach. You try to play dead but he just bites your jugular. \nYou're not sure how you're alive." << endl;
			break;
		case Bees:
			cout << "You can feel hundreds of Bees stinging you all over. You try to call for help, but all you're able to say is \"Not the Bees!\"" << endl;
			break;
		case Mimic:
			cout << "The Mimic roundhouse kicks you." << endl;
			break;
		case Necromancer:
			cout << "The Necromancer chants some incantations and you suddenly feel like dying sounds pretty okay." << endl;
			break;
		case Zombie:
			cout << "The Zombie bites your arm. You're pretty sure it's infected now." << endl;
			break;
		}
        ch->takeDamage(d.randroll(attack) + strength);
    }
	else {
		switch (identity)
    {
				case Mugger:
					cout << "The Mugger trys to stab you, but you dodged it." << endl;
					break;
				case Bear:
					cout << "The Bear charges you, but you're able to swiftly roll out of the way." << endl;
					break;
				case Bees:
					cout << "You flail around like an idiot for a bit trying to dodge the stings. Somehow, it works." << endl;
					break;
				case Mimic:
					cout << "The Mimic trys to kick you, but you took Taekwondo lessons as a kid so you totally blocked it." << endl;
					break;
				case Necromancer:
					cout << "The Necromancer chants some incantations, but stutters. Nothing happens." << endl;
					break;
				case Zombie:
					cout << "The Zombie slowly reaches out trying to grab you, you sorta just take a few steps back." << endl;
					break;
	}
}
}

size_t Enemy::getDefense(){
    return defense;
}

int Enemy::getHealth(){
    return health;
}

bool Enemy::checkHP(){
    if (health > 0)
        return 0;
    else
        return 1;
}

void Enemy::Stunned()
{
    bIsStunned = true;
}

void Enemy::speak()
{
    switch (identity)
    {
        case Mimic:
            cout << "Mimic: \"You can't escape my grasp!\"" << endl;
            break;
        case Mugger:
        {
            size_t phrase = rand() % 6 + 1;
            if (health <= 10)
            {
                switch(phrase)
                {
                    case 1: cout << "Mugger: \"...\"" << endl;
                    break;
                    case 2: cout << "Mugger: \"I'll... Kill... You\""<< endl;
                    break;
                    case 3: cout << "Mugger: \"W-Why... Why is this happening...?\"" << endl;
                    break;
                    case 4: cout << "Mugger \"I... I don't want to die!\"" << endl;
                    break;
                    case 5: cout << "The Mugger is throwing up blood" << endl;
                    break;
                    case 6: cout << "The Mugger looks at you with remorse in his eyes." << endl;
                    break;
                }
            }
            else
            {
                switch (phrase)
                {
                    case 1 : cout << "Mugger: \"Just die already!\"" << endl;
                    break;
                    case 2 : cout << "Mugger: \"Stop resisting and noone has to get hurt!\"" << endl;
                    break;
                    case 3 : cout << "Mugger: \"Bastard!\"" << endl;
                    break;
                    case 4 : cout << "Mugger: \"I'll kill you!\"" << endl;
                    break;
                    case 5 : cout << "Mugger: \"Take this!\"" << endl;
                    break;
                    case 6 : cout << "Mugger: \"This could be so much easier if you'd just give me your damn money!\"" << endl;
                    break;
                }
            }
            break;
        }
        case Bear:
            cout << "Bear: \"Rawr\"" << endl;
            break;
        case Bees:
            cout << "Bees: \"Bzzzzzzzzzz\"" << endl;
            break;
        case Necromancer:
        {
            size_t phrase = rand() % 6 + 1;
            if (health <= 30)
            {
                switch(phrase)
                {
                    case 1: cout << "Necromancer: \"So this is how it feels...\"" << endl;
                    break;
                    case 2: cout << "Necromancer: \"Where did I go wrong...?\""<< endl;
                    break;
                    case 3: cout << "Necromancer: \"This is how it ends...?\"" << endl;
                    break;
                    case 4: cout << "Necromancer: \"I won't die... not like this...\"" << endl;
                    break;
                    case 5: cout << "The Necromancer doesn't look to good." << endl;
                    break;
                    case 6: cout << "The Necromancer laughs weakly." << endl;
                    break;
                }
            }
            else
            {
                switch (phrase)
                {
                    case 1 : cout << "Necromancer: \"You'll never win.\"" << endl;
                    break;
                    case 2 : cout << "Necromancer: \"Impudent fool.\"" << endl;
                    break;
                    case 3 : cout << "The Necromancer cackles with laughter" << endl;
                    break;
                    case 4 : cout << "Necromancer: \"You'll make a great addition to my army...\"" << endl;
                    break;
                    case 5 : cout << "Necromancer: \"Pathetic.\"" << endl;
                    break;
                    case 6 : cout << "Necromancer: \"You must really want to die.\"" << endl;
                    break;
                }
            }
        }
        case Zombie:
            cout << "The Zombie is stumbling towards you." << endl;
            break;
   }
}

void Enemy::outHealth()
{
	cout << "It looks like the enemy has " << health << " health left." << endl;
}
