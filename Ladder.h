#pragma once
#include <fstream>
#include "GameObject.h"

class Ladder :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"
	static int NumLadders;
	CellPosition endCellPos; // here is the ladder's End Cell Position

public:

	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	void Save(ofstream& OutFile);

	static int GetNumLadders();            // Getter For The Total Number Of Ladders In The Grid

	static void SetNumLadders(int x); 

	virtual void Load(ifstream& Infile, Grid* pGrid);

	virtual bool IsOverLapping(GameObject* newObj); // Checks If A Ladder Is OverLapping With Something Else, This Is Done In This Cases :
	                                                // If The Start Cell Of The New Ladder Is Between The Start Cell And End Cell Of The Old Ladder
	                                                // If The End Cell Of The New Ladder Is Between Or Above The Start Cell Of The Old Ladder In Case The Start Cell Of The New Is Under The Old
	                                                // If The End Cell Of The New Object Is The Start Cell Of The Old One

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual ~Ladder(); // Virtual destructor
};

