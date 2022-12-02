#pragma once
#include "Card.h"
#include "Player.h"
#include "Output.h"
#include "Input.h"
class CardEleven : public Card
{
	static int cardPrice11;
	static int FeesToPay11;
	static Player* Owner11;

public:
	CardEleven(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);
	static int GetCardPrice();
	static void ChangeOwner(Player* P);
	virtual void BuyStation(Grid* pGrid, Player* P);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile, Grid* pGrid);
	virtual ~CardEleven();
};

