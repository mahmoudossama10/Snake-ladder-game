#pragma once
#include "CellPosition.h"
#include "Card.h"
class CardFour : public Card
{
public :
	CardFour(const CellPosition& pos); // Constructor To Initialize The Cell Position Of The Card And Its Number

	virtual void Apply(Grid* pGrid , Player* pPlayer); // We Just Set The Data Member (IsPrevented) True In Player Class

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile, Grid* pGrid);

	virtual ~CardFour(); // Virtual Destructor
};

