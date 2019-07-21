/**
*   @file   SpecialItem.cpp
*   @brief  Implementation file for SpecialItem class
*   @author Michelle Le
*   @date   Implementation phase due March 13th, 2017
*/

#include "SpecialItem.h"

SpecialItem::SpecialItem(item a):Item(a)
{
   switch (a)
     {
         case amulet:
         {
             name = "Amulet";
             price =0;
             description= "Use this for special cases";
             enumVal=6;
             break;
             }
         case honey:
         {
             name = "Honey";
             price=0;
             description= "Used in special cases. I hear bears like honey.";
             enumVal=7;
             break;
             }
         case key:
            {
                name="Master Key";
                price = 0;
                description=" Use to unlock a Necromancers door";
                enumVal=7;
                break;
            }
         case potion:
             {
                 price = 20;
                 name = "Potion";
                 description = "Regenerates 15 HP";
                 enumVal = 5;
                 break;
                 }
            }

}

