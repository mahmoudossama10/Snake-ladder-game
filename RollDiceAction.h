#pragma once

#include "Action.h"

class RollDiceAction : public Action
{

	// No parameters for this action

public:
	RollDiceAction(ApplicationManager *pApp); // Constructor To Initialize The Application Manager Pointer In The Action Class

	virtual void ReadActionParameters(); //No Parameters To Read

	virtual void Execute(); //Randomizes The Number Of The Dice Rolled
	                        // Then Check If The Current Player Is Effected By Poison We Decrease The Number By 1
	                        //Then We Call Function Move For The Current Player

	virtual ~RollDiceAction(); // Desctructor
};

