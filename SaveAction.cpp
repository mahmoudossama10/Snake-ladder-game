#include "SaveAction.h"
#include "Grid.h"
#include "Action.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp)
{
	Outfile.open("grid.txt", ios::app);
}

void SaveAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Would You Like To Save This Grid ? (y/n)");
	do
	{
		Check = pIn->GetSrting(pOut);
		if (Check == "y" || Check == "Y" || Check == "N" || Check == "n")
			break;
		pOut->PrintMessage("Invalid Input, Please Try Again ...");
	} while (1);
	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	ReadActionParameters();
	if (Check == "y" || Check == "Y")
	{
		int total_game_objects = Ladder::GetNumLadders() + Snake::GetNumOfSnakes() + Card::GetNumCards();
		GameObject** pGameObject = new GameObject*[total_game_objects];
		Grid* pGrid = pManager->GetGrid();
		pGrid->SaveAll(pGameObject);
		Ladder** L = new Ladder*[Ladder::GetNumLadders()];
		Snake** S = new Snake * [Snake::GetNumOfSnakes()];
		Card** C = new Card * [Card::GetNumCards()];
		int x = 0, y = 0, z = 0;
		for (int i = 0; i < total_game_objects; i++)
		{
				if (dynamic_cast<Ladder*>(pGameObject[i]))
					L[x++] = dynamic_cast<Ladder*>(pGameObject[i]);
				if (dynamic_cast<Snake*>(pGameObject[i]))
					S[y++] = dynamic_cast<Snake*>(pGameObject[i]);
				if (dynamic_cast<Card*>(pGameObject[i]))
					C[z++] = dynamic_cast<Card*>(pGameObject[i]);
		}
		Outfile << Ladder::GetNumLadders() << "\n";
		for (int i = 0; i < Ladder::GetNumLadders(); i++)
			L[i]->Save(Outfile);
		Outfile << Snake::GetNumOfSnakes() << "\n";
		for (int i = 0; i < Snake::GetNumOfSnakes(); i++)
			S[i]->Save(Outfile);
		Outfile << Card::GetNumCards() << "\n";
		for (int i = 0; i < Card::GetNumCards(); i++)
			C[i]->Save(Outfile);
		pGrid->PrintErrorMessage("Save Done :), Press Any Where To Continue ...");
	}
	//int k = 0;
	//for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	//{
	//	for (int j = 0; j < NumHorizontalCells; j++) // left to right
	//	{
	//		if (CellList[i][j]->GetGameObject())
	//			GO[k++] = CellList[i][j]->GetGameObject();
	//	}
	//}

	//OutFile << Ladder::GetNumLadders() << "\n";
	//int i = 0;
	//k = 0;
	//while (i < Ladder::GetNumLadders())
	//{
	//	if (dynamic_cast<Ladder*>(GO[k]))
	//	{
	//		GO[k]->Save(OutFile);
	//		i++;
	//	}
	//	k++;
	//}
	//OutFile << Snake::GetNumOfSnakes() << "\n";
	//i = 0;
	//k = 0;
	//while (i < Snake::GetNumOfSnakes())
	//{
	//	if (dynamic_cast<Snake*>(GO[k]))
	//	{
	//		GO[k]->Save(OutFile);
	//		i++;
	//	}
	//	k++;
	//}
	//OutFile << Card::GetNumCards() << "\n";
	//i = 0;
	//k = 0;
	//while (i < Card::GetNumCards())
	//{
	//	if (dynamic_cast<Card*>(GO[k]))
	//	{
	//		GO[k]->Save(OutFile);
	//		i++;
	//	}
	//	k++;
	//}
}

SaveAction::~SaveAction()
{
	Outfile.close();
}

