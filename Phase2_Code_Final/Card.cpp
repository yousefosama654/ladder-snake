#include "Card.h"

int Card::num_of_cards=0;
Card::Card()
{
	num_of_cards++;
}
Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{num_of_cards++;
}
void Card::SetCardNumber(int cnum)
{
	cardNumber = cnum; // needs validation
	
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{
	
	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position,cardNumber);

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

Card::~Card()
{
	num_of_cards--;
}

int Card::getnumofcards()
{
	return num_of_cards;
}
void Card::Save(ofstream& OutFile, object_type type)
{
}

GameObject* Card::Load(ifstream& Infile, object_type type)
{
	return nullptr;
}
 bool Card::CheckOverLapping(GameObject * pObject)
 {
   return false; 
 }