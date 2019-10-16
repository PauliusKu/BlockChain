//
// Created by Paulius on 2019-10-16.
//

#ifndef BLOCKCHAIN_USERGEN_H
#define BLOCKCHAIN_USERGEN_H

#include "User.h"
#include "vector"
#include "../core/Random.h"

class UserGen {

public:
    UserGen();

    void SetRulesDflt();

    void GenAllRandom();

    std::vector<User> GetUsers();

private:
    struct Params {
        unsigned long int prNumOfClientsToGen;
        unsigned long int prMinNameLength;
        unsigned long int prMaxNameLength;
        unsigned long int prPublicKeyLength;
        int prMaxBalance;
        int prMinBalance;
    };

    Params params;
    std::vector<User> users;

};
#endif //BLOCKCHAIN_USERGEN_H
