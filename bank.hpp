#include "accountholder.hpp"
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

class Bank{
private:
    //Current accounts loaded in program
    std::vector<AccountHolder> accounts;
//    std::hash<AccountHolder> acc;
public:
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
};