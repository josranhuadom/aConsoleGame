#include "CharacterManagement.h"


void CharacterManagement::MainInterface()
{
    cout << "欢迎来到角色管理系统" << endl;

    cout << "1. 增加角色\n"
        << "2. 编辑角色\n"
        << "3. 删除角色\n"
        << endl;

    int i = NULL;
    int selection = NULL;
    do
    {
        cout << "请输入对应编号以选择操作" << endl;
        cin >> selection;
        i = InputChecking(selection);
    } while (i);

    switch (selection)
    {
    case 1:
        AddCharacter();
        break;
    case 2:
        if (detectCharaExist())
            break;
        ModifyCharacter();
        break;
    case 3:
        if (detectCharaExist())
            break;
        DeleteCharacter();
        break;
    default:
        cout << "错误输入，请重新输入\n" << endl;
        break;
    }
}





