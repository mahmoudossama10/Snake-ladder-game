#pragma once
#include "Card.h"
#include "Player.h"
#include "Output.h"
#include "Input.h"
class CardNine : public Card
{
	static int cardPrice9;
	static int FeesToPay9;
	static Player* Owner9;

public:
	CardNine(const CellPosition& pos);
	static int GetCardPrice();
	static void ChangeOwner(Player* P);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void BuyStation(Grid* pGrid, Player* P);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile, Grid* pGrid);
	virtual ~CardNine();
};

