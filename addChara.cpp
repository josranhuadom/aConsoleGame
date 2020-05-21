#include "CharacterStruct.h"

extern Chara* head;

void addChara()
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
    
    if(head == NULL)
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