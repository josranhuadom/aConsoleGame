#pragma once

#include<iostream>
#include<string>
using namespace std;


class Character
{
private:
	string m_name;
	int m_atk = 0;
	int m_def = 0;
	struct Character* next = NULL;

public:
	Character() {};
	Character(string name, int atk, int def) : m_name(name), m_atk(atk), m_def(def) {}

	//һϵ�д�privateֵ�õĺ���
	string PassName();
	int PassAtk();
	int PassDef();
	Character* PassNextData();

	//һϵ�иĶ�privateֵ�ĺ���
	void NewName(string);
	void NewAtk(int);
	void NewDef(int);
	void NextCharacter(Character*);
};

