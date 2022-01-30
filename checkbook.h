
#include "check.h"
#include <iostream>
#include <string>
using namespace std;

class Checkbook{

    public:
        static const size_t SIZE = 200;

        Checkbook();
         // Have their checkbook reloaded from the backup file – so they do not re-enter their checks every time they start the program.
        void load_from_file(istream& ifs);
        
        // Make a deposit into their checkbook.
        void deposit(double depamount);

        /* Write a check – the user cannot enter the check-number, the check number will be inserted by 
        the checkbook using the set_chk_num() function of the Check class. */
        //void write_check(istream& cin);

        //See the checkbook balance
        double get_balance();

        /*See a listing of all the checks that they have written – for each check they should see all the 
        information about that check */
        void show_all(ostream& cout);

        /*Remove a check by entering its check-number. Once a check is removed that check number is 
        never available again */
        //void remove(int num);

        /*Sort the checks by check-number. */
        //void number_sort();

        /*Sort the checks alphabetically by the person to whom they were written. */
        //void payto_sort();

        /*Sort the checks by the date they were written. */
        //void date_sort();

        /*Find and view all the checks written to a particular payee along with the total amount of those 
        checks */
        //void show(string str1);

        /*Find the average of all the checks written */
        double average();

        /*Have the checkbook backed up to the same file that it was read from at the beginning of the 
        program, upon exiting the program (the main calls the save function – you write the save 
        function) */
        void save(ostream& ofs);

    private:
        Check list[SIZE];
        int used;
        double balance;
        int next_avail;


};