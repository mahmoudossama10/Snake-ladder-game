#include "CardNine.h"
Player* CardNine::Owner9 = NULL;
int CardNine::cardPrice9 = -1;
int CardNine::FeesToPay9 = -1;
CardNine::CardNine(const CellPosition& pos) : Card(pos)
{
	SetCardNumber(9);
}

int CardNine::GetCardPrice()
{
	return cardPrice9;
}

void CardNine::ChangeOwner(Player* P)
{
	Owner9 = NULL;
	Owner9 = P;
}

void CardNine::ReadCardParameters(Grid* pGrid)
{
	if (cardPrice9 == -1)
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
		cardPrice9 = n;
		FeesToPay9 = m;
	}
}

void CardNine::BuyStation(Grid*pGrid,Player* P)
{
	if (P != NULL && Owner9 == NULL)
	{
		Owner9 = P;
		int x = P->GetWallet();
		x -= cardPrice9;
		P->SetWallet(x);
	}
	else
		pGrid->PrintErrorMessage("The Station Is Already Owned By Player #" + to_string(Owner9->GetPlayerNum()));
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	if (Owner9 == NULL)
	{
		pGrid->PrintErrorMessage("Staion Price = " + to_string(cardPrice9)+", Would You Like To Buy The Station (y/n)");
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		string Check = pIn->GetSrting(pOut);
		if (Check == "Y" || Check == "y")
		{
			int CheckWallet = pPlayer->GetWallet();
			if (CheckWallet < cardPrice9)
				pGrid->PrintErrorMessage("You Don't Have Enough Money To Buy This Station :(");
			else
			{
				BuyStation(pGrid, pPlayer);
			}
		}
	}
	else
	{
		if (pPlayer != Owner9)
		{
			int x = pPlayer->GetWallet();
			x -= FeesToPay9;
			pPlayer->SetWallet(x);
		}
	}
}

void CardNine::Save(ofstream& OutFile)
{
	Card::Save(OutFile);
	OutFile << "\t" << cardPrice9 << "\t" << FeesToPay9 << "\n";
}

void CardNine::Load(ifstream& Infile, Grid* pGrid)
{
	Card::Load(Infile, pGrid);
	Infile >> cardPrice9 >> FeesToPay9;
}


CardNine::~CardNine()
{
}
