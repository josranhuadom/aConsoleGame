#pragma once
#include"Character.h"
class CharacterList
{
public:
	CharacterList()
	{
		head->NextCharacter(tail);
	};

	
	void AddCharacter();
	void ModifyCharacter();
	void DeleteCharacter();
	int InputChecking(int);
	void PrintCharacter();

private:
	Character* head = new Character;
	Character* tail = new Character;

};

