#pragma once
#include "Character.h"
#include "CharacterList.h"




class CharacterManagement
{
public:
	void MainInterface(CharacterList);

public:
	friend int InputChecking(int m);
};

