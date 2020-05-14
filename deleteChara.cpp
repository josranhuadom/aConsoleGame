#include "CharacterStruct.h"

extern Chara* head;

void deleteChara()
{
    printChara();

    int No;
    cout<<"请输入想要删除的角色编号：";
    cin >> No;

    Chara *ptr = head->next, 
          *q = head;

    //查找角色并移动指针
    for (int i = 1; i <= No; i++)
    {
        if (No == i)
            break;
        else if(ptr)
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

    cout << "以下是剩余的角色：\n";
    printChara();

    return;
}