#include "Character.h"

//һϵ�д�privateֵ�õĺ���
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

//һϵ�иĶ�privateֵ�ĺ���
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
