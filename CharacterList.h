#pragma once
#include"Character.h"
class CharacterList
{
public:
	CharacterList() {};

	void AddCharacter();
	void ModifyCharacter();
	void DeleteCharacter();
	int InputChecking(int);
	void PrintCharacter();

private:
	Character* head = new Character;
	Character* tail = new Character;
};

