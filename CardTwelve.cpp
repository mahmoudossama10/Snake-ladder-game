#include "CardTwelve.h"
#include "Stations.h"
CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos)
{
	cardNumber = 12;
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Player* Players[4];
	for (int i = 0; i < 4; i++)
	{
		Players[i] = pGrid->GetCurrentPlayer();
		pGrid->AdvanceCurrentPlayer();
	}
	Player* LessWalletPlayer = Players[0]->GetLessWallet(Players, 4);
	int n = 0;
	for (int i = 0; i < 3; i++)
	{
		if (Stations::GetCardOwner(i+9) == pPlayer)
			n++;
	}
	if (n > 0)
	{
		int* StationsOwned = new int[n];
		int j = 0;
		for (int i = 0; i < 3; i++)
		{
			if (Stations::GetCardOwner(i + 9) == pPlayer)
				StationsOwned[j++] = i;
		}
		int MostValuble = Stations::GetCardPrice(StationsOwned[0] + 9);
		int StationNumber = StationsOwned[0];
		for (int i = 1; i < n; i++)
		{
			if (Stations::GetCardPrice(StationsOwned[i] + 9) > MostValuble)
			{
				MostValuble = Stations::GetCardPrice(StationsOwned[i] + 9);
				StationNumber = StationsOwned[i];
			}
		}
		Stations::ChangeOwner(LessWalletPlayer, StationNumber+9);
		pGrid->PrintErrorMessage("Now Player #" + to_string(LessWalletPlayer->GetPlayerNum() + 1) + " Owns Station#" + to_string(StationNumber + 9));
		delete[] StationsOwned;
	}
}

void CardTwelve::Save(ofstream& OutFile)
{
	Card::Save(OutFile);
	OutFile << "\n";
}

void CardTwelve::Load(ifstream& Infile, Grid* pGrid)
{
	Card::Load(Infile, pGrid);
}



CardTwelve::~CardTwelve()
{
}
