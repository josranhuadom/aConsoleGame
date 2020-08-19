#include "Character.h"

//一系列传private值用的函数
string Character::GetName()
{
	return this->m_name;
}
int Character::GetAtk()
{
	return this->m_atk;
}
int Character::GetDef()
{
	return this->m_def;
}
Character* Character::GetNextCharacter()
{
	return this->next;
}

//一系列改动private值的函数
void Character::SetName(string name)
{
	m_name = name;
}
void Character::SetAtk(int atk)
{
	m_atk = atk;
}
void Character::SetDef(int def)
{
	m_def = def;
}
void Character::SetNextCharacter(Character* data)
{
	this->next = data;
}
