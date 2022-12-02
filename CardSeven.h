#pragma once
#include "Card.h"
class CardSeven :
    public Card
{
public:
	CardSeven(const CellPosition& pos); // A Constructor To Initialize The Cell Position Of The Card And Its Number


	virtual void Apply(Grid* pGrid, Player* pPlayer); // Simply, We Call The Get Next Player Function From The Grid Which Is The Same As Get Next Ladder
	                                                  // We Get An Array Of The Players Which Is Close To The Player And In Front Of Him
	                                                  // We Set These Players Cells With The First Cell Of The Grid

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile, Grid* pGrid);

	virtual ~CardSeven(); // A Virtual Destructor
};

