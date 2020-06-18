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
        cout << No << "："
            << "名字：" << tempPtr->PassName() << "\n"
            << "   攻击力：" << tempPtr->PassAtk() << "\n"
            << "   防御力：" << tempPtr->PassDef() << "\n" << endl;

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

    cout << "请输入角色名称：";
    cin >> NAME;
    cout << tail->PassAtk() << endl;
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
    cout << tail->PassAtk() << endl;

    cout << endl;

    Character *tempPter = new Character(NAME, ATK, DEF);
    cout << tail->PassAtk() << endl;
    //该while语句用于检测tail是否在列表末尾。但是要考虑，如果tail被删除了，这里能否重建tail？
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

    cout << "目前有以下角色：\n";
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
        cout << "请输入想要删除的角色编号：";
        cin >> No;
        i = InputChecking(No);
    } while (i);

    Character* tempPtr = head->PassNextData();
    Character* ptrPrevious = head;

    //查找角色并移动指针
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
            cout << "不存在该角色，退出至主界面\n" << endl;
            return;
        }

    }

    ptrPrevious->NextCharacter(tempPtr->PassNextData());
    delete tempPtr;
    cout << "已删除\n" << endl;

    cout << "以下是剩余的角色：\n";
    PrintCharacter();

    return;
}
void CharacterList::ModifyCharacter()
{
    int No;
    int i = NULL;

    char choice; //该变量用于保存玩家是否继续改动角色其他属性/其他角色的选择
    do
    {
        cout << "\n以下是所有角色：\n";
        PrintCharacter();

        do
        {
            cout << "请输入想要改动的角色编号：";
            cin >> No;
            i = InputChecking(No);
        } while (i);

        Character* tempPtr = head->PassNextData();

        //查找角色并移动指针
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
                cout << "不存在该角色，退出至主界面\n" << endl;
                return;
            }
        }

        //更改角色属性
        do
        {
            cout << endl;
            int Element = NULL;
            int i = NULL;
            do
            {
                cout << "请问你想改动的属性：\n"
                    << "1. 名称；2.攻击力；3.防御力\n";
                cin >> Element;
                i = InputChecking(Element);
            } while (i);
            cout << endl;

            //根据玩家的选择来改动三个属性之一
            switch (Element)
            {
                case 1: 
                {
                    string NAME;
                    cout << "请输入新名称：";
                    cin >> NAME;
                    tempPtr->NewName(NAME);
                    cout << "现在新名称为：";
                    cout << tempPtr->PassName();
                    break;
                }
                case 2:
                {
                    int ATK;
                    do
                    {
                        cout << "请输入新攻击力：";
                        cin >> ATK;
                        i = InputChecking(ATK);
                    } while (i);

                    tempPtr->NewAtk(ATK);
                    cout << "现在新攻击力为：";
                    cout << tempPtr->PassAtk();
                    break;
                }
                case 3:
                {
                    int DEF;
                    do
                    {
                        cout << "请输入新攻击力：";
                        cin >> DEF;
                        i = InputChecking(DEF);
                    } while (i);

                    tempPtr->NewDef(DEF);
                    cout << "现在新攻击力为：";
                    cout << tempPtr->PassDef();
                    break;
                }
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


int CharacterList::DetectCharacterExist()
{
    if (!head->PassNextData())
    {
        cout << "没有任何角色。\n";
        cout << endl;
        return 1;
    }
    else return 0;
}