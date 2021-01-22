#include <iostream>

enum parameter { WITHDRAW, DEPOSIT };
//Cannot deposit or withdraw in fixed accounts
enum acc_type { SAVING, CURRENT, FIXED_1Y, FIXED_2Y, FIXED_3Y };

struct dob{
public:
    int day, month, year;
    dob(int a, int b, int c);
    dob(const dob& date);
    dob();
    friend std::ostream& operator<<(std::ostream& out, const dob& birth);
};

class AccountHolder{
public:
    //Constructor (New account function)
    AccountHolder(int id, std::string name, const dob& dob, std::string ine, std::string address, std::string phone, float cash, acc_type account_type);
    //Edit account function
    void edit(std::string new_address, std::string new_phone);
    //Withdraw and deposit function
    bool transact(float quantity, parameter par);
    //Print detailed information function
    friend std::ostream& operator<<(std::ostream& out, const AccountHolder& account);
    //Print in list mode
    void toList();
private:
    //Provided by the user
    std::string name;
    dob dateofbirth;
    std::string citizenship_no;
    std::string address; 
    std::string phone;
    float money;
    acc_type account_type;
    //Internal
    int id;
};