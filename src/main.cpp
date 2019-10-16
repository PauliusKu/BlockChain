#include <iostream>
#include "user/UserGen.h"

int main() {
    UserGen userGen;

    userGen.SetRulesDflt();
    userGen.GenAllRandom();
    std::vector<User> usersList = userGen.GetUsers();

    for(auto& item: usersList)
        std::cout << "Rez: " << item.GetAllInfo() << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}