#pragma once
#include "Card.h"
class CardThree : public Card
{
public:
	CardThree(const CellPosition& pos); // A Constructor To Initialize Cell Position Of The Card And Its Number

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Simply, We Advance Current Player 3 Times Then The Same Player Will Get Another Turn :D

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile, Grid* pGrid);

	virtual ~CardThree();  // Virtual Destructor
};

