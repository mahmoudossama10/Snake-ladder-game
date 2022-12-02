#pragma once
#include "Grid.h"
class SpecialAttacks
{
protected :
	Grid* pGrid;
public :
	SpecialAttacks(Grid* pGrid);
	virtual void Execute() = 0;
	virtual ~SpecialAttacks();
};

