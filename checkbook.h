/**
 * @file checkbook.h
 * @author Jansen Craft
 * @brief This is the header file for the checkbook class. This class uses the Check class and thus the Date class to
 * create an array of checks that the user can manipulate in various ways.
 * @date 2022-01-31
 */

#include "check.h"
#include <iostream>
#include <string>
using namespace std;

class Checkbook{

    public:
        static const size_t SIZE = 200;

        Checkbook();

        /**
         * @brief Swaps the two Check objects in the list
         * 
         * @param a index of the first object
         * @param b index of the second object
         */
        void swap(int a, int b);

         /**
          * @brief Has their checkbook reloaded from the backup file – so they do not re-enter their checks every time they start the program.
          * 
          * @param ifs 
          */
        void load_from_file(istream& ifs);
        
        /**
         * @brief Makes a deposit into their checkbook.
         * 
         * @param depamount 
         */
        void deposit(double depamount);

        /**
         * @brief Writes a check – the user cannot enter the check-number, the check number will be inserted by 
        the checkbook using the set_chk_num() function of the Check class.
         * 
         * @param cin 
         */

        void write_check(istream& cin);

        /**
         * @brief Get the balance object
         * 
         * @return double of the balance object
         */
        double get_balance();

        /**
         * @brief Shows a listing of all the checks that they have written – for each check they should see all the 
        information about that check
         * 
         * @param cout outstream to send the message to. Must be cout
         */
        void show_all(ostream& cout);

        /**
         * @brief Remove a check by entering its check-number. Once a check is removed that check number is 
        never available again
         * 
         * @param num checknumber ot be removed
         */
        void remove(int num);

        /**
         * @brief Sorts the checks by check-number.
         */
        void number_sort();

        /**
         * @brief Sorts the checks alphabetically by the person to whom they were written.
         */
        void payto_sort();

        /**
         * @brief Sorts the checks by the date they were written.
         */
        void date_sort();
    
        /**
         * @brief Finds and views all the checks written to a particular payee along with the total amount of those 
        checks
         * 
         * @param str1 
         */
        void show(string str1);

        /**
         * @brief Finds the average of all the checks written
         * 
         * @return double - the average of all the checks written
         */
        double average();

        /**
         * @brief Has the checkbook backed up to the same file that it was read from at the beginning of the 
        program, upon exiting the program 
         * 
         * @param ofs out stream to send it to
         */
        void save(ostream& ofs);

        /**
         * @brief Returns true if the first string is less than the second alphabetically
         * 
         * @param a first string
         * @param b second string
         * @return true if first string is  alphabetically less than the second
         * @return false if the first string not  alphabetically less than the second
         */
        bool greaterThanAlpha(string a, string b);

    private:
        Check list[SIZE];
        int used;
        double balance;
        int next_avail;


};