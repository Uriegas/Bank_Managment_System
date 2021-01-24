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
AccountHolder::AccountHolder(int id, std::string name, const dob& date, std::string ine, std::string address, std::string phone, float cash, acc_type account_type) :dateofbirth(date){
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
//For printing account type properly
std::ostream& operator<<(std::ostream& out, const acc_type& type){
    switch(type){
        case SAVING:
            out << "SAVING";
            break;
        case CURRENT:
            out << "SAVING";
            break;
        case FIXED_1Y:
            out << "SAVING";
            break;
        case FIXED_2Y:
            out << "SAVING";
            break;
        case FIXED_3Y:
            out << "SAVING";
            break;
        default:
            out << "NOT VALID ACCOUNT";
            break;
    }
    return out;
}

//Print function
std::ostream& operator<<(std::ostream& out, const AccountHolder& account){
    out << "***************Detailed Information of Account****************" << '\n'
        << "Account Number:" << '\t' << account.id << '\n'
        << "AccountHolder Name:" << '\t' << account.name << '\n' 
        << "Date of Birthday:" << '\t' << account.dateofbirth << '\n'
        << "Citizenship Number:" << '\t' << account.citizenship_no << '\n'
        //Pending to add age, need a function to read current date.
        << "Address:" << "\t\t" << account.address << '\n'
        << "Account Type" << "\t\t" << account.account_type << '\n'
        << "Phone Number:" << "\t\t" << account.phone << '\n'
        //Balance of Deposit(+) and Withdraws(-). Same: Need current date.
        << "Current Balance:" << '\t' << "$" << account.money << '\n';
        return out;
}

//Print in list mode
void AccountHolder::toList(){
    std::cout << id << '\t' << name << '\t' << address << '\t' << phone << '\n';  
}

//Returns ID
int AccountHolder::getID(){
    return this->id;
}

//Returns name
std::string AccountHolder::getName(){
    return this->name;
}
