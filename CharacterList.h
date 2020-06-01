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
	int InputChecking(int);

private:
	Character* head;
	Character* tail;
};

