/**
*	@file	Dice.cpp
*	@brief	Implementation file for Dice.h
*	@author Eric Heidel
*	@date	Implementation phase due March 13th, 2017
*/

#include "Dice.h"

#include <ctime>   // for time()
#include <random>
#include <stdlib.h>

int Dice::seedroll(int mx)
{
    srand((time(0)));
	int Roll = rand() % mx + 1;
	return Roll;
}
int Dice::randroll(int mx)
{
    int Roll = rand() % mx + 1;
	return Roll;
}
