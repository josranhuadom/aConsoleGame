#include "CharacterStruct.h"

int detectCharaExist()
{
    if (!head || !head->next)
    {
        cout << "û���κν�ɫ��\n";
        cout << endl;
        return 1;
    }
    else return 0;
}