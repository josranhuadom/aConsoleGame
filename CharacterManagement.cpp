#include "CharacterManagement.h"
#include "CharacterList.h"
#include "Character.h"

//同样，default 之后能否重新让玩家选择？需要注意
void CharacterManagement::MainInterface(CharacterList theList){

    cout << "欢迎来到角色管理系统" << endl;

    do {
        cout << "1. 增加角色\n" << "2. 编辑角色\n" << "3. 删除角色\n" << "4. 角色一览" << endl;
    
        int selection = NULL;
        do{
            cout << "请输入对应编号以选择操作: ";
            cin >> selection;
        } while (InputChecking(selection));

    
        switch (selection)
        {
        case 1: //增加角色
        {
            string name; int atk; int def; int id;

            do {
                cout << "创建勇士还是奴隶？\n1.勇士\t2.奴隶："; cin >> id;
            } while (InputChecking(id));

            cout << "请输入角色名字："; cin >> name;

            do {
                cout << "请输入角色攻击力："; cin >> atk;
            } while (InputChecking(atk));

            do {
                cout << "请输入角色防御力："; cin >> def;
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
                cout << "输入错误，返回主菜单。" << endl;
                return;
            }
        }
        case 2: //编辑角色
        {
            if (theList.DetectExist())
                break;
            else
            {
                cout << "\n以下是所有角色：\n";
                theList.Print();
                cout << endl;

                int No;
                do {
                    cout << "请输入想要改动的角色编号："; cin >> No;
                } while (InputChecking(No));

                theList.Modify(No);
            }

            cout << endl;
            break;

        }
        case 3: //删除角色
        {
            if (theList.DetectExist())
                break;
            else
            {
                cout << "\n以下是所有角色：\n";
                theList.Print();
                cout << endl;

                int No;
                do {
                    cout << "请输入想要删除的角色编号："; cin >> No;
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
            cout << "错误输入，请重新输入\n" << endl;
        }
    } while (true);
}


