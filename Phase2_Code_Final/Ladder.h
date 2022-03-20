#pragma once

#include "GameObject.h"
#include "objectType.h"

class Ladder :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"

	CellPosition endCellPos; // here is the ladder's End Cell Position
	static int num_of_ladders;

public:
	Ladder();
	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member
	static int getnumofladders();
	virtual ~Ladder(); // Virtual destructor
	virtual bool CheckOverLapping(GameObject * pObject);
	virtual void Save(ofstream &OutFile,object_type type) ;	// Saves the GameObject parameters to the file
	virtual GameObject* Load(ifstream &Infile,object_type type) ;	// Loads and Reads the GameObject parameters from the file

};

