#pragma once
#include "Card.h"
class CardFive :
    public Card
{
public:
	CardFive(const CellPosition& pos); // A Constructor takes card position

	
	virtual void Apply(Grid* pGrid, Player* pPlayer); // First We Make A New CellPosition Object 
	                                                  // Initializing It With The Difference Between The Current Cell Number Of Player And The Just Rolled Dice Number
	                                                  // This Is Done After Validating That The Difference Won't Be Less That 1
	                                                  // Finally We Update Player Cell With The New CellPosition Object

	virtual void Save(ofstream& OutFile);             

	virtual void Load(ifstream& Infile, Grid* pGrid); 

	virtual ~CardFive(); // A Virtual Destructor
};

