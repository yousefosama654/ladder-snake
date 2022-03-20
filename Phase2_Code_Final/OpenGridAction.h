#pragma once
#include "Action.h"
#include "fstream"
class OpenGridAction : public Action
{ifstream input_file;
public:
	OpenGridAction(ApplicationManager *pApp);
	~OpenGridAction(void);
	virtual void ReadActionParameters() ; 

	virtual void Execute() ; 
};

