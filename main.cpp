#include "accountholder.hpp"

int main(){
    dob my_birth(19, 10, 2001);
    AccountHolder yo("Eduardo Uriegas", my_birth, 1930526, "Mirlos", "8341567800", 200);
    std::cout << yo;
}
