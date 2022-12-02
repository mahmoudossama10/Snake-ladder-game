#include "AddSnakeAction.h"
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{

}


void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	bool ValidCell;
	// Read the startPos parameter
	ValidCell = false;
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	// Checks If The Input Is A Valid Cell Or Not
	if (!startPos.IsValidCell() || !endPos.IsValidCell())
	{
		pGrid->PrintErrorMessage("The Selected Cells Is Not Valid :(");
		Valid = false;
	}
	if (startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage("Snakes Should Be Vertical ");
		Valid = false;
	}
	if (startPos.VCell() >= endPos.VCell())
	{
		pGrid->PrintErrorMessage("Start Cell Should Be Above The End Cell Of The Snake");
		Valid = false;
	}
	if (startPos.GetCellNum() == 99)
	{
		pGrid->PrintErrorMessage("You Shouldn't Add A Snake In The Last Cell Of The Grid");
		Valid = false;
	}
	if (startPos.VCell() == 8)
	{
		pGrid->PrintErrorMessage("Start Cell Can't Be In The First Row");
		Valid = false;
	}
	// Check If The Inputs Will Create An OverLapping Ladder

///TODO: Make the needed validations on the read parameters


// Clear messages
	pOut->ClearStatusBar();
}


void AddSnakeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Snake* pSnake;
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
		ReadActionParameters();
		if (Valid)
		{
			// Create a Snake object with the parameters read from the user
			pSnake = new Snake(startPos, endPos);
			if (pGrid->IsOverLapping(pSnake))
			{
				pGrid->PrintErrorMessage("OverLapping Isn't Allowed");
				delete pSnake;
				return;
			}

			// Add the card object to the GameObject of its Cell:
			bool added = pGrid->AddObjectToCell(pSnake);

			// if the GameObject cannot be added
			if (!added)
				// Print an appropriate message
				pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
			else
				pSnake->SetNumSnakes(pSnake->GetNumOfSnakes() + 1);
			// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction
		}
}


AddSnakeAction::~AddSnakeAction()
{

}

