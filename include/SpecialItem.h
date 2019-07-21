/**
 *    @file   SpecialItem.h
 *    @brief  Special Item  class definition file
 *    @author Michelle Le
 *    @date   Implementation phase due March 13th, 2017
 */

#ifndef SPECIALITEM_H
#define SPECIALITEM_H

#include "Item.h"

/**
 *   @brief derived class Special Item  from superclass Item
 */
class SpecialItem:public Item
{
    friend class SaveLoad;
  public:
    /**
    * @brief The Special Item constructor.
    * @param item, takes in enum item to determine and name  description
    */
   SpecialItem(item b);
    /**
    * @brief Getter for the special item and
    *allows for this special item to be added to inventory
    */
    /**
    * @brief The SpecialItem deconstructor.
    */
   virtual ~SpecialItem(){}
};

#endif
