#include "CopyCardAction.h"
#include "CardOne.h"


CopyCardAction::CopyCardAction(ApplicationManager *pApp) : Action(pApp)
{
}


CopyCardAction::~CopyCardAction(void)
{
}
void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on the Source Cell");
	source_cell=pIn->GetCellClicked();
}

void CopyCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
  	ReadActionParameters();

	if(!source_cell.IsValidCell()) 
	{
		pGrid->PrintErrorMessage("You didn't choose a cell in the grid , Click to continue ...");

		return;
	}
	if(pGrid->GetClipboard()&&!pGrid->getGameObject(pGrid->GetClipboard()->GetPosition())) //this if statment will happen if the user cut a card then he copied another card
	{
		pGrid->AddObjectToCell(pGrid->GetClipboard());
	}
	if(dynamic_cast<Card *>(pGrid->getGameObject(source_cell)))
	{
		pOut->PrintMessage("The card is copied, Click to Continue ...");
		pIn->GetCellClicked();
	}
	else 
	{ 
		pOut->PrintMessage("You didn't choose a card, Click to Continue ...");
		pIn->GetCellClicked();
	}


	if(dynamic_cast<Card *>(pGrid->getGameObject(source_cell)))
	{
		GameObject * temp =pGrid->getGameObject(source_cell);
		pGrid->SetClipboard((Card *)temp);
	}
	pOut->ClearStatusBar();
}