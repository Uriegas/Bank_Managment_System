#include "bank.hpp"

int Bank::menu(){
    std::string buffer;
    int option;

    while (true){
    buffer.empty();
    std::cout << buffer;
    std::cout << "****************Banking Managment System****************" << '\n'
              << "Select the action(Input Number)." << '\n'
              << "1. Create New Accout" << '\n'
              << "2. Update information of existing accout" << '\n'
              << "3. Transactions" << '\n'
              << "4. View details of existing account" << '\n'
              << "5. Remove existing account" << '\n'
              << "6. Accounts List" << std::endl;
              std::cin.clear();
    
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> option;

    switch (option)
    {
    case 1:
        creatAccount();
        break;
    case 2:
        updateAccount();
        break;
        /*
    case 3:
        transaction();
        break;
    case 4:
        details();
        break;
    case 5:
        remove();
        break;
        */
    case 6:
        return 0;
        break;
    default:
        menu();
        break;
    }

    }
}

void Bank::creatAccount(){
    std::string buffer;
    std::string name;
    dob dateofbirth;
    std::string citizenship_no;
    std::string address; 
    std::string phone;
    float money;
    acc_type account_type;

    int selection;

    std::cout << "Enter Name:";
    std::cin.clear();
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> name;

    std::cout << "Enter Date of Birth: ";
    std::cin.clear();
    std::getline(std::cin, buffer);
   // dateofbirth = string2dob(buffer);//Not defined yet
    
    std::cout << "Enter CURP: " ;
    std::cin.clear();
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> citizenship_no;

    std::cout << "Enter address: " ;
    std::cin.clear();
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> address;

    std::cout << "Enter phone: " ;
    std::cin.clear();
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> phone;

    std::cout << "Account Types.\n" 
              << "1. Savings" << '\n'
              << "2. Current" << '\n'
              << "3. Fixed 1 Year" << '\n'
              << "4. Fixed 2 Year" << '\n'
              << "5. Fixed 3 Year" << '\n';
    std::cin.clear();
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> selection;
    account_type = (acc_type)selection;

    std::cout << "Enter first deposit:" ;
    std::cin.clear();
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> money;

    AccountHolder tmp(100, name, dateofbirth, citizenship_no, address, phone, money, account_type);

}

dob Bank::string2dob(std::string buffer){
    int day, month, year;
    day = (int)buffer[0-1];
    month = (int)buffer[3-4];
    year = (int)buffer[6-9];

    return dob(day, month, year);
}

void Bank::updateAccount(){
    
}