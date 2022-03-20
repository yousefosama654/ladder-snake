#include "DeleteGameObject.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"


DeleteGameObject::DeleteGameObject(ApplicationManager *pApp) : Action(pApp)
{
}


DeleteGameObject::~DeleteGameObject(void)
{
}
void DeleteGameObject::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Choose the game object you want to delete");
	object_position=pIn->GetCellClicked();

	pOut->ClearStatusBar();
}

void DeleteGameObject::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if(!object_position.IsValidCell())
	{
		pOut->PrintMessage("You didn't choose a cell in the grid, Click to Continue ... ");
		pIn->GetCellClicked();
		return ;
	}
	GameObject * game_object=   pGrid->getGameObject(object_position);
	if(pGrid->GetClipboard()==(Card *)game_object&&game_object)
	{
		pGrid->SetClipboard(nullptr);
	}
	if(game_object)
	{ 
		if(dynamic_cast<CardNine*>(game_object)) 
		{if(CardNine::getcounter()==1)
		CardNine::Reset();
		}
		if(dynamic_cast<CardTen*>(game_object))
		{if(CardTen::getcounter()==1)
		CardTen::Reset();
		}
		if(dynamic_cast<CardEleven*>(game_object))
		{if(CardEleven::getcounter()==1)
		CardEleven::Reset();
		}

		delete pGrid->RemoveObjectFromCell(object_position);
		pOut->PrintMessage("The object is deleted, Click to Continue ...");
		pIn->GetCellClicked();
	}
	else 
	{
		pOut->PrintMessage("There is no object in the chosen cell, Click to Continue ...");
		pIn->GetCellClicked();
	}
	pOut->ClearStatusBar();
}