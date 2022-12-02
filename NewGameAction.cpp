#include "NewGameAction.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
	Check = false;
}


NewGameAction::NewGameAction(ApplicationManager* pApp, bool Ok) : Action(pApp)
{
	Check = Ok;
}


void NewGameAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Do You Want To Start A New Game ? (y/n)");
	string checkStr = pIn->GetSrting(pOut);
	if (checkStr == "Y" || checkStr == "y")
		Check = true;
	pOut->ClearStatusBar();
}


void NewGameAction::Execute()
{
	if (!Check)
		ReadActionParameters();
	if (Check)
	{
		Grid* pGrid = pManager->GetGrid();
		Player* Player = NULL;
		CellPosition StartPosition(1);
		for (int i = 0; i < 4; i++)
		{
			Player = pGrid->GetCurrentPlayer();
			pGrid->UpdatePlayerCell(Player, StartPosition);
			Player->ResetPlayer();
			pGrid->AdvanceCurrentPlayer();
		}
		Stations::ResetStations();
		while (pGrid->GetCurrentPlayer()->GetPlayerNum() != 0)
			pGrid->AdvanceCurrentPlayer();
		pGrid->UpdateInterface();
		pGrid->SetEndGame(false);
	}
}


NewGameAction::~NewGameAction()
{

}
