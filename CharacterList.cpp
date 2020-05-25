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
        cout << "输入错误，请重新输入\n" << endl;
        return 1;
    }
}

void CharacterList::PrintCharacter()
{
    int No = 1;
    Character* tempPtr = head->PassNextData;
    while (tempPtr)
    {
        cout << No << "："
            << "名字：" << tempPtr->PassName << "\n"
            << "   攻击力：" << tempPtr->PassAtk << "\n"
            << "   防御力：" << tempPtr->PassDef << "\n" << endl;

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

    cout << "请输入角色名称：";
    cin >> NAME;

    do
    {
        cout << "请自定义该角色的攻击力：";
        cin >> ATK;
        i = InputChecking(ATK);
    } while (i);

    do
    {
        cout << "请自定义该角色的防御力：";
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
        //这个while循环与deleteChara.cpp 有关，用来判定q指针是不是在链表最后，以确保能够正常添加新角色
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

    cout << "目前有以下角色：\n";
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
        cout << "请输入想要删除的角色编号：";
        cin >> No;
        i = InputChecking(No);
    } while (i);

    Chara* ptr = head->next,
        * q = head;

    //查找角色并移动指针
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
            cout << "不存在该角色，退出至主界面\n" << endl;
            return;
        }

    }

    q->next = ptr->next;
    delete ptr;
    cout << "已删除\n" << endl;

    cout << "以下是剩余的角色：\n";
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
        cout << "\n以下是所有角色：\n";
        printChara();

        do
        {
            cout << "请输入想要改动的角色编号：";
            cin >> No;
            i = InputChecking(No);
        } while (i);



        Chara* ptr = head->next;
        //查找角色并移动指针
        for (int i = 1; i <= No; i++)
        {
            if (No == i)
                break;
            else if (ptr)
                ptr = ptr->next;
            else
            {
                delete ptr;
                cout << "不存在该角色，退出至主界面\n" << endl;
                return;
            }
        }

        //更改角色属性
        do
        {
            cout << endl;
            int Element = NULL;

            do
            {
                cout << "请问你想改动的属性：\n"
                    << "1. 名称；2.攻击力；3.防御力\n";
                cin >> Element;
                i = InputChecking(Element);
            } while (i);
            cout << endl;

            switch (Element)
            {
            case 1:
                cout << "请输入新名称：";
                cin >> ptr->name;
                cout << "现在新名称为：";
                cout << ptr->name;
                break;

            case 2:
                do
                {
                    cout << "请输入新攻击力：";
                    cin >> ptr->atk;
                    i = InputChecking(ptr->atk);
                } while (i);
                cout << "现在新攻击力为：";
                cout << ptr->atk;
                break;

            case 3:
                do
                {
                    cout << "请输入新防御力：";
                    cin >> ptr->def;
                    i = InputChecking(ptr->def);
                } while (i);
                cout << "现在新防御力为：";
                cout << ptr->def;
                break;

            default:
                cout << "不存在，请重新输入";
                break;
            }

            cout << endl;
            cout << "\n请问还需要改动该角色的其他属性吗？(Y/N)：";
            cin >> choice;
        } while (choice == 'Y');

        cout << endl;
        cout << "请问还需要改动其他角色的属性吗？(Y/N)：";
        cin >> choice;
    } while (choice == 'Y');

    return;
}