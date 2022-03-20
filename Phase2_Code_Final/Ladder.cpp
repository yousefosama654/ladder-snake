#include "Ladder.h"
#include "CMUgraphicsLib\CMUgraphics.h"
#include "objectType.h"
#include <fstream>
#include <iostream>
#include "Input.h"
#include "Output.h"
#include "Snake.h"
int Ladder::num_of_ladders=0;
Ladder::Ladder()
{
	num_of_ladders++;
}
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	num_of_ladders++;
	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer,endCellPos);

}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}
int  Ladder::getnumofladders()
{
	return num_of_ladders;
}

Ladder::~Ladder()
{
	num_of_ladders--;
}
void Ladder::Save(ofstream &OutFile,object_type type)
{
	if(type==ladder)
	{  
		if(OutFile.is_open())
		{
			OutFile<< position.GetCellNum()<<" "<<endCellPos.GetCellNum()<<endl;
		}
	}
	else
	{
		return;
	}
}    

GameObject* Ladder::Load(ifstream &Infile,object_type type) 
{	
	int start_cell,end_cell;
	Infile>>start_cell>>end_cell;
	position=CellPosition(start_cell);
	endCellPos=CellPosition(end_cell);
	return this;
}	
 bool Ladder::CheckOverLapping(GameObject * pObject)
 {
	 Ladder *pLadder=dynamic_cast<Ladder *>(pObject);
	if(pLadder)
	{
		 if(pLadder->GetPosition().VCell()<=position.VCell()&&pLadder->GetPosition().VCell()>=endCellPos.VCell())
		 {
			 return true;
		 }
		if(pLadder->GetEndPosition().VCell()<=position.VCell()&&pLadder->GetEndPosition().VCell()>=endCellPos.VCell())
		{
			return true;
		}
		if(pLadder->GetPosition().VCell()>=position.VCell()&&pLadder->GetEndPosition().VCell()<=endCellPos.VCell())
		{
			return true;
		}
	}
 
	Snake *pSnake=dynamic_cast<Snake *>(pObject);
	if(pSnake)
	{
		if(pSnake->GetPosition().VCell()==endCellPos.VCell())
		return true ;
		if (pSnake->GetEndPosition().VCell() == position.VCell())
		{
			return true;
		}
	}
	return false;
 
 }