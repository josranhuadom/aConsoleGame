#include<string>
#include <iostream>

using namespace std;

#ifndef CHARACTERSTRUCT_H
#define CHARACTERSTRUCT_H

typedef struct Character
{
    string name;
    int atk = NULL;
    int def = NULL;
    struct Character *next = NULL;
}Chara;

extern Chara* head;

void addChara();
void modiChara();
void deleteChara();
void printChara();

#endif

