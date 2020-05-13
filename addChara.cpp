#include "CharacterStruct.h"

extern Chara* head;

void addChara()
{

    string NAME;
    int ATK;
    int DEF;

    /*这部分缺失检查输入规范，一旦输入错误会进入死循环*/
    cout << "请输入角色名称：";
    cin >> NAME;

    cout << "请自定义该角色的攻击力：";
    cin >> ATK;

    cout << "请自定义该角色的防御力：";
    cin >> DEF;
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