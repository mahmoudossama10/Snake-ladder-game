#include "CardEleven.h"
Player* CardEleven::Owner11 = NULL;
int CardEleven::cardPrice11 = -1;
int CardEleven::FeesToPay11 = -1;
CardEleven::CardEleven(const CellPosition& pos) : Card(pos)
{
	SetCardNumber(11);
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{
	if (cardPrice11 == -1)
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
		cardPrice11 = n;
		FeesToPay11 = m;
	}
}

int CardEleven::GetCardPrice()
{
	return cardPrice11;
}

void CardEleven::ChangeOwner(Player* P)
{
	Owner11 = NULL;
	Owner11 = P;
}

void CardEleven::BuyStation(Grid* pGrid, Player* P)
{
	if (P != NULL && Owner11 == NULL)
	{
		Owner11 = P;
		int x = P->GetWallet();
		x -= cardPrice11;
		P->SetWallet(x);
	}
	else
		pGrid->PrintErrorMessage("The Station Is Already Owned By Player #" + to_string(Owner11->GetPlayerNum()));
}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	if (Owner11 == NULL)
	{
		pGrid->PrintErrorMessage("Staion Price = " + to_string(cardPrice11) + ", Would You Like To Buy The Station (y/n)");
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		string Check = pIn->GetSrting(pOut);
		if (Check == "Y" || Check == "y")
		{
			int CheckWallet = pPlayer->GetWallet();
			if (CheckWallet < cardPrice11)
				pGrid->PrintErrorMessage("You Don't Have Enough Money To Buy This Station :(");
			else
			{
				BuyStation(pGrid, pPlayer);
			}
		}
	}
	else
	{
		if (pPlayer != Owner11)
		{
			int x = pPlayer->GetWallet();
			x -= FeesToPay11;
			pPlayer->SetWallet(x);
		}
	}
}

void CardEleven::Save(ofstream& OutFile)
{
	Card::Save(OutFile);
	OutFile << "\t" << cardPrice11 << "\t" << FeesToPay11 << "\n";
}

void CardEleven::Load(ifstream& Infile, Grid* pGrid)
{
	Card::Load(Infile, pGrid);
	Infile >> cardPrice11 >> FeesToPay11;
}


CardEleven::~CardEleven()
{
}
