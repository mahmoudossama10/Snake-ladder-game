#include "CardTen.h"
Player* CardTen::Owner10 = NULL;
int CardTen::cardPrice10 = -1;
int CardTen::FeesToPay10 = -1;
CardTen::CardTen(const CellPosition& pos) : Card(pos)
{
	SetCardNumber(10);
}

void CardTen::ReadCardParameters(Grid* pGrid)
{
	if (cardPrice10 == -1)
	{
		Input* pIn = pGrid->GetInput();
		Output* pOut = pGrid->GetOutput();
		int n, m;
		do {
			pOut->PrintMessage("New CardNine: Please Enter its Price ...");
			n = pIn->GetInteger(pOut);
			pOut->ClearStatusBar();
			if (n <= 0)
			{
				pGrid->PrintErrorMessage("Invalid Input, Please Try Again ...");
			}
		} while (n <= 0);
		do {
			pOut->PrintMessage("Please Enter The Fees To Be Paid ...");
			m = pIn->GetInteger(pOut);
			pOut->ClearStatusBar();
			if (m <= 0)
			{
				pGrid->PrintErrorMessage("Invalid Input, Please Try Again ...");
			}
		} while (m <= 0);
		cardPrice10 = n;
		FeesToPay10 = m;
	}
}

int CardTen::GetCardPrice()
{
	return cardPrice10;
}

void CardTen::ChangeOwner(Player* P)
{
	Owner10 = NULL;
	Owner10 = P;
}

void CardTen::BuyStation(Grid* pGrid, Player* P)
{
	if (P != NULL && Owner10 == NULL)
	{
		Owner10 = P;
		int x = P->GetWallet();
		x -= cardPrice10;
		P->SetWallet(x);
	}
	else
		pGrid->PrintErrorMessage("The Station Is Already Owned By Player #" + to_string(Owner10->GetPlayerNum()));
}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	if (Owner10 == NULL)
	{
		pGrid->PrintErrorMessage("Staion Price = " + to_string(cardPrice10) + ", Would You Like To Buy The Station (y/n)");
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		string Check = pIn->GetSrting(pOut);
		if (Check == "Y" || Check == "y")
		{
			int CheckWallet = pPlayer->GetWallet();
			if (CheckWallet < cardPrice10)
				pGrid->PrintErrorMessage("You Don't Have Enough Money To Buy This Station :(");
			else
			{
				BuyStation(pGrid, pPlayer);
			}
		}
	}
	else
	{
		if (pPlayer != Owner10)
		{
			int x = pPlayer->GetWallet();
			x -= FeesToPay10;
			pPlayer->SetWallet(x);
		}
	}
}

void CardTen::Save(ofstream& OutFile)
{
	Card::Save(OutFile);
	OutFile << "\t" << cardPrice10 << "\t" << FeesToPay10 << "\n";
}

void CardTen::Load(ifstream& Infile, Grid* pGrid)
{
	Card::Load(Infile, pGrid);
	Infile >> cardPrice10 >> FeesToPay10;
}

CardTen::~CardTen()
{
}
