#pragma once
#include "Action.h"
class PasteAction : public Action
{
	CellPosition ObjecPosition;

	public:

		PasteAction(ApplicationManager* pApp); // Constructor To Initialize Application Manager Pointer In Action Class 

		virtual void ReadActionParameters(); // Reads The CellPosition For The Cell Meant To Add The Card To

		virtual void Execute(); // First We Check If There Is A Card In The Clipboard Or Not
		                        // If Yes, We Add The Card Saved In The Clipboard To The Cell Entered By The User
		                        // If No, An Error Message Will Be Printed

		virtual ~PasteAction(); // Destructor 
	

};

