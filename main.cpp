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