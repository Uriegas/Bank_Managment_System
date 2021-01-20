#include "accountholder.hpp"

dob::dob(int a, int b, int c)
    :day(a), month(b), year(c){}//Initializer list

dob::dob(const dob& date)
    :day(date.day), month(date.month), year(date.year){}

dob::dob(){
    dob(00, 00, 0000);
}

std::ostream& operator<<(std::ostream& out, const AccountHolder& account){
    out << account.name << '\n' << account.citizenship_no << '\n'
        << account.address << '\n' << account.phone << '\n'
        << account.phone << '\n' << account.money << '\n';
        return out;
}

AccountHolder::AccountHolder(std::string name, const dob& date, int ine, std::string address, std::string phone, float cash) :dateofbirth(date){
    this->name = name;
    this->citizenship_no = ine;
    this->address = address;
    this->phone = phone;
    this->money = cash;
}
