#include "InputRollDiceAction.h"

InputRollDiceAction::InputRollDiceAction(ApplicationManager* pApp) : Action (pApp)
{

}


void InputRollDiceAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please Enter The Dice Number ...");
	DiceNumber = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}


void InputRollDiceAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();
	Player* P = pGrid->GetCurrentPlayer();
	if (P->CheckPoisoned())
		DiceNumber--;
	P->Move(pGrid, DiceNumber);
}
