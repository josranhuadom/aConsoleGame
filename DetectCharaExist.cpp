#include "CharacterStruct.h"

int detectCharaExist()
{
    if (!head || !head->next)
    {
        cout << "没有任何角色。\n";
        cout << endl;
        return 1;
    }
    else return 0;
}