#include "CardSeven.h"
#include"Cell.h"
#include "fstream"

CardSeven::CardSeven()
{
	cardNumber = 7; // default constructor used in OpenGridAction
}

CardSeven::CardSeven(const CellPosition& pos) : Card(pos)
{
	cardNumber = 7;
}

CardSeven::~CardSeven(void)
{

}
void CardSeven::ReadCardParameters(Grid* pGrid)
{
	//nothing to be read
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{

	//Restarts the game for the first player whose cell is after the current player in the grid.
	//• Restarting the game for a player makes him go to cell number 1.

	Card::Apply(pGrid, pPlayer);
	CellPosition NewCell(1);
	if (pGrid->GetNextPlayer(  pPlayer->GetCell()->GetCellPosition() , pPlayer ))
	{
		Player* playerptr = pGrid->GetNextPlayer(pPlayer->GetCell()->GetCellPosition(), pPlayer);
			pGrid->UpdatePlayerCell(playerptr, NewCell);
	}
	//it also resets player in the same grid cell WHICH IS WRONGGG
	// using NextPlayer function to search for the next player 
}
void CardSeven::Save(ofstream& OutFile, object_type type)
{
	if(type==cards)
	{ 
		OutFile<<cardNumber<<" "<<position.GetCellNum()<<endl;
	}
	else return;
}

GameObject* CardSeven::Load(ifstream& Infile, object_type type)
{
	int cell_num;
	Infile>>cell_num;
	position=CellPosition(cell_num);
	return this;
}



