
#include "DeleteGameObjectAction.h"
#include "Input.h" 
#include "Output.h"
#include "Grid.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) :Action(pApp)
{
}

void DeleteGameObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	do {
		pOut->PrintMessage("Delete Object :Please Press On Its Location In The Grid ...");
		ObjecPosition = pIn->GetCellClicked();
		if (ObjecPosition.IsValidCell())
			if (ObjecPosition.GetCellNum() != 1 && ObjecPosition.GetCellNum() != 99)
				break;
		pGrid->PrintErrorMessage("Invlaid Input, Please Try Again ...");
	} while (1);
	// 4- Make the needed validations on the read parameters

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	GameObject* Test = pGrid->HasGameObject(ObjecPosition);
	if (dynamic_cast<Ladder*>(Test))
		Ladder::SetNumLadders(Ladder::GetNumLadders() - 1);
	if (dynamic_cast<Snake*>(Test))
		Snake::SetNumSnakes(Snake::GetNumOfSnakes() - 1);
	if (dynamic_cast<Card*>(Test))
		Card::SetNumCards(Card::GetNumCards() - 1);
	pGrid->RemoveObjectFromCell(ObjecPosition);
	pGrid->UpdateInterface();
}

DeleteGameObjectAction::~DeleteGameObjectAction()
{
}
