#pragma once
#include "Action.h"
#include <fstream>
class SaveGridAction: public Action
{ofstream outfile;
public:
	SaveGridAction(ApplicationManager *pApp);
	~SaveGridAction(void);
	virtual void ReadActionParameters();
	
	virtual void Execute();
};

