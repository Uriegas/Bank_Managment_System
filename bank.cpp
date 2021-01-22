#include "bank.hpp"

int Bank::menu(){
    std::string buffer;
    int option;

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
        /*
    case 2:
        updateAccount();
        break;
    case 3:
        transaction();
        break;
    case 4:
        details();
        break;
    case 5:
        remove();
        break;
    case 6:
        return 0;
        break;
        */
    default:
        menu();
        break;
    }

    return 1;
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

    std::cout << "Enter Name:";
    std::cin.clear();
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> name;

    std::cout << "Enter Date of Birth" << std::endl;
    std::cin.clear();
    std::getline(std::cin, buffer);
   // dateofbirth = string2dob(buffer);//Not defined yet
    
    std::cout << "Enter CURP:" << std::endl;
    std::cin.clear();
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> citizenship_no;

    std::cout << "Enter address:" << std::endl;
    std::cin.clear();
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> address;
}
