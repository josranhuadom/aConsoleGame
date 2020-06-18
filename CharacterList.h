#pragma once
#include "Character.h"
class CharacterList
{
public:
	CharacterList();

	void AddCharacter();
	void ModifyCharacter();
	void DeleteCharacter();
	void PrintCharacter();

	int DetectCharacterExist();

public:
	friend int InputChecking(int m);

private:
	Character* head;
	Character* tail;
};

