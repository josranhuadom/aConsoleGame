#pragma once
#include<iostream>
using namespace std;
class Character
{
private:
	string m_name;
	int m_atk;
	int m_def;
	struct Character* next = NULL;

public:
	Character();
	Character(string name, int atk, int def) : m_name(name), m_atk(atk), m_def(def) {}

	//һϵ�д�privateֵ�õĺ���
	string PassName();
	int PassAtk();
	int PassDef();
	Character* PassNextData();

	//��*nextָ����һ����ɫ����
	void NextCharacter(Character* data);
};

