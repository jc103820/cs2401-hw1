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

    while(!ifs.eof()){
        list[used].write_check(ifs);
        used++;
    }
}

void Checkbook::deposit(double depamount){
    balance += depamount;
}

double Checkbook::get_balance(){
    return balance;
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

/*
void Checkbook::remove(int num){
    Check tmp;
    bool found = 0;
    for (int i = 0; i < used; i++){
        if (list[i].get_num() == num){
            found = 1;
            //Put all of used data into i.
            list[i] = list[used];
            cout << "--" << endl;
            list[i].output(cout);
            used--;
        }
    }
    if (found == 0){
        cout << "ERROR: Check not found" << endl;
    }
    
} */

/*
void number_sort(){
    //TODO
    cout << "Not Finished" << endl;
} */

double Checkbook::average(){
    double total = 0;
    for (int i = 0; i < used; i++)
    {
        total += list[i].get_amount();
    }
    if (total == 0)
    {
        return 0;
    }
    
    return total / (used);
}

void Checkbook::save(ostream& ofs){
    ofs << fixed << setprecision(2) << balance << endl;
    ofs << next_avail;
    for (int i = 0; i < used; i++)
    {
        list[i].output(ofs);
    }
}