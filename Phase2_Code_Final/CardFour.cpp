#include "CardFour.h"
#include"Player.h"
#include"Grid.h"
#include "fstream"
CardFour::CardFour()
{
	cardNumber = 4; // default constructor used in OpenGridAction
}
CardFour::CardFour(const CellPosition& pos):Card(pos)
{
	cardNumber = 4;
}

void CardFour::ReadCardParameters(Grid* pGrid)
{
	//no paramters here
}
void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	pPlayer->SetPrisonCount(1); //preventing the player from playing the next turn 
	pGrid->GetOutput()->PrintMessage("You won't play next turn, Click to Continue ...");
	pGrid->GetInput()->GetCellClicked();
	pGrid->GetOutput()->ClearStatusBar();
}
CardFour::~CardFour()
{
}

//CardFour Save
void CardFour::Save(ofstream& OutFile, object_type type)
{
	if(type==cards)
	{ 
		OutFile<<cardNumber<<" "<<position.GetCellNum()<<endl;
	}
	else return;
}

//CardFour Load
GameObject* CardFour::Load(ifstream& Infile, object_type type)
{
    int cell_num;
	Infile>>cell_num;
	position=CellPosition(cell_num);
	return this;
}
