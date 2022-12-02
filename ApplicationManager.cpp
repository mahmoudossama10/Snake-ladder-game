#include "ApplicationManager.h"

#include "Grid.h"
#include "AddLadderAction.h"
#include "AddSnakeAction.h"
#include "AddCardAction.h"
#include "SaveAction.h"
#include "RollDiceAction.h"
#include "OpenGridAction.h"
#include "InputRollDiceAction.h"
#include "CopyAction.h"
#include "CutAction.h"
#include "PasteAction.h"
#include "DeleteGameObjectAction.h"
#include "NewGameAction.h"
#include "RollDiceAction.h"
#include "ToDesignModeAction.h"
///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;
	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;
	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;
	case Copy_Object:
		pAct = new CopyAction(this);
		break;
	case Cut_Object:
		pAct = new CutAction(this);
		break;
	case Paste_Object:
		pAct = new PasteAction(this);
		break;
	case Save_Grid:
		pAct = new SaveAction(this);
		break;
	case Open_Grid:
		pAct = new OpenGridAction(this);
		break;
	case Delete_Object :
		pAct = new DeleteGameObjectAction(this);
		break;
	case EXIT1 : case Exit2 :
		break;

	case TO_PLAY_MODE:
		pOut->CreatePlayModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;
	case Input_Roll_Dice:
		pAct = new InputRollDiceAction(this);
		break;
	case New_Game:
		pAct = new NewGameAction(this);
		break;
	case TO_DESIGN_MODE:
		pAct = new ToDesignModeAction(this);
		break;
		

		

		///TODO: Add a case for EACH Action type in the Design mode or Play mode



	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute

		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;

		if (pGrid->GetEndGame()) // Checks If The Game Ended Or Not
		{
			pAct = new NewGameAction(this);     // If Ended Call New Game Object
			pAct->Execute();
			delete pAct;
			pAct = NULL;
		}
	}
}
