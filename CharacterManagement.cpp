#include "CharacterManagement.h"

void CharacterManagement::AddCharacter()
{

}

void CharacterManagement::DeleteCharacter()
{

}

void CharacterManagement::ModifyCharacter()
{

}

void CharacterManagement::MainInterface()
{
    cout << "��ӭ������ɫ����ϵͳ" << endl;

    cout << "1. ���ӽ�ɫ\n"
        << "2. �༭��ɫ\n"
        << "3. ɾ����ɫ\n"
        << endl;

    int i = NULL;
    do
    {
        cout << "�������Ӧ�����ѡ�����" << endl;
        cin >> selection;
        i = InputChecking(selection);
    } while (i);

    switch (selection)
    {
    case 1:
        addChara();
        break;
    case 2:
        if (detectCharaExist())
            break;
        modiChara();
        break;
    case 3:
        if (detectCharaExist())
            break;
        deleteChara();
        break;
    default:
        cout << "�������룬����������\n" << endl;
        break;
    }
}
