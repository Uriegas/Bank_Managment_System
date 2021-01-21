#include <iostream>

enum parameter { WITHDRAW, DEPOSIT };

struct dob{
public:
    int day, month, year;
    dob(int a, int b, int c);
    dob(const dob& date);
    dob();
};

class AccountHolder{
public:
    //Constructor (New account function)
    AccountHolder(std::string name, const dob& dob, int ine, std::string address, std::string phone, float cash);
    //Edit account function
    void edit(std::string new_address, std::string new_phone);
    //Withdraw and deposit function
    bool transact(float quantity, parameter par);
    //Erase function
    bool erase();
    //Print function
    friend std::ostream& operator<<(std::ostream& out, const AccountHolder& account);
private:
    std::string name;
    dob dateofbirth;
    int citizenship_no;
    std::string address; 
    std::string phone;
    float money;
};