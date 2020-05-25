#include "CharacterList.h"

int CharacterList::InputChecking(int m)
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

void CharacterList::PrintCharacter()
{
    int No = 1;
    Character* tempPtr = head->PassNextData;
    while (tempPtr)
    {
        cout << No << "��"
            << "���֣�" << tempPtr->PassName << "\n"
            << "   ��������" << tempPtr->PassAtk << "\n"
            << "   ��������" << tempPtr->PassDef << "\n" << endl;

        tempPtr = tempPtr->PassNextData;
        No++;
    }

    return;
}

void CharacterList::AddCharacter()
{
    string NAME;
    int ATK = NULL;
    int DEF = NULL;
    int i = NULL;

    cout << "�������ɫ���ƣ�";
    cin >> NAME;

    do
    {
        cout << "���Զ���ý�ɫ�Ĺ�������";
        cin >> ATK;
        i = InputChecking(ATK);
    } while (i);

    do
    {
        cout << "���Զ���ý�ɫ�ķ�������";
        cin >> DEF;
        i = InputChecking(DEF);
    } while (i);

    cout << endl;

    Chara* ptr = new Chara;
    Chara* q = head;

    if (head == NULL)
    {
        head = new Chara;
        ptr->name = NAME;
        ptr->atk = ATK;
        ptr->def = DEF;

        head->next = ptr;
        q = ptr;
    }
    else
    {
        //���whileѭ����deleteChara.cpp �йأ������ж�qָ���ǲ��������������ȷ���ܹ���������½�ɫ
        while (q->next)
        {
            q = q->next;
        }

        ptr->name = NAME;
        ptr->atk = ATK;
        ptr->def = DEF;
        ptr->next = NULL;

        q->next = ptr;
        q = ptr;
    }

    cout << "Ŀǰ�����½�ɫ��\n";
    printChara();
    return;
}

void CharacterList::DeleteCharacter()
{
    printChara();

    int No = NULL;

    int i = NULL;
    do
    {
        cout << "��������Ҫɾ���Ľ�ɫ��ţ�";
        cin >> No;
        i = InputChecking(No);
    } while (i);

    Chara* ptr = head->next,
        * q = head;

    //���ҽ�ɫ���ƶ�ָ��
    for (int i = 1; i <= No; i++)
    {
        if (No == i)
            break;
        else if (ptr)
        {
            q = ptr;
            ptr = ptr->next;
        }
        else
        {
            cout << "�����ڸý�ɫ���˳���������\n" << endl;
            return;
        }

    }

    q->next = ptr->next;
    delete ptr;
    cout << "��ɾ��\n" << endl;

    cout << "������ʣ��Ľ�ɫ��\n";
    printChara();

    return;
}

void CharacterList::ModifyCharacter()
{
    extern Chara* head;
    char choice;
    int No;

    int i = NULL;

    do
    {
        cout << "\n���������н�ɫ��\n";
        printChara();

        do
        {
            cout << "��������Ҫ�Ķ��Ľ�ɫ��ţ�";
            cin >> No;
            i = InputChecking(No);
        } while (i);



        Chara* ptr = head->next;
        //���ҽ�ɫ���ƶ�ָ��
        for (int i = 1; i <= No; i++)
        {
            if (No == i)
                break;
            else if (ptr)
                ptr = ptr->next;
            else
            {
                delete ptr;
                cout << "�����ڸý�ɫ���˳���������\n" << endl;
                return;
            }
        }

        //���Ľ�ɫ����
        do
        {
            cout << endl;
            int Element = NULL;

            do
            {
                cout << "��������Ķ������ԣ�\n"
                    << "1. ���ƣ�2.��������3.������\n";
                cin >> Element;
                i = InputChecking(Element);
            } while (i);
            cout << endl;

            switch (Element)
            {
            case 1:
                cout << "�����������ƣ�";
                cin >> ptr->name;
                cout << "����������Ϊ��";
                cout << ptr->name;
                break;

            case 2:
                do
                {
                    cout << "�������¹�������";
                    cin >> ptr->atk;
                    i = InputChecking(ptr->atk);
                } while (i);
                cout << "�����¹�����Ϊ��";
                cout << ptr->atk;
                break;

            case 3:
                do
                {
                    cout << "�������·�������";
                    cin >> ptr->def;
                    i = InputChecking(ptr->def);
                } while (i);
                cout << "�����·�����Ϊ��";
                cout << ptr->def;
                break;

            default:
                cout << "�����ڣ�����������";
                break;
            }

            cout << endl;
            cout << "\n���ʻ���Ҫ�Ķ��ý�ɫ������������(Y/N)��";
            cin >> choice;
        } while (choice == 'Y');

        cout << endl;
        cout << "���ʻ���Ҫ�Ķ�������ɫ��������(Y/N)��";
        cin >> choice;
    } while (choice == 'Y');

    return;
}