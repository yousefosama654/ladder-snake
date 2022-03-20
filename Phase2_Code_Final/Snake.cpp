#include "Snake.h"
#include <fstream>
#include <iostream>
#include "Ladder.h"
#include "UI_Info.h"
int Snake::num_of_snakes=0;
Snake::Snake()
{
	num_of_snakes++;
}
Snake::Snake(const CellPosition & startCellPos, const CellPosition & endCellPos): GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	num_of_snakes++;
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}
void Snake::Apply(Grid* pGrid, Player* pPlayer) 
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	// 1- Print a message "You have reached a snake. Click to continue ..." and wait mouse click

	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

    pGrid->UpdatePlayerCell(pPlayer,endCellPos);

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}
Snake::~Snake()
{
	num_of_snakes--;
}
int Snake::getnumofsnakes()
{
	return num_of_snakes;
}
void Snake::Save(ofstream &OutFile,object_type type)
{
	if(type==snake)
	{  
		if(OutFile.is_open())
		{
			OutFile<< position.GetCellNum()<<" "<<endCellPos.GetCellNum()<<endl;
		}
	

	}
	else
	return;

}    
GameObject* Snake::Load(ifstream &Infile,object_type type) 
{
	int start_cell,end_cell;
	Infile>>start_cell>>end_cell;
	position=CellPosition(start_cell);
	endCellPos=CellPosition(end_cell);
	return this;
}
 bool Snake::CheckOverLapping(GameObject * pObject)
 {
 
	Snake *pSnake=dynamic_cast<Snake *>(pObject);
 if(pSnake)
 {
	 if(pSnake->position.VCell() >=position.VCell()&& pSnake->position.VCell() <=endCellPos.VCell())
	 {
		 return true;
	 }
	 if(pSnake->endCellPos.VCell()>=position.VCell()&& pSnake->endCellPos.VCell() <=endCellPos.VCell())
	 {
		 return true;
	 }
	 if(pSnake->position.VCell() <=position.VCell()&& pSnake->endCellPos.VCell() >=endCellPos.VCell())
	 {
		 return true;
	 }
 }
 
 Ladder *pLadder=dynamic_cast<Ladder *>(pObject);
 if(pLadder)
 {
	 if(pLadder->GetEndPosition().VCell()==position.VCell())
	 {
		 return true ;
	 }
	 if (pLadder->GetPosition().VCell() == endCellPos.VCell())
	 {
		 return true;
	 }
 }
 return false;
 
 }
 
 
 