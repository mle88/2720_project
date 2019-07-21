/**
*	@file	Dice.h
*	@brief	Rolls for attacking
*	@author Eric Heidel
*	@date	Implementation phase due March 13th, 2017
*/

#ifndef DICE_H
#define DICE_H


/**
 *@brief rolls for attacking
 */
class Dice
{
    friend class SaveLoad;
public:
    int seedroll(int);
    int randroll(int);
};

#endif // DICE_H
