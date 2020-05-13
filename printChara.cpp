#include "CharacterStruct.h"
extern Chara* head;

void printChara()
{

    if(!head)
    {
        cout << "没有任何角色。\n";
        exit(-1);
    }
    
    int No = 1;
    Chara *ptr = head->next;
    while(ptr)
    {
        cout << No << "："
            << "名字：" << ptr->name << "\n"
            << "   攻击力：" << ptr->atk << "\n"
            << "   防御力：" << ptr->def << "\n"<<endl;

        ptr = ptr->next;
        No++;
    }

    return;
}