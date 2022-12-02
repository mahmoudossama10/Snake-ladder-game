
#include "Card.h"
class CardTwo :
    public Card
{
public:
	CardTwo(const CellPosition& pos); // A Constructor To Initialize The Card Position And Its Number

	virtual void Apply(Grid* pGrid, Player* pPlayer); // We Get The Next Ladder In Front Of The Player
	                                                  // If There Is One We Update The Player Cell With The Start Cell Of This Ladder
	                                                  // Then We Apply It

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile, Grid* pGrid);

	virtual ~CardTwo(); // A Virtual Destructor
};
