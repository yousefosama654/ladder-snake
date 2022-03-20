#include "CardTwo.h"
#include"Ladder.h"
#include "fstream"

CardTwo::CardTwo()
{
	cardNumber = 2; // default constructor used in OpenGridAction
}

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
		cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	//no paramters here
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	//Moves the player forward to the start of the next ladder in the grid.
		// If no ladders ahead, do nothing
	Card::Apply(pGrid, pPlayer);
	CellPosition PlayerPosition = pPlayer->GetCell()->GetCellPosition();
	Ladder* NextLadder = pGrid->GetNextLadder(PlayerPosition);
	if (NextLadder)
	{
		CellPosition NextLadderPosition = NextLadder->GetPosition();
		pGrid->UpdatePlayerCell(pPlayer, NextLadderPosition);
		NextLadder->Apply(pGrid, pPlayer);
	}
	else
	{
		pGrid->GetOutput()->PrintMessage("There are no ladders ahead, Click to Continue ...");
		pGrid->GetInput()->GetCellClicked();
	}
	pGrid->GetOutput()->ClearStatusBar();
}
	

		

CardTwo::~CardTwo()
{
}
//CardTwo Save 
void CardTwo::Save(ofstream& OutFile, object_type type)
{
	if(type==cards)
	{ 
		OutFile<<cardNumber<<" "<<position.GetCellNum()<<endl;
	}
	else return;
}

//CardTwo Load
GameObject* CardTwo::Load(ifstream& Infile, object_type type)
{
	int cell_num;
	Infile>>cell_num;
	position=CellPosition(cell_num);
	return this;
}