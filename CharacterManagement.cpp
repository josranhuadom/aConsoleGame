#include "CharacterManagement.h"
#include "CharacterList.h"
#include "Character.h"

//ͬ����default ֮���ܷ����������ѡ����Ҫע��
void CharacterManagement::MainInterface(CharacterList theList){

    cout << "��ӭ������ɫ����ϵͳ" << endl;

    do {
        cout << "1. ���ӽ�ɫ\n" << "2. �༭��ɫ\n" << "3. ɾ����ɫ\n" << "4. ��ɫһ��" << endl;
    
        int selection = NULL;
        do{
            cout << "�������Ӧ�����ѡ�����: ";
            cin >> selection;
        } while (InputChecking(selection));

    
        switch (selection)
        {
        case 1: //���ӽ�ɫ
        {
            string name; int atk; int def; int id;

            do {
                cout << "������ʿ����ū����\n1.��ʿ\t2.ū����"; cin >> id;
            } while (InputChecking(id));

            cout << "�������ɫ���֣�"; cin >> name;

            do {
                cout << "�������ɫ��������"; cin >> atk;
            } while (InputChecking(atk));

            do {
                cout << "�������ɫ��������"; cin >> def;
            } while (InputChecking(def));
            cout << endl;

            if (id == 1) {
                Hero* Ch = new Hero; Ch->SetName(name); Ch->SetAtk(atk); Ch->SetDef(def);
                theList.Add(Ch);
                break;
            }
            else if (id == 2) {
                Slave *Ch = new Slave; Ch->SetName(name); Ch->SetAtk(atk); Ch->SetDef(def);
                theList.Add(Ch);
                break;
            }
            else {
                cout << "������󣬷������˵���" << endl;
                return;
            }
        }
        case 2: //�༭��ɫ
        {
            if (theList.DetectExist())
                break;
            else
            {
                cout << "\n���������н�ɫ��\n";
                theList.Print();
                cout << endl;

                int No;
                do {
                    cout << "��������Ҫ�Ķ��Ľ�ɫ��ţ�"; cin >> No;
                } while (InputChecking(No));

                theList.Modify(No);
            }

            cout << endl;
            break;

        }
        case 3: //ɾ����ɫ
        {
            if (theList.DetectExist())
                break;
            else
            {
                cout << "\n���������н�ɫ��\n";
                theList.Print();
                cout << endl;

                int No;
                do {
                    cout << "��������Ҫɾ���Ľ�ɫ��ţ�"; cin >> No;
                } while (InputChecking(No));

                theList.Remove(No);
            }
            break;
        }
        case 4:
            if (theList.DetectExist())
                break;
            else 
                theList.Print();

            break;
        default:
            cout << "�������룬����������\n" << endl;
        }
    } while (true);
}


