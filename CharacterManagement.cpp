#include "CharacterManagement.h"
#include "CharacterList.h"
#include "Character.h"


void CharacterManagement::MainInterface(CharacterList theList)
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
        theList.AddCharacter();
        break;
    case 2:
        if (theList.DetectCharacterExist())
            break;
        theList.ModifyCharacter();
        break;
    case 3:
        if (theList.DetectCharacterExist())
            break;
        theList.DeleteCharacter();
        break;
    default:
        cout << "�������룬����������\n" << endl;
        break;
    }
}


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


