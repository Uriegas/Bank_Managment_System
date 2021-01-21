#include "accountholder.hpp"

//************Date Of Birthday constructors***************
dob::dob(int a, int b, int c)
    :day(a), month(b), year(c){}//Initializer list

dob::dob(const dob& date)
    :day(date.day), month(date.month), year(date.year){}

dob::dob(){
    dob(00, 00, 0000);
}

std::ostream& operator<<(std::ostream& out, const dob& birth){
    out << birth.day << '/' << birth.month << '/' << birth.year;
    return out;
}

//***************AccountHolder Functions******************
//Constructor (New account function)
AccountHolder::AccountHolder(int id, std::string name, const dob& date, int ine, std::string address, std::string phone, float cash, acc_type account_type) :dateofbirth(date){
    this->id = id;
    this->name = name;
    this->citizenship_no = ine;
    this->address = address;
    this->phone = phone;
    this->money = cash;
    this->account_type = account_type;
}

//Edit account function
void AccountHolder::edit(std::string new_address, std::string new_phone){
    this->address = new_address;
    this->phone = new_phone;
}

//Withdraw and deposit function
//Parameter could be: Withdraw, deposit or transference
bool AccountHolder::transact(float quantity, parameter par){
    if(par == WITHDRAW)
        this->money -= quantity;
    else if(par == DEPOSIT)
        this->money += quantity;
    else
        return false;
    return true;
}

//Print function
std::ostream& operator<<(std::ostream& out, const AccountHolder& account){
    out << "Detailed Account Information of Account:" << account.id
        << "AccountHolder Name:" << '\t' << account.name << '\n' 
        << "Date of Birthday:" << '\t' << account.dateofbirth
        << "Citizenship Number:" << '\t' << account.citizenship_no << '\n'
        //Pending to add age, need a function to read current date.
        << "Address:" << '\t' << account.address << '\n'
        << "Account Type" << '\t' << account.account_type << '\n'
        << "Phone:" << '\t' << account.phone << '\n'
        //Balance of Deposit(+) and Withdraws(-). Same: Need current date.
        << "Current Balance:" << '\t' << "$ " << account.money << '\n';
        return out;
}

//Print in list mode
void AccountHolder::toList(){
    std::cout << id << '\t' << name << '\t' << address << '\t' << phone << '\n';  
}