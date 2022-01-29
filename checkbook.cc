/*************************************************************************
Jansen Craft
Chechbook Class Implementation
*************************************************************************/
#include "checkbook.h"
#include <iomanip>

using namespace std;

Checkbook::Checkbook(){
    used = 0;
    balance = 0;
    next_avail = 0;
}

void Checkbook::show_all(ostream& cout){
    if(used > 0){
        cout << "Here are your checks: " << endl;
        for (int i = 0; i < used; i++)
        {
        list[i].output(cout);
        }
        
    } else {
        cout << "ERROR: No Checks Available" << endl;
    }    
}

