#include "CharacterList.h"
#include "CharacterManagement.h"

void CharacterList::Print(){
    int i = 1;
    CharacterNode* Current = _Header->Next;
    while (Current){
        cout << i << "��"
             << "���֣�" << Current->Data->GetName() << "\n"
             << "   ��������" << Current->Data->GetAtk() << "\n"
             << "   ��������" << Current->Data->GetDef() << "\n" << endl;

        Current = Current->Next;
        i++;
    }
    return;
}

//Add����ÿ�ζ�����ͷ��ʼ��������󣬻᲻���˷����ܣ��ɷ����һ���̶�ָ������ĩβ��ָ�룿
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

    //��һ���Ǹ���ɫ���ϱ�ţ�����Remove��modify���иĶ�
    Current->Next->Data->SetNo(i);
}

//if������֮�󣬺����Ĵ����ƺ����������ѭ������Ҫע�Ⲣ����; 
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
    cout << "�����ڸý�ɫ���˻���������\n" << endl;
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

//��֪��while������ܷ���defult֮�������»ص�while��ͷ�����жϣ���Ҫע��
void CharacterList::Modify(int No){
    CharacterNode* Current = _Header->Next;
    while (Current){
        int i = Current->Data->GetNo();
        if (i == No){
            int Element = NULL;
            do{
                cout << "��������Ķ������ԣ�\n"
                    << "1. ���ƣ�2.��������3.������\n";
                cin >> Element;
            } while (InputChecking(Element));
            cout << endl;

            //������ҵ�ѡ�����Ķ���������֮һ
            switch (Element)
            {
            case 1:
            {
                string name;
                cout << "�����������ƣ�"; cin >> name; Current->Data->SetName(name);
                cout << "��������Ϊ��" << Current->Data->GetName() << endl;
                break;
            }
            case 2:
            {
                int atk;
                do{
                    cout << "�������¹�������"; cin >> atk;
                } while (InputChecking(atk));

                Current->Data->SetAtk(atk);
                cout << "���ڹ�����Ϊ��" << Current->Data->GetAtk() << endl;
                break;
            }
            case 3:
            {
                int def;
                do{
                    cout << "�������·�������"; cin >> def;
                } while (InputChecking(def));

                Current->Data->SetDef(def);
                cout << "���ڷ�����Ϊ��" << Current->Data->GetDef() << endl;
                break;
            }
            default:
                cout << "����������"<<endl;
                break;
            }
        }
        else {
            Current = Current->Next;
            if (!Current) {
                cout << "�����ڸý�ɫ���˳���������\n" << endl;
                return;
            }
        }

        int q;
        cout << endl << "�Ƿ��˳���\n1. ��\t2. ��"; cin >> q;
        if (q == 1)
            return;
        cout << endl;
    }

}


int CharacterList::DetectExist(){
    if (!_Header->Next){
        cout << "û���κν�ɫ��\n";
        cout << endl;
        return 1;
    }
    else return 0;
}