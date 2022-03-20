#include "CutCardAction.h"
#include "Card.h"

CutCardAction::CutCardAction(ApplicationManager *pApp)  : Action(pApp)
{
}


CutCardAction::~CutCardAction(void)
{
}

void CutCardAction::ReadActionParameters() 
{	
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("choose the card you want to cut");
	cut_cell=pIn->GetCellClicked();
	pOut->ClearStatusBar();
}


// Execute the action
void CutCardAction::Execute() 
{ 
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();
	if(!cut_cell.IsValidCell())
	{
		pGrid->PrintErrorMessage("You didn't choose a cell in the grid , Click to continue....");
		return ;
	}     
	
	if(!(dynamic_cast<Card*>(pGrid->getGameObject(cut_cell))))
	{
		pGrid->PrintErrorMessage("There is no card in the cell you chose , Click to continue....");
		return ;
	}
	pGrid->SetClipboard((Card*)pGrid->getGameObject(cut_cell));
	pGrid->RemoveObjectFromCell(cut_cell);
}