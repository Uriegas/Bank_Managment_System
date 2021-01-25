#include <iostream>

enum parameter { WITHDRAW = 1, DEPOSIT };
//Cannot deposit or withdraw in fixed accounts
enum acc_type { SAVING = 1, CURRENT, FIXED_1Y, FIXED_2Y, FIXED_3Y };

//Day Of Birthday Class
class dob{
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
    //For printing account type properly
    friend std::ostream& operator<<(std::ostream& out, const acc_type& type);
    //Print detailed information function
    void printAccount();
    //Print to file
    friend std::ostream& operator<<(std::ostream& out, const AccountHolder& a);
    //Print in list mode
    void toList();
    //Returns ID
    int getID();
    //Returns name
    std::string getName();
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