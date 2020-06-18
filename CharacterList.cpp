#include "CharacterList.h"
#include "CharacterManagement.h"

CharacterList::CharacterList()
{
    head = new Character;
    tail = new Character;
}

void CharacterList::PrintCharacter()
{
    int No = 1;
    Character* tempPtr = head->PassNextData();
    cout << tail->PassAtk() << endl;
    while (tempPtr)
    {
        cout << No << "��"
            << "���֣�" << tempPtr->PassName() << "\n"
            << "   ��������" << tempPtr->PassAtk() << "\n"
            << "   ��������" << tempPtr->PassDef() << "\n" << endl;

        tempPtr = tempPtr->PassNextData();
        No++;
    }
    cout << tail->PassAtk() << endl;
    return;
}
void CharacterList::AddCharacter()
{
    cout << tail->PassAtk() << endl;
    string NAME;
    int ATK = NULL;
    int DEF = NULL;
    int i = NULL;

    cout << "�������ɫ���ƣ�";
    cin >> NAME;
    cout << tail->PassAtk() << endl;
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
    cout << tail->PassAtk() << endl;

    cout << endl;

    Character *tempPter = new Character(NAME, ATK, DEF);
    cout << tail->PassAtk() << endl;
    //��while������ڼ��tail�Ƿ����б�ĩβ������Ҫ���ǣ����tail��ɾ���ˣ������ܷ��ؽ�tail��
    cout << tail->PassAtk() << endl;
    while (tail->PassNextData())
    {
        tail->NextCharacter(tail->PassNextData());
    }

    if (head->PassNextData() == NULL)
    {
        head->NextCharacter(tempPter);
        tail = tempPter;
    }
    else
    {
        tail->NextCharacter(tempPter);
        tail = tempPter;
    }

    cout << "Ŀǰ�����½�ɫ��\n";
    PrintCharacter();
    return;
}
void CharacterList::DeleteCharacter()
{
    PrintCharacter();

    int No = NULL;
    int i = NULL;
    do
    {
        cout << "��������Ҫɾ���Ľ�ɫ��ţ�";
        cin >> No;
        i = InputChecking(No);
    } while (i);

    Character* tempPtr = head->PassNextData();
    Character* ptrPrevious = head;

    //���ҽ�ɫ���ƶ�ָ��
    for (int i = 1; i <= No; i++)
    {
        if (No == i)
            break;
        else if (tempPtr)
        {
            ptrPrevious = tempPtr;
            tempPtr = tempPtr->PassNextData();
        }
        else
        {
            cout << "�����ڸý�ɫ���˳���������\n" << endl;
            return;
        }

    }

    ptrPrevious->NextCharacter(tempPtr->PassNextData());
    delete tempPtr;
    cout << "��ɾ��\n" << endl;

    cout << "������ʣ��Ľ�ɫ��\n";
    PrintCharacter();

    return;
}
void CharacterList::ModifyCharacter()
{
    int No;
    int i = NULL;

    char choice; //�ñ������ڱ�������Ƿ�����Ķ���ɫ��������/������ɫ��ѡ��
    do
    {
        cout << "\n���������н�ɫ��\n";
        PrintCharacter();

        do
        {
            cout << "��������Ҫ�Ķ��Ľ�ɫ��ţ�";
            cin >> No;
            i = InputChecking(No);
        } while (i);

        Character* tempPtr = head->PassNextData();

        //���ҽ�ɫ���ƶ�ָ��
        for (int i = 1; i <= No; i++)
        {
            if (No == i)
                break;
            else if (tempPtr->PassNextData())
            {
                tempPtr = tempPtr->PassNextData();
                
            }
            else
            {
                delete tempPtr;
                cout << "�����ڸý�ɫ���˳���������\n" << endl;
                return;
            }
        }

        //���Ľ�ɫ����
        do
        {
            cout << endl;
            int Element = NULL;
            int i = NULL;
            do
            {
                cout << "��������Ķ������ԣ�\n"
                    << "1. ���ƣ�2.��������3.������\n";
                cin >> Element;
                i = InputChecking(Element);
            } while (i);
            cout << endl;

            //������ҵ�ѡ�����Ķ���������֮һ
            switch (Element)
            {
                case 1: 
                {
                    string NAME;
                    cout << "�����������ƣ�";
                    cin >> NAME;
                    tempPtr->NewName(NAME);
                    cout << "����������Ϊ��";
                    cout << tempPtr->PassName();
                    break;
                }
                case 2:
                {
                    int ATK;
                    do
                    {
                        cout << "�������¹�������";
                        cin >> ATK;
                        i = InputChecking(ATK);
                    } while (i);

                    tempPtr->NewAtk(ATK);
                    cout << "�����¹�����Ϊ��";
                    cout << tempPtr->PassAtk();
                    break;
                }
                case 3:
                {
                    int DEF;
                    do
                    {
                        cout << "�������¹�������";
                        cin >> DEF;
                        i = InputChecking(DEF);
                    } while (i);

                    tempPtr->NewDef(DEF);
                    cout << "�����¹�����Ϊ��";
                    cout << tempPtr->PassDef();
                    break;
                }
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


int CharacterList::DetectCharacterExist()
{
    if (!head->PassNextData())
    {
        cout << "û���κν�ɫ��\n";
        cout << endl;
        return 1;
    }
    else return 0;
}