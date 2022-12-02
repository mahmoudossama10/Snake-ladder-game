#pragma once
#include "Action.h"
#include "Grid.h"
#include "Player.h"
// This Action Is Only Used For Testing 
class InputRollDiceAction : public Action         
{
	int DiceNumber;
public :
	InputRollDiceAction(ApplicationManager* pApp); // Constructor To Initialize The Application Manager Pointer In Action Class


	virtual void ReadActionParameters();           // Read The Value Of The Dice Number From The User


	virtual void Execute();                        // After Reading The Value Of The DiceNumber, We Get A Pointer To The Grid
	                                               // So That We Can Get The CurrentPlayer Turn
	                                               // Then We Call Function Move From Player Class Passing It The Grid Pointer And DiceNumber

};

