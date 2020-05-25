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

	//一系列传private值用的函数
	string PassName();
	int PassAtk();
	int PassDef();
	Character* PassNextData();

	//把*next指向下一个角色数据
	void NextCharacter(Character* data);
};

