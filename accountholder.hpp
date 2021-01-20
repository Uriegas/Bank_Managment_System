#include <iostream>

struct dob{
public:
    int day, month, year;
    dob(int a, int b, int c);
    dob(const dob& date);
    dob();
};

class AccountHolder{
public:
    AccountHolder(std::string name, const dob& dob, int ine, std::string address, std::string phone, float cash);
    int transfer(AccountHolder a, float quantity);
    friend std::ostream& operator<<(std::ostream& out, const AccountHolder& account);
private:
    std::string name;
    dob dateofbirth;
    int citizenship_no;
    std::string address; 
    std::string phone;
    float money;
};