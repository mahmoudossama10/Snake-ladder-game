#pragma once
#include "CellPosition.h"
#include "Output.h"
#include "Input.h"
#include "Card.h"
class CardSix : public Card
{
	CellPosition Destination;
public :
	CardSix(const CellPosition& pos); // Constructor To Initialize The Cell Position Of The Card And Its Number

	void Set_Destination(CellPosition Des); // Setter For The Destination

	CellPosition Get_Destination();   // Getter For The Destination

	virtual void ReadCardParameters(Grid* pGrid); // Reads From The User The Cell Position Meant To Go To After Stopping On The Card
	                                              // This Is Done For Initializing Destination After Making Needed Validations

	virtual void Apply(Grid* pGrid, Player* pPlayer); // We Just Update The Player Cell Position To The Destination 
	                                                  // Then We Check If This Cell Has A Game Object Or Not
	                                                  // If There, Apply Its Effect

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile, Grid* pGrid);

	virtual ~CardSix();                 // Virtual Destructor
};

