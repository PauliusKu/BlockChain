//
// Created by Paulius on 2019-10-16.
//

#include "UserGen.h"

UserGen::UserGen() = default;

void UserGen::SetRulesDflt() {
    params.prNumOfClientsToGen = 1000;
    params.prMinNameLength = 10;
    params.prMaxNameLength = 20;
    params.prPublicKeyLength = 24;
    params.prMaxBalance = 0;
    params.prMinBalance = 100;
}

void UserGen::GenAllRandom() {
    Random random;

    for (unsigned long int i = 0; i < params.prNumOfClientsToGen; i++) {
        User user(random.RandomString(params.prMinNameLength, params.prMaxNameLength),
                  random.RandomString(params.prPublicKeyLength),
                  random.RandomNum(params.prMaxBalance, params.prMinBalance));

        users.push_back(user);
    }
//    std::cout << params.prNumOfClientsToGen << std::endl;
//    for (unsigned long int i = 0; i < params.prNumOfClientsToGen; i++){
//        std::cout << i << std::endl;
////        User user(random.RandomString(params.prMinNameLength, params.prMaxNameLength),
////                  random.RandomString(params.prPublicKeyLength),
////                  random.RandomNum(params.prMaxBalance, params.prMinBalance));
//        std::cout << params.prNumOfClientsToGen << std::endl;
//        users.push_back(User());
//    }
}

std::vector<User> UserGen::GetUsers() {
    return users;
}
