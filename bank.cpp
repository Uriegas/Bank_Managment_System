#include "bank.hpp"

int Bank::acc_number = 0;

Bank::Bank(){
    std::ifstream file;
    file.open("accounts.txt", std::ios::in);
    //Every line in the file is an account object
    std::string str;

    if( file.fail() ){
        std::cerr << "Creating empty file";
        std::ofstream output("accounts.txt");
    }
    else{
        while( !file.eof() ){
            str.clear();
            std::getline(file, str, '\n');

            if(!str.empty())
                str2Account(str);
        }
    }
}

//Load accounts to file
Bank::~Bank(){
    std::ofstream file("accounts.txt", std::ios::out);
    if(file.is_open()){
        for(int i = 0; i < accounts.size(); i++){
            file << accounts[i];
        }
    }
    else{
        std::cout << "ERROR: COULDN'T OPEN FILE\n";
    }
    
    file.close();
}

int Bank::menu(){
    std::string buffer;
    int option;

    while (true){
        buffer.empty();
        std::cout << "\n****************Banking Managment System****************" << '\n'
                << "Select the action(Input Number)." << '\n'
                << "1. Create New Accout" << '\n'
                << "2. Update information of existing accout" << '\n'
                << "3. Transactions" << '\n'
                << "4. View details of existing account" << '\n'
                << "5. Remove existing account" << '\n'
                << "6. Accounts List" << '\n'
                << "7. Exit" << std::endl;
        
        std::getline(std::cin, buffer);
        std::stringstream(buffer) >> option;

        switch (option){
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
    std::getline(std::cin, name);
//    std::stringstream(buffer) >> name;

    std::cout << "Enter Date of Birth: ";
    std::getline(std::cin, buffer);
    dateofbirth = string2dob(buffer);
    
    std::cout << "Enter CURP: " ;
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> citizenship_no;

    std::cout << "Enter address: " ;
    std::getline(std::cin, address);
//    std::stringstream(buffer) >> address;

    std::cout << "Enter phone: " ;
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> phone;

    std::cout << "Account Types.\n" 
              << "1. Savings" << '\n'
              << "2. Current" << '\n'
              << "3. Fixed 1 Year" << '\n'
              << "4. Fixed 2 Year" << '\n'
              << "5. Fixed 3 Year" << std::endl;
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> selection;
    account_type = (acc_type)selection;

    std::cout << "Enter first deposit:" ;
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> money;

    //Increment counter of accounts
    acc_number++;
    //Create object Account
    AccountHolder tmp(acc_number, name, dateofbirth, citizenship_no, address, phone, money, account_type);
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
            std::getline(std::cin, new_address);

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

            std::cout << "Enter amount: $";
            std::getline(std::cin, buff);
            std::stringstream(buff) >> quanta;

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
            accounts[i].printAccount();
            return;
        }
    }
    std::cout << "Account not found!!!";
}

//Erase an specific account
void Bank::erase(){
    int id = search();
    for(int i = 0; i < accounts.size(); i++){
        if(accounts[i].getID() == id){
            accounts.erase(accounts.begin()+i);
            std::cout << "\nAccount " << accounts[i].getID() << "erased";
            return;
        }
    }
    std::cout << "Account not found!!!";
}

//Print all accounts
void Bank::viewlist(){
    if( !accounts.empty() ){
        std::cout << "\nAccount List:\n";
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
    int select = 0;

    while(select != 1 && select != 2){
        std::cout << "Search by:\n"
                    << "1. id\n"
                    << "2. name\n>";
        std::cin.clear();
        std::getline(std::cin, buff);
        std::stringstream(buff) >> select;
    }

    if(select == 1){
        std::cout << "Enter account ID (Number): ";
        std::cin.clear();
        std::getline(std::cin, buff);
        std::stringstream(buff) >> id;
    }
    else{
        std::cout << "Enter account name to search for: ";
        std::cin.clear();
        std::getline(std::cin, buff);
        for(int i = 0; i < accounts.size(); i++){
            if(buff == accounts[i].getName()){//Same name verification not implemented
                id = accounts[i].getID();
            }
        }
    }
    return id;
}

bool Bank::search_id(int id){
    for(int i = 0; i < accounts.size(); i++)
        if( id == accounts[i].getID() )
            return true;
    return false;
}

dob Bank::string2dob(std::string buffer){
    int date[3];
    char delimiter = '/';
    std::vector <std::string> strings;
    std::string tmp;
    std::stringstream stream(buffer);

    while( std::getline(stream, tmp, delimiter) )
        strings.push_back(tmp);

    for(int i = 0; i < strings.size(); i++)
        std::stringstream(strings[i]) >> date[i];

//    std::cout << "Date is: " << date[0] << '/' << date[1] << '/' << date[2] << '\n';

    return dob(date[0], date[1], date[2]);
}

void Bank::str2Account(std::string str){
    //Function convert string 2 accountholder object
    std::string buffer;
    int flag = 0;

    //Account atributtes
    int id;
    std::string name;
    dob dateofbirth;
    std::string citizenship_no;
    std::string address; 
    std::string phone;
    float money;
    acc_type account_type;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '#'){
            flag++;
            switch (flag){
                case 1:
                    std::stringstream(buffer) >> id;
                    break;
                case 2:
                    name = buffer;
                    break;
                case 3:
                    dateofbirth = string2dob(buffer);
                    break;
                case 4:
                    citizenship_no = buffer;
                    break;
                case 5:
                    address = buffer;
                    break;
                case 6:
                    phone = buffer;
                    break;
                case 7:
                    std::stringstream(buffer) >> money;
                    break;
                case 8:{
                    int tmp_acc;
                    std::stringstream(buffer) >> tmp_acc;
                    account_type = (acc_type)tmp_acc;
                    break;
                }
            }
            buffer.clear();
            continue;
        }
        buffer += str[i];
    }

    //Increment counter of accounts
    acc_number++;
    //Create object Account
    AccountHolder tmp(id, name, dateofbirth, citizenship_no, address, phone, money, account_type);
    accounts.push_back(tmp);
}