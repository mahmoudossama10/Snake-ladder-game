#include "ToDesignModeAction.h"

ToDesignModeAction::ToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{

}

void ToDesignModeAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Are You Sure You Want To Return To Design Mode ? You Will Start A New Game (y,n)");
	string Checker = pIn->GetSrting(pOut);
	if (Checker == "y" || Checker == "Y")
		Check = true;
	else
		Check = false;
	pOut->ClearStatusBar();
}

void ToDesignModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	ReadActionParameters();
	if (Check)
	{
		Action* Temp = new NewGameAction(pManager , true);
		Temp->Execute();
		pOut->CreateDesignModeToolBar();
		delete Temp;
	}
}

ToDesignModeAction::~ToDesignModeAction()
{
}
