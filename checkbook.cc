/*************************************************************************
Jansen Craft
Chechbook Class Implementation
*************************************************************************/
#include "checkbook.h"
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

Checkbook::Checkbook(){
    used = 0;
    balance = 0;
    next_avail = 0;
}
void Checkbook::load_from_file(istream& ifs){
    string temp;
    getline(ifs, temp);
    if(temp == ""){
        cout << "ERROR: Empty file" << endl;
        return;
    }
    balance = stod(temp);

    getline(ifs, temp);
    next_avail = stoi(temp);

    cout << "Balance: " << balance << endl;
    cout << "Next: " << next_avail << endl;
    while(!ifs.eof()){
        list[used].write_check(ifs);
        used++;
    }
}

void Checkbook::show_all(ostream& cout){
    if(used > 0){
        cout << "Here are your checks: " << endl;
        cout << "----------------------" << endl << endl;
        for (int i = 0; i < used; i++)
        {
        list[i].output(cout);
        }
        
    } else {
        cout << "ERROR: No Checks Available" << endl;
    }    
}

