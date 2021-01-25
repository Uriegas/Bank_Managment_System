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
            out << "1";
            break;
        case CURRENT:
            out << "2";
            break;
        case FIXED_1Y:
            out << "3";
            break;
        case FIXED_2Y:
            out << "4";
            break;
        case FIXED_3Y:
            out << "5";
            break;
        default:
            out << "-1";
            break;
    }
    return out;
}

//Print function
std::ostream& operator<<(std::ostream& out, const AccountHolder& a){
    out << a.id << '#' << a.name << '#' << a.dateofbirth << '#' << a.citizenship_no << '#'
        << a.address << '#' << a.phone << '#' << a.money << '#' << a.account_type << "#\n";
    return out;
}

void AccountHolder::printAccount(){
    std::cout << "***************Detailed Information of Account****************" << '\n'
        << "Account Number:" << '\t' << id << '\n'
        << "AccountHolder Name:" << '\t' << name << '\n' 
        << "Date of Birthday:" << '\t' << dateofbirth << '\n'
        << "Citizenship Number:" << '\t' << citizenship_no << '\n'
        << "Address:" << "\t\t" << address << '\n'
        << "Account Type" << "\t\t";

    switch(account_type){
        case SAVING:
            std::cout << "SAVING";
            break;
        case CURRENT:
            std::cout << "CURRENT";
            break;
        case FIXED_1Y:
            std::cout << "FIXED_1Y";
            break;
        case FIXED_2Y:
            std::cout << "FIXED_2Y";
            break;
        case FIXED_3Y:
            std::cout << "FIXED_3Y";
            break;
        default:
            std::cout << "NOT VALID ACCOUNT";
            break;
    }
    std::cout << "\nPhone Number:" << "\t\t" << phone << '\n'
              << "Current Balance:" << '\t' << "$" << money << '\n';
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
