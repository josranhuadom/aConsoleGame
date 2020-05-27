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

	//一系列传private值用的函数
	string PassName();
	int PassAtk();
	int PassDef();
	Character* PassNextData();

	//一系列改动private值的函数
	void NewName(string);
	void NewAtk(int);
	void NewDef(int);
	void NextCharacter(Character*);
};

