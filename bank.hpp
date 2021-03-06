#include "accountholder.hpp"
#include <sstream>
#include <fstream>
#include <vector>

class Bank{
private:
    std::vector<AccountHolder> accounts;
    static int acc_number;

public:
    //Initialize clients.dat
    Bank();
    //Load accounts to file
    ~Bank();
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

    dob string2dob(std::string buffer);
    //Search account interface
    int search();
    //Search by id and returns bool
    bool search_id(int id);
    //Converts string 2 account
    void str2Account(std::string str);

};