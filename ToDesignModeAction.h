#pragma once
#include "Action.h"
#include "Grid.h"
#include "Output.h"
#include "Input.h"
#include "NewGameAction.h"
class ToDesignModeAction : public Action
{
	bool Check;
public :

	ToDesignModeAction(ApplicationManager* pApp); // Constructor To Initialize Application Manager Pointer In Action Class

	virtual void ReadActionParameters();          // Checks If The User Wants To Get Back To The Design Mode
	                                              // This Is Done To Alert The User That The Current Game Will Be Cancelled

	virtual void Execute();                       // If Yes, We Execute (New Game) Action Then Create The Design Mode Statues Bar

	virtual ~ToDesignModeAction();
};

