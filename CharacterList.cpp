#include "CharacterList.h"
#include "CharacterManagement.h"

void CharacterList::Print(){
    int i = 1;
    CharacterNode* Current = _Header->Next;
    while (Current){
        cout << i << "："
             << "名字：" << Current->Data->GetName() << "\n"
             << "   攻击力：" << Current->Data->GetAtk() << "\n"
             << "   防御力：" << Current->Data->GetDef() << "\n" << endl;

        Current = Current->Next;
        i++;
    }
    return;
}

//Add函数每次都都从头开始遍历到最后，会不会浪费性能？可否加入一个固定指向链表末尾的指针？
void CharacterList::Add(Character *Ch){
    int i = 1;
    CharacterNode* Current = _Header;
    while (Current->Next) {
        Current = Current->Next;
        i++;
    }
    Current->Next = new CharacterNode;
    Current->Next->Next = NULL;
    Current->Next->Data = Ch;

    //这一条是给角色标上编号，方便Remove和modify进行改动
    Current->Next->Data->SetNo(i);
}

//if语句结束之后，后续的代码似乎会造成无限循环，需要注意并测试; 
void CharacterList::Remove(int No){
    CharacterNode* Current = _Header;
    while (Current->Next){
        int i = Current->Next->Data->GetNo();
        if (i == No) {
            CharacterNode* Next = Current->Next->Next;
            delete Current->Next;
            Current->Next = Next;
            return;
        }
        Current = Current->Next;
    }
    cout << "不存在该角色，退回至主界面\n" << endl;
    return;
}

CharacterNode* CharacterList::Get(unsigned index){
    unsigned i = 0;
    CharacterNode* Current = _Header->Next;
    while (Current){
        if (index == i) return Current;
        Current = Current->Next;
        i += 1;
    }
    return NULL;
}

unsigned CharacterList::Size(){
    unsigned i = 0;
    CharacterNode* Current = _Header->Next;
    while (Current){
        Current = Current->Next;
        i += 1;
    }
    return i;
}

//不知道while语句中能否在defult之后还能重新回到while开头重新判断，需要注意
void CharacterList::Modify(int No){
    CharacterNode* Current = _Header->Next;
    while (Current){
        int i = Current->Data->GetNo();
        if (i == No){
            int Element = NULL;
            do{
                cout << "请问你想改动的属性：\n"
                    << "1. 名称；2.攻击力；3.防御力\n";
                cin >> Element;
            } while (InputChecking(Element));
            cout << endl;

            //根据玩家的选择来改动三个属性之一
            switch (Element)
            {
            case 1:
            {
                string name;
                cout << "请输入新名称："; cin >> name; Current->Data->SetName(name);
                cout << "现在名称为：" << Current->Data->GetName() << endl;
                break;
            }
            case 2:
            {
                int atk;
                do{
                    cout << "请输入新攻击力："; cin >> atk;
                } while (InputChecking(atk));

                Current->Data->SetAtk(atk);
                cout << "现在攻击力为：" << Current->Data->GetAtk() << endl;
                break;
            }
            case 3:
            {
                int def;
                do{
                    cout << "请输入新防御力："; cin >> def;
                } while (InputChecking(def));

                Current->Data->SetDef(def);
                cout << "现在防御力为：" << Current->Data->GetDef() << endl;
                break;
            }
            default:
                cout << "请重新输入"<<endl;
                break;
            }
        }
        else {
            Current = Current->Next;
            if (!Current) {
                cout << "不存在该角色，退出至主界面\n" << endl;
                return;
            }
        }

        int q;
        cout << endl << "是否退出？\n1. 是\t2. 否："; cin >> q;
        if (q == 1)
            return;
        cout << endl;
    }

}


int CharacterList::DetectExist(){
    if (!_Header->Next){
        cout << "没有任何角色。\n";
        cout << endl;
        return 1;
    }
    else return 0;
}