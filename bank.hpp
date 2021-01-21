#include "accountholder.hpp"
#include <vector>

class Bank{
private:
    //Current accounts loaded in program
    std::vector<AccountHolder> accounts;
public:
    int menu();
    //Create account interface
    void creatAccount();
    //Erase an specific account
    void erase(AccountHolder a);
    //Print all accounts
    void viewlist();
};