//
// Created by Paulius on 2019-10-17.
//

#ifndef BLOCKCHAIN_TRXGEN_H
#define BLOCKCHAIN_TRXGEN_H

#include <vector>
#include <string>
#include "Trx.h"
#include "../user/User.h"
#include "../core/Random.h"
#include "../core/Context.h"

class TrxGen {
public:
    TrxGen(std::vector<User> &pUserList);

    void GenerateManyTrxRand(unsigned int pNumToGen);

    std::vector<Trx> GetTrxList();

private:
    std::vector<Trx> trxList{};
    std::vector<User> userList{};
    Random rand;
    unsigned long prPrevTrxNum{};

    User GetRandUser();

    Trx GenerateOneTrxRand();

    void FillTwoUsersDiff(User &user1, User &user2);

    long int GetRandAmtForUser(User &pUser);

    unsigned long GetNextTrxNum();
};


#endif //BLOCKCHAIN_TRXGEN_H
