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
              << "6. Accounts List" << '\n'
              << "7. Exit" << std::endl;
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
    case 3:
        transaction();
        break;
    case 4:
        details();
        break;
    case 5:
        erase();
        break;
    case 6:
        viewlist();
        break;
    case 7:
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

    AccountHolder tmp(001, name, dateofbirth, citizenship_no, address, phone, money, account_type);
//    accounts.insert(std::pair<int, AccountHolder>(001, tmp));
    accounts.push_back(tmp);

}

void Bank::updateAccount(){ 
    int id = search();
    for(int i = 0; i < accounts.size(); i++){
        if(accounts[i].getID() == id){
            std::string new_address, new_phone, buff;

            std::cout << "\nPlease enter the new address: ";
            std::cin.clear();
            std::getline(std::cin, buff);
            std::stringstream(buff) >> new_address;

            std::cout << "Please enter the new phone number: ";
            std::cin.clear();
            std::getline(std::cin, buff);
            std::stringstream(buff) >> new_phone;
            accounts[i].edit(new_address, new_phone);
            return;
        }
    }
    std::cout << "Account not found!!!";
        
}

//transactions interface
void Bank::transaction(){
    int id = search();
    
    for(int i = 0; i < accounts.size(); i++){
        if(accounts[i].getID() == id){
            std::string buff;
            float quanta;
            int selection;
            parameter par;
            std::cout << "\nMovements."
                        << "\n1. Withdraw"
                        << "\n2. Deposit"
                        << "\nEnter the selected action: ";
            std::cin.clear();
            std::getline(std::cin, buff);
            std::stringstream(buff) >> selection;
            par = (parameter)selection;
            accounts[i].transact(quanta, par);
            return;
        }
    }
    std::cout << "Account not found!!!";
}

//details of account interface
void Bank::details(){
    int id = search();
    
    for(int i = 0; i < accounts.size(); i++){
        if(accounts[i].getID() == id){
            std::cout << accounts[i];
            return;
        }
    }
    std::cout << "Account not found!!!";
}

//This functions doesnt work yet
//Erase an specific account
void Bank::erase(){
    int id = search();
//    std::remove_if( accounts.begin(), accounts.end(), search_id(id) );
    for(int i = 0; i < accounts.size(); i++){
        if(accounts[i].getID() == id){
//            accounts.erase(accounts.begin()+i);
//            accounts.erase();
//            std::find(accounts.begin(), accounts.end(), );
//            std::__find_if(accounts.begin(), accounts.end(),);
//            std::remove_if( accounts.begin(), accounts.end(), search_id(id) );
            std::cout << accounts[i];
            return;
        }
    }
    std::cout << "Account not found!!!";
}

//Print all accounts
void Bank::viewlist(){
    if( !accounts.empty() ){
        std::cout << "\nList of Accounts.\n";
        for(int i = 0; i < accounts.size(); i++){
            accounts[i].toList();
        }
    }
    else
        std::cout << "\n Empty List\n";
}

//Helper functions
int Bank::search(){
    std::string buff;
    int id;

    std::cout << "Enter account ID (Number): ";
    std::cin.clear();
    std::getline(std::cin, buff);
    std::stringstream(buff) >> id;
    return id;
}

bool Bank::search_id(int id){
    for(int i = 0; i < accounts.size(); i++)
        if( id == accounts[i].getID() )
            return true;
    return false;
}

dob Bank::string2dob(std::string buffer){
    int day, month, year;
    day = (int)buffer[0-1];
    month = (int)buffer[3-4];
    year = (int)buffer[6-9];

    return dob(day, month, year);
}