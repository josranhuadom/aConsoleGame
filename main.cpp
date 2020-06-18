#include "CharacterManagement.h"
#include "CharacterList.h"
#include "Character.h"
using namespace std;

int main()
{
    
    CharacterList theList;
    CharacterManagement theManagementSys;
    
    while (1)
    {
        theManagementSys.MainInterface(theList);
    }
}

int InputChecking(int m)
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