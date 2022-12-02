#pragma once
#include "Card.h"
#include "Player.h"
#include "Output.h"
#include "Input.h"
class CardTen : public Card
{
	static int cardPrice10;
	static int FeesToPay10;
	static Player* Owner10;

public:
	CardTen(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);
	static int GetCardPrice();
	static void ChangeOwner(Player* P);
	virtual void BuyStation(Grid* pGrid, Player* P);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile, Grid* pGrid);
	virtual ~CardTen();
};
