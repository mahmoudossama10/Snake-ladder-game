#pragma once
#include "Action.h"
#include "Grid.h"
#include "Card.h"
class CutAction : public Action
{
	CellPosition Cell_To_Cut;
public :
	CutAction(ApplicationManager* pApp);  // Constructor

	virtual void ReadActionParameters(); // Reads The Cell Position Of The Card That Is Needed To Be Cut


	virtual void Execute();  // Call Copy Card Action To Send The Card To The Clipboard
	                         // Then We Should Call RemoveObjectFromCell So That We Can Delete It From Its Current Cell

	virtual ~CutAction();  // Virtual Destructor
};

