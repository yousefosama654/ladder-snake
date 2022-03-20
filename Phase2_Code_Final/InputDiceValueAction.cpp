#include "InputDiceValueAction.h"
#include "Input.h"
#include "Output.h"
#include "Player.h"


InputDiceValueAction::InputDiceValueAction(ApplicationManager *pApp) : Action(pApp)
{
}


InputDiceValueAction::~InputDiceValueAction(void)
{
}
void InputDiceValueAction::ReadActionParameters() {

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	bool valid_dice_value=false;
	int dicevalue;
	//pOut->PrintMessage("Enter the dice value (1-6) :");
	//dicevalue = pIn->GetInteger(pOut);
	//We  can remove this validation in our testing to make it easier
	do 
	{
		pOut->PrintMessage("Enter the dice value (1-6) :");
		dicevalue = pIn->GetInteger(pOut);
		if (dicevalue >= 1 && dicevalue <= 6)
			valid_dice_value = true;
		else
		{
			pOut->PrintMessage("Invalid dice value,Click to try again...");
			pIn->GetCellClicked();
		}
	} while (!valid_dice_value);
	Dice_Value=dicevalue;
}
void InputDiceValueAction::Execute(){
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Player * pPlayer=pGrid->GetCurrentPlayer();
	bool endgame = pGrid->GetEndGame();
	if (endgame == true)
	{
		pGrid->GetOutput()->PrintMessage("The game has ended, Click on NewGame to start again ...");
		pGrid->GetInput()->GetCellClicked();
		pGrid->GetOutput()->ClearStatusBar();
		return;
	}
	pPlayer->Move(pGrid,Dice_Value);
	pGrid->AdvanceCurrentPlayer();

}