#pragma once

#include "objectType.h"

#include "GameObject.h"


class Snake :	public GameObject // inherited from GameObject
{
	
	CellPosition endCellPos;
	static int num_of_snakes;
public:
	Snake();
	Snake(const CellPosition & startCellPos, const CellPosition & endCellPos); 

	virtual void Draw(Output* pOut) const; 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	CellPosition GetEndPosition() const;
	static int getnumofsnakes();
	virtual ~Snake();
	virtual bool CheckOverLapping(GameObject * pObject);
	void Save(ofstream &OutFile,object_type type) ;	// Saves the GameObject parameters to the file
	GameObject * Load(ifstream &Infile,object_type type) ;
};

