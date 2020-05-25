#include "Character.h"

string Character::PassName()
{
	return this->m_name;
}

int Character::PassAtk()
{
	return this->m_atk;
}

int Character::PassDef()
{
	return this->m_def;
}

Character* Character::PassNextData()
{
	return this->next;
}

void Character::NextCharacter(Character* data)
{
	this->next = data;
}
