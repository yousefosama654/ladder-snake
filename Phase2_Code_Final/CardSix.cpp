#include "CardSix.h"
#include "fstream"

CardSix::CardSix()
{
	cardNumber = 6; // default constructor used in OpenGridAction
}

CardSix::CardSix(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)
}

CellPosition CardSix::GetToMoveTo()
{
	return to_move_to;
}

void CardSix::SetToMoveTo(CellPosition goingto)
{
	to_move_to = goingto;
}

CardSix::~CardSix(void)
{

}
 void CardSix:: ReadCardParameters(Grid* pGrid)
 {  
	do
	{
		pGrid->GetOutput()->PrintMessage("New CardSix: Click on the to move to cell");
		to_move_to = pGrid->GetInput() ->GetCellClicked();
	}
	while(!(to_move_to.IsValidCell()));

	pGrid->GetOutput()->ClearStatusBar();
 }

 void CardSix::Apply(Grid* pGrid, Player* pPlayer)
 {
	 Card::Apply(pGrid, pPlayer);
	 pGrid->UpdatePlayerCell(pPlayer, to_move_to);
 }

 //CardSix Save
 void CardSix::Save(ofstream& OutFile, object_type type)
{
	 if(type==cards)
	{ 
		OutFile<<cardNumber<<" "<<position.GetCellNum()<<" "<<to_move_to.GetCellNum()<<endl;
	}
	else return;
}

 //CardSix Load
GameObject* CardSix::Load(ifstream& Infile, object_type type)
{
	int cell_num,to_move_cell_num;
	Infile>>cell_num>>to_move_cell_num;
	position=CellPosition(cell_num);
	to_move_to=CellPosition(to_move_cell_num);
	return this;
}