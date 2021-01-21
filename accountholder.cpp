#include "accountholder.hpp"

//************Date Of Birthday constructors***************
dob::dob(int a, int b, int c)
    :day(a), month(b), year(c){}//Initializer list

dob::dob(const dob& date)
    :day(date.day), month(date.month), year(date.year){}

dob::dob(){
    dob(00, 00, 0000);
}

//***************AccountHolder Functions******************
//Constructor (New account function)
AccountHolder::AccountHolder(std::string name, const dob& date, int ine, std::string address, std::string phone, float cash) :dateofbirth(date){
    this->name = name;
    this->citizenship_no = ine;
    this->address = address;
    this->phone = phone;
    this->money = cash;
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
    out << account.name << '\n' << account.citizenship_no << '\n'
        << account.address << '\n' << account.phone << '\n'
        << account.money << '\n';
        return out;
}

//Erase function
//Erase account from file
bool AccountHolder::erase(){
    std::cout << "Succesfully Erased" << std::endl;
    return true;
}