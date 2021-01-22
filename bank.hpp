#include "accountholder.hpp"
#include <sstream>
#include <fstream>
#include <vector>

class Bank{
private:
    //Current accounts loaded in program
    std::vector<AccountHolder> accounts;
public:
    int menu();
    //Create account interface
    void creatAccount();
    /*
    //update info interface
    void updateAccount();
    //transactions interface
    void transaction();
    //details of account interface
    void details();
    //remove account interface
    void remove();
    //Erase an specific account
    void erase(AccountHolder a);
    //Print all accounts
    void viewlist();

    //Helper functions
    //Loads accounts in file
    void loadAccounts();
    dob string2dob(std::string buffer);
    */
};