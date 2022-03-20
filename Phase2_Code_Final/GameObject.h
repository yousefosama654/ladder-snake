#pragma once

#include "Grid.h"
#include "objectType.h"
// Base Class for All Game Objects ( ladders, snakes and cards )
class GameObject
{

protected:

	CellPosition position; // The current cell position of the GameObject
	
public:

	GameObject();
	GameObject(const CellPosition & pos); // Constructor for initializing data members
	
	CellPosition GetPosition() const;     // A Getter for position
	void setPosition(CellPosition );
	// ============ Virtual Functions ============

	virtual void Draw(Output* pOut) const = 0;	 // Draws the game object in the window in his position cell 
											     // (drawing depends on GameObject Type, so virtual)

	virtual void Apply(Grid* pGrid, Player* pPlayer) = 0;  // Applys the effect of the GameObject on the passed Player
	                                                       // (The effect depends on the GameObject type, so virtual)
	                                                       // For example, applying a ladder is by moving player up, and so on

	// The following functions are examples of what should be supported by the GameObject class
	// They should be overridden by each inherited class

	// Decide the parameters that you should pass to each function	
	virtual bool CheckOverLapping(GameObject * pObject)=0;
	virtual void Save(ofstream &OutFile,object_type Type) = 0 ;	// Saves the GameObject parameters to the file
	virtual GameObject * Load(ifstream &Infile,object_type Type) = 0;	// Loads and Reads the GameObject parameters from the file

	virtual ~GameObject(); // Virtual destructor
};

