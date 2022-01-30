/*************************************************************************
    This is the implementation file for the Check class. For more 
		information about the class see check.h.
    Students are expected to implement some of the functions shown 
		below.
	John Dolan			Ohio University EECS	September 2019
	Patricia Lindner	Ohio University EECS	August 2021
*************************************************************************/
#include "check.h"
#include <string>
#include <iomanip>
using namespace std;

Check::Check(Date d, string p, int num, double amt){
	checknum = num;
	date = d;
	payto = p;
	amount = amt;
}

// Input and output functions
void Check::write_check(std::istream& ins){
	/* You are to write the implementation of this function to read 
	from the keyboard or a file. Remember to use getline to read the 
	payto.  */
	string temp;

	if(&cin == &ins){ //If from CIN stream
		cout << "Enter the date : ";
		ins >> date;
		ins.ignore(100, '\n');

		cout << "Enter the recipient : ";
		getline(ins, temp);
		payto = temp;

		cout << "Enter the amount : ";
		getline(ins, temp);
		amount = stod(temp);

	} else { //If from file stream
		getline(ins, temp); //checknum
		checknum = stoi(temp);

		ins >> date; //date
		ins.ignore(100, '\n');

		getline(ins, temp); //payto
		payto = temp;

		getline(ins, temp); //amount
		amount = stod(temp);
	}

}

void Check::output(std::ostream& outs)const{
	/* You are to write the implementation of this function to write 
	to the monitor or to a file. Remember not to put labels into the 
	file.*/
	string temp;

	if(&cout == &outs){ //If to COUT stream
		outs << "CHECKNUM: " << checknum << endl;
		outs << "DATE: " << date << endl;
		outs << "PAYTO: " << payto << endl;
		outs << "AMOUNT: " << fixed << setprecision(2) << amount << endl << endl;

	} else { //If to file stream
		outs << checknum << endl;
		outs << date << endl;
		outs << payto << endl;
		outs << amount << endl;
	}
}

ostream& operator << (ostream& outs, const Check& c){
	c.output(outs);
	return outs;
}

istream& operator >> (istream& ins, Check& c){
	c.write_check(ins);
	return ins;
}