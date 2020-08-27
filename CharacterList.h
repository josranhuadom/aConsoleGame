#pragma once
#include "Character.h"

//下划线是针对指针加吗？

typedef struct _tagCharacterNode{
    struct _tagCharacterNode* Next;
    Character* Data;
} CharacterNode;

class CharacterList {
private:
    CharacterNode* _Header;
public:
    CharacterList() {
        _Header = new CharacterNode;
        _Header->Next = NULL;
    }

    ~CharacterList() {
        CharacterNode* Current = _Header;
        while (Current) {
            CharacterNode* Next = Current->Next;
            delete Current;
            Current = Next;
        }
    }

    void Print();
    void Add(Character*);
    void Remove(int);
    CharacterNode* Get(unsigned);
    unsigned Size();
    void Modify(int);
    int DetectExist();
}; 