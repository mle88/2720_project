/**
 *    @file   Merchant.cpp
 *    @brief  Implementation file for Merchant class
 *    @author Erica Nordin
 *    @date   Implementation phase due March 13th, 2017
 */

#include <Merchant.h>

Inventory& getMerchInv(){
    static Inventory MerchInv;
    return MerchInv;
}
/*
void makeDefMerchInv(){
    Item *i1 = new Weapon(swordshield);
    Item *i2 = new Weapon(longsword);
    Item *i3 = new Weapon(bow);
    Item *i4 = new SpecialItem(potion);
    Item *i5 = new SpecialItem(potion);
    MerchInv.AddItem(i1);
    MerchInv.AddItem(i2);
    MerchInv.AddItem(i3);
    MerchInv.AddItem(i4);
    MerchInv.AddItem(i5);
    //cout << "The default merchant inventory has been created." << endl;
    //MerchInv.DisplayInventoryName();
}*/

Merchant::Merchant(){// : sellable(inv){
    //cout << "This is what is being passed to the merchant constructor: " << endl;
    //inv.DisplayInventoryName();
    sellable = getMerchInv();
    /*
    cout << "MerchInv" << endl;
    for(int i=0; i<MerchantInvSize; i++){
        cout << getMerchInv().enumIntAtIndex(i) << " ";
    }
    cout << "sellable" << endl;
    for(int i=0; i<MerchantInvSize; i++){
        cout << sellable.enumIntAtIndex(i) << " ";
    }
    */
    //sellable.DisplayInventoryName();
/*string x;
for (unsigned int i; i < sizeof(inv); i++){
    // Copy the items in inv into the merchant's inventory attribute. Replace with inventory initializer list if possible.
    string x = inv; // Placeholder
}*/

}

Merchant::~Merchant(){
    sellable.Empty();
    //for(int i = 0; i<sellable.size(); i++)
    //    delete sellable[i];

}

void Merchant::speak(){
    cout << "Merchant: Hello! You look like an adventurer. I carry only the finest weapons and health potions to assist you on your quests." << endl;
    // Dialogue options
}

void Merchant::sell(item i, Character *c){
    bool sold = 0;
    //cout << "Character's money: " << c->getMoney() << endl
    //<< "Item's price: " << Weapon(i).getPrice() << endl;
    Item *sellingItem;
    switch(i){
    case 2:
    case 3:
    case 4:
        sellingItem = new Weapon(i);
        break;
    case 5:
        sellingItem = new SpecialItem(i);
        break;
    default:
        throw switchcase_error("The merchant shouldn't have that");
    }
    if (c->getMoney() < sellingItem->getPrice()){
        cout << "You're too poor to buy that." << endl << endl;
        return;
    }
    sold = sellable.RemoveItem(i);
    if (sold == 1){
        Item *aPotion = new SpecialItem(potion);
        sellable.AddItem(aPotion);
        getMerchInv() = sellable;
        /*
        for(int i=0; i<MerchantInvSize; i++){
        cout << getMerchInv().enumIntAtIndex(i) << " ";
    }
    */
        c->addToInv(sellingItem);
        c->changeMoney(-1*(sellingItem->getPrice()));
    }
    else{
        cout << "The merchant does not have one to sell you." << endl << endl;
    }
}

//void Merchant::interaction(){
//}

void Merchant::displayWares(){
    sellable.DisplayInventory();
}

void Merchant::theft(Character *c){
    Dice d;
    int roll;
    item enumStolen;
    Item *stolen;
    roll = d.seedroll(20);
    if (roll >= 10){
        enumStolen = sellable.removeRandomItem();
        // Switch case for enum: item or weapon
        switch(enumStolen){
        case 2:
        case 3:
        case 4:
            stolen = new Weapon(enumStolen);
            break;
        case 5:
            stolen = new SpecialItem(enumStolen);
            break;
        default:
            throw switchcase_error("The merchant shouldn't have that kind of item");
        }
        //Item *stolen = sellable.removeRandomItem();
        //Item *stolen = new Item(potion);

        Item *aPotion = new SpecialItem(potion);
        sellable.AddItem(aPotion);
        getMerchInv() = sellable;
        cout << "You've successfully stolen! You received a "
        << stolen->getName() << endl;
        c->addToInv(stolen);
        delete aPotion; delete stolen;
    }
    else{
        cout << "Merchant: You dirty thief!" << endl
        << "You failed to steal anything, and have lost all your items except your dagger." << endl;
        c->loseAllItems();
    }

}
