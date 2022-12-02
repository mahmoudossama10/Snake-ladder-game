#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v <= 8 && v >= 0)
	{
		vCell = v;
		return true;
	}
	else return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h <= 10 && h >= 0)
	{
		hCell = h;
		return true;
	}
	else return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: Implement this function as described in the .h file
	if ((vCell >= 0 && vCell <= 8) && (hCell >= 0 && hCell <= 10))
		return true;
	else return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	int cellnum=0;
	int x = cellPosition.HCell();
	int y = cellPosition.VCell();
	if (x != -1 && y != -1)
	{
		switch (y) {
		case 0: cellnum = 89 + x; break;
		case 1: cellnum = 78 + x; break;
		case 2: cellnum = 67 + x; break;
		case 3: cellnum = 56 + x; break;
		case 4: cellnum = 45 + x; break;
		case 5: cellnum = 34 + x; break;
		case 6: cellnum = 23 + x; break;
		case 7: cellnum = 12 + x; break;
		case 8: cellnum = 01 + x; break;
		}
	}
	return cellnum; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;
	int x = position.HCell();
	int y = position.VCell();
	/// TODO: Implement this function as described in the .h file
	if (cellNum >= 89) {
		position.SetVCell(0);
		position.SetHCell(cellNum - 89);
	}
	else if (cellNum >= 78) {
		position.SetVCell(1);
		position.SetHCell(cellNum - 78);
	}
	else if (cellNum >= 67) {
		position.SetVCell(2);
		position.SetHCell(cellNum - 67);
	}
	else if (cellNum >= 56) {
		position.SetVCell(3);
		position.SetHCell(cellNum - 56);
	}
	else if (cellNum >= 45) {
		position.SetVCell(4);
		position.SetHCell(cellNum - 45);
	}
	else if (cellNum >= 34) {
		position.SetVCell(5);
		position.SetHCell(cellNum - 34);
	}
	else if (cellNum >= 23) {
		position.SetVCell(6);
		position.SetHCell(cellNum - 23);
	}
	else if (cellNum >= 12) {
		position.SetVCell(7);
		position.SetHCell(cellNum - 12);
	}
	else {
		position.SetVCell(8);
		position.SetHCell(cellNum - 1);
}

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	
	/// TODO: Implement this function as described in the .h file
	CellPosition A;
	A = GetCellPositionFromNum(addedNum + GetCellNum());
	vCell = A.VCell();
	hCell = A.HCell();

	// Note: this function updates the data members (vCell and hCell) of the calling object

}

bool CellPosition::operator==(CellPosition A)
{
	if (this->hCell == A.hCell && this->vCell == A.vCell)
		return true;
	else
		return false;
}

