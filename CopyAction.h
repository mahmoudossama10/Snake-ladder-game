#pragma once
#include "Action.h"
class CopyAction : public Action
{
	CellPosition ObjectPosition;  //the cell position
public:
	CopyAction(ApplicationManager* pApp); // A Constructor

	CopyAction(ApplicationManager* pApp, CellPosition CardPos); // Overloaded Constructor Will Be Used Inside Cut Action

	virtual void ReadActionParameters(); // Reads Copy Card Action Parameters (cardPosition)

	virtual void Execute(); // Create A New Card With The Same Information And Position Of The Card
	                        // Then, Send The New Card To  Clipboard So That It Can Be Placed By Paste Action

	virtual ~CopyAction(); // A Virtual Destructor
};

