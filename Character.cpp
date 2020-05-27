#include "Character.h"

//一系列传private值用的函数
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

//一系列改动private值的函数
void Character::NewName(string name)
{
	m_name = name;
}
void Character::NewAtk(int atk)
{
	m_atk = atk;
}
void Character::NewDef(int def)
{
	m_def = def;
}
void Character::NextCharacter(Character* data)
{
	this->next = data;
}
