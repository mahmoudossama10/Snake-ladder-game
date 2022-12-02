#include "CardSix.h"
#include "Cell.h"
CardSix::CardSix(const CellPosition& pos) : Card(pos)
{
	SetCardNumber(6);
}

void CardSix::Set_Destination(CellPosition Des)
{
	Destination = Des;
}

CellPosition CardSix::Get_Destination()
{
	return Destination;
}

void CardSix::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	do {
		pOut->PrintMessage("Please Select The Desired Cell");
		Destination = pIn->GetCellClicked();
		if (!Destination.IsValidCell())
		{
			pGrid->PrintErrorMessage("Selected Cell Is Invalid, Please Try Again");
			continue;
		}
		if (Destination.GetCellNum() == 99)
		{
			pGrid->PrintErrorMessage("Destination Cannot Be The End Cell");
			continue;
		}
		if (Destination == this->GetPosition())
		{
			pGrid->PrintErrorMessage("Would You Like To Go On An Infinite Loop :DD");
			continue;
		}
		break;
	} while (1);
	pOut->ClearStatusBar();
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("You Reached The Airport, You Are Travelling To Cell Num " + to_string(Destination.GetCellNum()));
	pGrid->UpdatePlayerCell(pPlayer, Destination);
	Cell* C = pPlayer->GetCell();
	if (C->GetGameObject() != NULL)
		(C->GetGameObject())->Apply(pGrid,pPlayer);
}

void CardSix::Save(ofstream& OutFile)
{
	Card::Save(OutFile);
	OutFile << "\t" << Destination.GetCellNum() << "\n";
}

void CardSix::Load(ifstream& Infile, Grid* pGrid)
{
	Card::Load(Infile, pGrid);
	int DestinationNum;
	Infile >> DestinationNum;
	Destination = Destination.GetCellPositionFromNum(DestinationNum);
}


CardSix::~CardSix()
{
}
