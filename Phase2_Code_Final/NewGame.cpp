#include "NewGame.h"

#include "Input.h"
#include "Output.h"


NewGame::NewGame(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

NewGame::~NewGame()
{
}
void NewGame::ReadActionParameters()
{
	//No parameters
}

void NewGame::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->SetEndGame(false);
	pGrid->ResetPlayers();
}
