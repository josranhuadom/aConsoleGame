#pragma once
#include "Character.h"



class CharacterList
{
public:
	CharacterList();

	void AddCharacter();
	void ModifyCharacter();
	void DeleteCharacter();
	void PrintCharacter();

	int DetectCharacterExist();

public:
	friend int InputChecking(int m);

private:
	Character* head;
	Character* tail;
};



class CharacterList 
{
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

    void Add(Character* Ch) {
        CharacterNode* Current = _Header;
        while (Current->Next) {
            Current = Current->Next;
        }
        Current->Next = new CharacterNode;
        Current->Next->Next = NULL;
        Current->Next->Data = Ch;
    }

    void Remove(Character* Ch) {
        CharacterNode* Current = _Header;
        while (Current->Next) {
            if (Current->Next->Data == Ch) {
                CharacterNode* Next = Current->Next->Next;
                delete Current->Next;
                Current->Next = Next;
            }
            Current = Current->Next;
        }
    }

    CharacterNode* Get(unsigned index) {
        unsigned i = 0;
        CharacterNode* Current = _Header->Next;
        while (Current) {
            if (index == i) return Current;
            Current = Current->Next;
            i += 1;
        }
        return NULL;
    }

    unsigned Size() {
        unsigned i = 0;
        CharacterNode* Current = _Header->Next;
        while (Current) {
            Current = Current->Next;
            i += 1;
        }
        return i;
    }
};