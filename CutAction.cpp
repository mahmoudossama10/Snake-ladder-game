#include "CutAction.h"
#include "CopyAction.h"
#include "Card.h"

CutAction::CutAction(ApplicationManager* pApp) : Action(pApp)
{

}


void CutAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	do {
		pOut->PrintMessage("Please Select The Card You Want To Cut ... ");
		Cell_To_Cut = pIn->GetCellClicked();
		if (Cell_To_Cut.IsValidCell())
		{
			if (dynamic_cast<Card*>(pGrid->HasGameObject(Cell_To_Cut)));
			break;
		}
		pGrid->PrintErrorMessage("No Card Was Selected, Please Try Again ...");
	} while (1);
	pOut->ClearStatusBar();
}


void CutAction::Execute()
{
	if (Card::GetNumCards() > 0)
	{
		ReadActionParameters();
		Action* pAct = new CopyAction(pManager, Cell_To_Cut);
		pAct->Execute();
		delete pAct;
		Grid* pGrid = pManager->GetGrid();
		pGrid->RemoveObjectFromCell(Cell_To_Cut);
		Card::SetNumCards(Card::GetNumCards() - 1);
	}
	else
	{
		pManager->GetGrid()->PrintErrorMessage("There Is No Card To Cut Yet");
	}
}


CutAction::~CutAction()
{

}
