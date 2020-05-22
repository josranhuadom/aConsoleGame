#include "CharacterManagement.h"

int CharacterManagement::InputChecking(int m)
{
    try
    {
        if (cin.fail())
            throw - 1;
        else
            return 0;
    }
    catch (...)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "�����������������\n" << endl;
        return 1;
    }
}


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
    int selection = NULL;
    do
    {
        cout << "�������Ӧ�����ѡ�����" << endl;
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
        cout << "�������룬����������\n" << endl;
        break;
    }
}
