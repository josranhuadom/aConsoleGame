﻿#include "CharacterStruct.h"

extern Chara* head;

void modiChara()
{
    extern Chara* head;
    char choice;
    int No;

    do
    {
        cout << "\n以下是所有角色：\n";
        printChara();
        cout << "请输入想要改动的角色编号：\n";
        cin >> No;
        cout << endl;

        Chara* ptr = head->next;

        for (int i = 1; i <= No ; i++)
        {
            if (No == i)
                break;
            else
                ptr = ptr->next;
        }

        //检查玩家是否给出不存在的角色编号
        if (!ptr)
        {
            delete ptr;
            cout << "不存在该角色，退出至主界面\n" << endl;
            return;
        }

        do
        {
            int Element;
            cout << "请问你想改动的属性：\n"
                << "1. 名称；2.攻击力；3.防御力\n";
            cin >> Element;

            switch (Element)
            {
            case 1:
                cout << "请输入新名称：";
                cin >> ptr->name;
                cout << "现在新名称为：";
                cout << ptr->name;
                break;

            case 2:
                cout << "请输入新攻击力：";
                cin >> ptr->atk;
                cout << "现在新攻击力为：";
                cout << ptr->atk;
                break;

            case 3:
                cout << "请输入新防御力：";
                cin >> ptr->def;
                cout << "现在新防御力为：";
                cout << ptr->def;
                break;

            default:
                cout << "不存在，请重新输入";
                break;
            }

            cout << endl;
            cout << "请问还需要改动该角色的其他属性吗？(Y/N)：";
            cin >> choice;
        } while (choice == 'Y');
        
        cout << endl;
        cout << "请问还需要改动其他角色的属性吗？(Y/N)：";
        cin >> choice;
    } while (choice == 'Y');

    return;
}