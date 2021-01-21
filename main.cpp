#include "accountholder.hpp"

//Should implement a Bank class for printing all accounts info in the bank.
int main(){
    dob my_birth(19, 10, 2001);
    dob lizbirth(23, 06, 2001);
    AccountHolder uriegas(100, "Eduardo Uriegas", my_birth, 1930526, "Mirlos", "8341567800", 200, SAVING);
    AccountHolder lizbeth(101, "Lizbeth Pozos",lizbirth, 1930306, "Bambu", "8993554999", 300, SAVING);
    std::cout << uriegas << '\n' << lizbeth << std::endl;

    uriegas.edit("Los Mirlos 1122", "8394018745");
    std::cout << uriegas << std::endl;

    lizbeth.transact(100, WITHDRAW);

    std::cout << uriegas << '\n' << lizbeth << std::endl;
}
