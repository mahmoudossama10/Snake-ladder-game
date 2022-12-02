#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) : Card(pos)
{
	AmountOfCoins = -1;
	SetCardNumber(8);
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	do {
		pOut->PrintMessage("New CardEight : Please Enter The Amount Of Money To Exit The Prison");
		AmountOfCoins = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();
		if (AmountOfCoins > 0)
			break;
		pGrid->PrintErrorMessage("Invalid Input , Please Try Again ...");
	} while (1);
}

void CardEight::SetAmountOfCoins(int x)
{
	if (x > 0)
		AmountOfCoins = x;
}

int CardEight::Get_Amount_Of_Coins()
{
	return AmountOfCoins;
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (pPlayer->GetWallet() >= AmountOfCoins)
	{
		pOut->PrintMessage("Would you like to pay " + to_string(AmountOfCoins) + " or to stay in prison for 3 rounds? (y,n)");
		string Check = pIn->GetSrting(pOut);
		if (Check == "y" || Check == "Y")
		{
			pGrid->PrintErrorMessage("You Paid The Taxes, You Are Free To Go");
			pPlayer->DecreaseWallet(AmountOfCoins);
		}
		else
		{
			pGrid->PrintErrorMessage("For Evading Taxes, Stop 3 Rounds And Go To Prison");
			pPlayer->SetInPrison(true);
		}
	}
	else
	{
		pGrid->PrintErrorMessage("For Being Bad Citizen, Stop 3 Rounds And Go To Prison");
		pPlayer->SetInPrison(true);
	}
}

void CardEight::Save(ofstream& OutFile)
{
	Card::Save(OutFile);
	OutFile << "\t" << AmountOfCoins << "\n";
}

void CardEight::Load(ifstream& Infile, Grid* pGrid)
{
	Card::Load(Infile, pGrid);
	Infile >> AmountOfCoins;
}

CardEight::~CardEight()
{
}


