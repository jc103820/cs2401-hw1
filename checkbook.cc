/**
 * @file checkbook.cc
 * @author Jansen Craft
 * @brief  This is the implementation file for the checkbook class. This class uses the Check class and thus the Date class to
 * create an array of checks that the user can manipulate in various ways.
 * @date 2022-01-31
 */

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

void Checkbook::swap(int a, int b){
    Check tmp;
    tmp = list[a];
    list[a] = list[b];
    list[b] = tmp;
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

void Checkbook::write_check(istream& cin){
    list[used].set_check_num(next_avail);
    list[used].write_check(cin);
    used++;
    next_avail++;
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

void Checkbook::remove(int num){
    Check tmp;
    bool found = 0;
    for (int i = 0; i < used; i++){
        if (list[i].get_num() == num){
            found = 1;
            swap(used - 1, i);
            used--;
        }
    }
    if (found == 0){
        cout << "ERROR: Check not found" << endl;
    }
    
}

void Checkbook::number_sort(){
    Check temp;
    bool done = false;

    while(!done){
        done = true;
        for (int i = 0; i < used - 1; i++){
            if(list[i].get_num() > list[i + 1].get_num()){
                swap(i, i + 1);
                done = false;
            }
        }
        
    }
}

void Checkbook::payto_sort(){
    Check temp;
    bool done = false;

    while(!done){
        done = true;
        for (int i = 0; i < used - 1; i++){
            if(greaterThanAlpha(list[i].get_payto(), list[i+1].get_payto())){
                swap(i, i + 1);
                done = false;
            }
        }
        
    }
}

void Checkbook::date_sort(){
    Check temp;
    bool done = false;

    while(!done){
        done = true;
        for (int i = 0; i < used - 1; i++){
            if(list[i].get_date() > list[i + 1].get_date()){
                swap(i, i + 1);
                done = false;
            }
        }
        
    }
}

void Checkbook::show(string str1){
    string lowerstr1 = "";
    string lowertemp = "";

    //str1 to lowercase str1
    for (size_t i = 0; i < str1.length(); i++){
        lowerstr1 += tolower(str1[i]);
    }
    
    int total = 0;
    for (int i = 0; i < used; i++){
        lowertemp = "";
        //turns current Check's name to a lowercase version and stores in lowertemp
        for (size_t j = 0; j < list[i].get_payto().length(); j++){
            lowertemp += tolower(list[i].get_payto()[j]);
        }
        if (lowertemp == lowerstr1){
            list[i].output(cout);
            total++;
        }
    }
    cout << "Total checks to " << str1 << ": " << total << endl;
}

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

bool Checkbook::greaterThanAlpha(string a, string b){
    string aLower = "";
    string bLower = "";
    for (size_t i = 0; i < a.length(); i++){
        aLower += tolower(a[i]);
    }
    for (size_t i = 0; i < b.length(); i++){
        bLower += tolower(b[i]);
    }
    if (aLower > bLower){
        return true;
    } else {
        return false;
    }  
}