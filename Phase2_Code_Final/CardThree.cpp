#include "CardThree.h"
#include"RollDiceAction.h"
#include "fstream"

CardThree::CardThree()
{
	cardNumber = 3; // default constructor used in OpenGridAction
}

CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (3 here)
}

CardThree::~CardThree(void)
{

}

void CardThree::ReadCardParameters(Grid* pGrid)
{
	//no paramters here
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	for (int i = 0; i <3; i++)
	{
		pGrid->AdvanceCurrentPlayer(); //loop to return back to same player
	}
	pGrid->GetOutput()->PrintMessage("Click to Continue, ... , then Roll Dice Again");
	pGrid->GetInput()->GetCellClicked();
	pGrid->GetOutput()->ClearStatusBar();
}

//CardThree Save
void CardThree::Save(ofstream& OutFile, object_type type)
{
	if(type==cards)
	{ 
		OutFile<<cardNumber<<" "<<position.GetCellNum()<<endl;
	}
	else return;
}

//CardThree Load
GameObject* CardThree::Load(ifstream& Infile, object_type type)
{
	int cell_num;
	Infile>>cell_num;
	position=CellPosition(cell_num);
	return this;
}