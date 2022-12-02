#include "Stations.h"
#include "Player.h"
int Stations::StationPrice[] = { 0,0,0 };
int Stations::FeesToPay[] = { 0,0,0 };
Player* Stations::Owner[] = { NULL , NULL , NULL };
Stations::Stations(const CellPosition& pos, int StationNumber) : Card(pos)
{
	cardNumber = StationNumber;
}

int Stations::GetCardPrice(int stationNum)
{
	return StationPrice[stationNum-9];
}

void Stations::Set_Station_Price(int St_Price, int St_Num)
{
	StationPrice[St_Num - 9] = St_Price;
}

void Stations::Set_Station_Fees(int St_Fees, int St_Num)
{
	FeesToPay[St_Num - 9] = St_Fees;
}

int Stations::GetCardFees(int stationNum)
{
	return FeesToPay[stationNum-9];
}

void Stations::ChangeOwner(Player* P, int stationNum)
{
	Owner[stationNum-9] = NULL;
	Owner[stationNum-9] = P;
}

Player* Stations::GetCardOwner(int StationNumber)
{
	return Owner[StationNumber - 9];
}


void Stations::ReadCardParameters(Grid* pGrid)
{
	if (StationPrice[cardNumber - 9] == 0)
	{
		Input* pIn = pGrid->GetInput();
		Output* pOut = pGrid->GetOutput();
		int n, m;
		do {
			pOut->PrintMessage("New Card " + to_string(cardNumber) + ": Please Enter its Price ...");
			n = pIn->GetInteger(pOut);
			pOut->ClearStatusBar();
			if (n <= 0)
			{
				pGrid->PrintErrorMessage("Station Price Cannot Be Zero Or Negative");
			}
		} while (n <= 0);
		do {
			pOut->PrintMessage("Please Enter The Fees To Be Paid ...");
			m = pIn->GetInteger(pOut);
			pOut->ClearStatusBar();
			if (m <= 0)
			{
				pGrid->PrintErrorMessage("Station Fees Cannot Be Zero Or Negative");
			}
		} while (m <= 0);
		StationPrice[cardNumber - 9] = n;
		FeesToPay[cardNumber - 9] = m;
		pOut->ClearStatusBar();
	}
}

void Stations::BuyStation(Grid* pGrid, Player* P)
{
	if (P != NULL && Owner[cardNumber - 9] == NULL)
	{
		Owner[cardNumber - 9] = P;
		P->DecreaseWallet(StationPrice[cardNumber - 9]);
	}
	else
		pGrid->PrintErrorMessage("The Station Is Already Owned By Player #" + to_string(Owner[cardNumber - 9]->GetPlayerNum()));
}

void Stations::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	if (Owner[cardNumber - 9] == NULL)
	{
		pGrid->PrintErrorMessage("Staion Price = " + to_string(StationPrice[cardNumber - 9]) + ", Would You Like To Buy The Station (y/n)");
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		string Check = pIn->GetSrting(pOut);
		if (Check == "Y" || Check == "y")
		{
			int CheckWallet = pPlayer->GetWallet();
			if (CheckWallet < StationPrice[cardNumber - 9])
				pGrid->PrintErrorMessage("You Don't Have Enough Money To Buy This Station :(");
			else
			{
				BuyStation(pGrid, pPlayer);
			}
		}
	}
	else
	{
		if (pPlayer != Owner[cardNumber - 9])
		{
			pGrid->PrintErrorMessage("Pay Player#" + to_string(Owner[cardNumber - 9]->GetPlayerNum() + 1) + " " + to_string(FeesToPay[cardNumber - 9]) + " Coins");
			pPlayer->DecreaseWallet(FeesToPay[cardNumber - 9]);
			Owner[cardNumber - 9]->IncreaseWallet(FeesToPay[cardNumber - 9]);
		}
	}
}

void Stations::Save(ofstream& OutFile)
{
	Card::Save(OutFile);
	OutFile << "\t" << StationPrice[cardNumber - 9] << "\t" << FeesToPay[cardNumber - 9] << "\n";
}

void Stations::Load(ifstream& Infile, Grid* pGrid)
{
	Card::Load(Infile, pGrid);
	Infile >> StationPrice[cardNumber - 9] >> FeesToPay[cardNumber - 9];
}

void Stations::ResetStations()
{
	for (int i = 0; i < 3; i++)
		ChangeOwner(NULL, i + 9);
}

Stations::~Stations()
{
}