#include "OpenGridAction.h"
#include "Grid.h"
#include "Ladder.h"
#include "Snake.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "Stations.h"
#include "CardTwelve.h"
OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp)
{

}

void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	string Check;
	pOut->PrintMessage("Would You Like To Load A Grid From The Default File Or Another File? (y/n)");
	do
	{
		Check = pIn->GetSrting(pOut);
		if (Check == "y" || Check == "Y" || Check == "N" || Check == "n")
			break;
		pOut->PrintMessage("Invalid Input, Please Try Again ...");
	} while (1);
	if (Check == "N" || Check == "n")
	{
		string FileName;
		bool Found = false;
		do {
			pOut->PrintMessage("Enter File Name Followed By '.txt'");
			FileName = pIn->GetSrting(pOut);
			if (FILE* file = fopen(FileName.c_str(), "r"))
			{
				fclose(file);
				Found = true;
				File.open(FileName);
			}
			else
				pOut->PrintMessage("File Not Found, Please Try Again ...");
		} while (!Found);
	}
	else
		File.open("grid.txt");
	pOut->ClearStatusBar();
}


void OpenGridAction::Execute()
{
	ReadActionParameters();
	string Checker;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	do {
		int NumberOfLadders;
		int NumberOfSnakes;
		int NumberOfCards;
		int CardNumber;
		GameObject* TempGameObject = NULL;
		CellPosition Temp1, Temp2;
		pGrid->ClearAllObjects();
		pGrid->UpdateInterface();
		File >> NumberOfLadders;
		for (int i = 0; i < NumberOfLadders; i++)
		{
			TempGameObject = new Ladder(Temp1, Temp2);
			TempGameObject->Load(File, pGrid);
			TempGameObject = NULL;

		}
		File >> NumberOfSnakes;
		for (int i = 0; i < NumberOfSnakes; i++)
		{
			TempGameObject = new Snake(Temp1, Temp2);
			TempGameObject->Load(File, pGrid);
			TempGameObject = NULL;
		}
		File >> NumberOfCards;
		for (int i = 0; i < NumberOfCards; i++)
		{
			File >> CardNumber;
			switch (CardNumber)
			{
			case 1: TempGameObject = new  CardOne(Temp1); break;
			case 2: TempGameObject = new  CardTwo(Temp1); break; 
			case 3: TempGameObject = new  CardThree(Temp1); break; 
			case 4: TempGameObject = new  CardFour(Temp1); break; 
			case 5: TempGameObject = new  CardFive(Temp1); break; 
			case 6: TempGameObject = new  CardSix(Temp1); break;
			case 7: TempGameObject = new  CardSeven(Temp1); break; 
			case 8: TempGameObject = new  CardEight(Temp1); break; 
			case 9: case 10: case 11: TempGameObject = new Stations(Temp1, CardNumber); break;
			case 12: TempGameObject = new CardTwelve(Temp1); break;
			}
			TempGameObject->Load(File, pGrid);
			TempGameObject = NULL;
		}
		pOut->PrintMessage("Would You Like To Load This Grid ? (y/n)");
		Checker = pIn->GetSrting(pOut);
		if (Checker == "n" || Checker == "N")
		{
			pGrid->ClearAllObjects();
			pGrid->UpdateInterface();
		}
	} while (!File.eof() && (Checker == "n" || Checker == "N"));
	File.close();
	pOut->ClearStatusBar();
}


OpenGridAction::~OpenGridAction()
{

}
