#include "PasteAction.h"
#include "Grid.h"
#include "Card.h"
PasteAction::PasteAction(ApplicationManager* pApp):Action(pApp)
{

}

void PasteAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	do {
		pOut->PrintMessage("Paste Card :Please Press On The Card Location In The Grid ...");
		ObjecPosition = pIn->GetCellClicked();
		if (ObjecPosition.IsValidCell())
			if (ObjecPosition.GetCellNum() != 1 && ObjecPosition.GetCellNum() != 99)
				break;
		pGrid->PrintErrorMessage("Invlaid Input, Please Try Again ...");
	} while (1);
	pOut->ClearStatusBar();
}


void PasteAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->GetClipboard() != NULL)
	{
		ReadActionParameters();
		Card* pClipboard = pGrid->GetClipboard();
		pClipboard->Set_Position(ObjecPosition);
		if (!(pGrid->AddObjectToCell(pClipboard)))
			pGrid->PrintErrorMessage("There is already an object in this cell ");
		else
			Card::SetNumCards(Card::GetNumCards() + 1);
	}
	else
		pGrid->PrintErrorMessage("There Is No Card In The Clipboard");
}


PasteAction::~PasteAction()
{

}
