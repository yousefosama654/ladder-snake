#pragma once
#include "Action.h"

class NewGame : public Action
{
	

public:

	NewGame(ApplicationManager* pApp); // A Constructor

	virtual void Execute(); //restart players' positions,wallets, and turn returns to player zero
	virtual void ReadActionParameters(); 
    virtual ~NewGame(); // Virtual Destructor
};


