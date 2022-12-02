#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
	Valid = true;
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	// Read the startPos parameter
	// Read the endPos parameter
	// Checks If The Input Is A Valid Cell Or Not
	// Check If The Inputs Will Create An OverLapping Ladder
    ///TODO: Make the needed validations on the read parameters
    // Clear messages
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();


	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	if (!startPos.IsValidCell() || !endPos.IsValidCell())
	{
		pGrid->PrintErrorMessage("The Selected Cells Is Not Valid :(");
		Valid = false;
	}
	if (startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage("Ladders Should Be Vertical ");
		Valid = false;
	}
	if (startPos.VCell() <= endPos.VCell())
	{
		pGrid->PrintErrorMessage("Start Cell Should Be Under The End Cell Of The Ladder");
		Valid = false;
	}
	if (startPos.GetCellNum() == 1)
	{
		pGrid->PrintErrorMessage("You Shouldn't Add A Ladder In The First Cell Of The Grid");
		Valid = false;
	}
	if (startPos.VCell() == 0)
	{
		pGrid->PrintErrorMessage("Start Cell Can't Be In The Last Row");
		Valid = false;
	}

	pOut->ClearStatusBar();
}



// Execute the action
void AddLadderAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
    // and hence initializes its data members
    // Create a Ladder object with the parameters read from the user
	// Add the card object to the GameObject of its Cell:
	// if the GameObject cannot be added
	// Print an appropriate message
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
	ReadActionParameters();
	if (Valid)
	{
		Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
		Ladder* pLadder;

		pLadder = new Ladder(startPos, endPos);
		if (pGrid->IsOverLapping(pLadder))
		{
			pGrid->PrintErrorMessage("OverLapping Isn't Allowed ");
			delete pLadder;
			return;
		}

		bool added = pGrid->AddObjectToCell(pLadder);

		if (!added)
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		else
			pLadder->SetNumLadders(pLadder->GetNumLadders() + 1);
	}
}
