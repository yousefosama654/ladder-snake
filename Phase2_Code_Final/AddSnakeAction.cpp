#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Snake.h"



AddSnakeAction::AddSnakeAction(ApplicationManager *pApp) : Action(pApp)
{
}


AddSnakeAction::~AddSnakeAction(void)
{
}
 void AddSnakeAction::ReadActionParameters(){
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	bool ValidorNo = false;
	do {
		pOut->PrintMessage("New Snake: Click on its Start Cell ...");
		startPos = pIn->GetCellClicked();
		pOut->PrintMessage("New Snake: Click on its End Cell ...");
		endPos = pIn->GetCellClicked();
		if (endPos.GetCellNum() < startPos.GetCellNum() && endPos.HCell() == startPos.HCell() && startPos.VCell() != 8 && startPos.GetCellNum() != 99)
		{
			ValidorNo = true;
		}
		else
		{
			pOut->PrintMessage("Invalid Sanke input, Click to try again ...");
			pIn->GetCellClicked();
		}
	} while (!ValidorNo);
	/*
	bool start_pos_valid=false;
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	while(!start_pos_valid)
	{
		startPos = pIn->GetCellClicked();
		if(startPos.VCell()==8)
		{	
			pOut->PrintMessage("invalid start cell,Please try again");
		}
		else 
		{
			start_pos_valid = true;
		}
	}
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	
	bool end_pos_valid=false;
	while(!end_pos_valid)
	{
	endPos = pIn->GetCellClicked();
	if(startPos.HCell()!=endPos.HCell()||endPos.VCell()<startPos.VCell())
	{
		pOut->PrintMessage("invalid end cell ,try again");
	}
	else 
	{
		end_pos_valid = true;
	}
	}
	*/
	pOut->ClearStatusBar();

}
 
 void AddSnakeAction::Execute()
 {
 ReadActionParameters();
 Snake * pSnake= new Snake(startPos,endPos);
 Grid * pGrid = pManager->GetGrid();
 if(pGrid->CheckOverLapping(pSnake))
	{
	 pGrid->PrintErrorMessage("Error: Overlapping ! Try again adding new snake , Click to continue...");
	 delete pSnake;
	 return;
	}
 bool added = pGrid->AddObjectToCell(pSnake);
 if (! added)
	{
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
 }