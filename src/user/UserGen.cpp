//
// Created by Paulius on 2019-10-16.
//

#include "UserGen.h"

UserGen::UserGen() = default;

void UserGen::SetRulesDflt() {
    params.prNumOfClientsToGen = 1000;
    params.prMinNameLength = 10;
    params.prMaxNameLength = 20;
    params.prPublicKeyLength = 48;
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
}

std::vector<User> UserGen::GetUsers() {
    return users;
}
