#include "CardFive.h"
#include"CellPosition.h"
#include"Cell.h"
#include"GameObject.h"
#include "fstream"

CardFive::CardFive()
{
	cardNumber = 5; // default constructor used in OpenGridAction
}

CardFive::CardFive(const CellPosition& pos) : Card(pos)
{
	cardNumber = 5;
}

CardFive::~CardFive(void)
{
}

void CardFive::ReadCardParameters(Grid* pGrid)
{
	// no paramters
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);
	int  diceNumber = pPlayer->getjustRolledDiceNum();
	int PlayerCellNumber = pPlayer->GetCell()->GetCellPosition().GetCellNum();
	int NewCellNumber = PlayerCellNumber - diceNumber ;
	CellPosition NewCellPosition(NewCellNumber);
	pGrid->UpdatePlayerCell(pPlayer, NewCellPosition);

	if(pPlayer->GetCell()->GetGameObject())
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);

	pGrid->GetOutput()->PrintMessage("You returned to your previous location, Click to Continue ...");
	pGrid->GetInput()->GetCellClicked();
	pGrid->GetOutput()->ClearStatusBar();
}
//CardFive Save
void CardFive::Save(ofstream& OutFile, object_type type)
{
	if(type==cards)
	{ 
		OutFile<<cardNumber<<" "<<position.GetCellNum()<<endl;
	}
	else return;
}

//CardFive Load
GameObject* CardFive::Load(ifstream& Infile, object_type type)
{
	int cell_num;
	Infile>>cell_num;
	position=CellPosition(cell_num);
	return this;
}
