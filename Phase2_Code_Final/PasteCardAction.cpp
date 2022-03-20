#include "PasteCardAction.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
PasteCardAction::PasteCardAction(ApplicationManager *pApp) : Action(pApp)
{
}

PasteCardAction::~PasteCardAction(void)
{
}

void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on the Destination Cell ...");
	paste_cell=pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void PasteCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if(paste_cell.GetCellNum()==99||paste_cell.GetCellNum()==1)
	{
		pGrid->PrintErrorMessage("You connot add card in cell 99 or cell 1 , Click to continue....");
		return;
	}
	if(pGrid->GetClipboard()==NULL)
	{
		pGrid->PrintErrorMessage("No card is copied or cut, Click to continue....");
		return;
	}
	Card * copied_card=pGrid->GetClipboard(); //the card that the clipboard refeer to.
	Card * pCard;
	if(!paste_cell.IsValidCell())
	{
		pGrid->PrintErrorMessage("You didn't choose a cell in the grid , Click to continue....");
		return;
	}
	if(!pGrid->getGameObject(copied_card->GetPosition())) //it allows me to paste one time only after i cut the card .
	{
		copied_card->setPosition(paste_cell);
		pGrid->AddObjectToCell(copied_card);
		pGrid->SetClipboard(nullptr);
		return ;
	}
	
	switch (copied_card->GetCardNumber())
	{
	case 1:
	{   int wallet_value;
		wallet_value = ((CardOne*)copied_card)->getwalletamount();
		pCard = new CardOne(paste_cell, wallet_value);
		break;
	}
	case 2:
	{
		pCard = new CardTwo(paste_cell);
		break;
	}
	case 3:
	{
		pCard = new CardThree(paste_cell);
		break;
	}
	case 4:
	{
		pCard = new CardFour(paste_cell);
		break;
	}
	case 5:
	{
		pCard = new CardFive(paste_cell);
		break;
	}
	case 6:
	{
		CellPosition to_move_to = ((CardSix*)pGrid->GetClipboard())->GetToMoveTo();
		pCard = new CardSix(paste_cell);
		((CardSix*)pCard)->SetToMoveTo(to_move_to);
		break;
	}
	case 7:
	{
		pCard = new CardSeven(paste_cell);
		break;
	}
	case 8:
	{
		int amount_of_coins = ((CardEight*)pGrid->GetClipboard())->GetAmountOfCoins();
		pCard = new CardEight(paste_cell);
		((CardEight*)pCard)->SetAmountOfCoins(amount_of_coins);
		break;
	}
	case 9:
	{
	
		pCard = new CardNine(paste_cell);
		break;
	}
		
		
	case 10:
	{
		
		pCard = new CardTen(paste_cell);
		break;
	}
		
	case 11:
	{
		pCard = new CardEleven(paste_cell);
		break;
	}
	case 12:
	{
		pCard = new CardTwelve(paste_cell);
		break;
	}
	default:
		break;
	}
	
	if(pCard){
	bool added = pGrid->AddObjectToCell(pCard);
	

		if (!added)
		{
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}

	}



}