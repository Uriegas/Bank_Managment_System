#include "accountholder.hpp"
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

class Bank{
private:
    std::vector<AccountHolder> accounts;
    static int acc_number;

public:
    //Initialize clients.dat
    Bank();
    int menu();
    //Create account interface
    void creatAccount();
    //update info interface
    void updateAccount();
    //transactions interface
    void transaction();
    //details of account interface
    void details();
    //Erase an specific account
    void erase();
    //Print all accounts
    void viewlist();

    /*
    //Helper functions
    //Loads accounts in file
    void loadAccounts();
    */
    dob string2dob(std::string buffer);
    //Search account interface
    int search();
    //Search by id and returns bool
    bool search_id(int id);
};