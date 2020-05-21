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
	Character(string name, int atk, int def) : m_name(name), m_atk(atk), m_def(def) {};

};

