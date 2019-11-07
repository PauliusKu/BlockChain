//
// Created by Paulius on 2019-10-19.
//

#ifndef BLOCKCHAIN_TRXPOOL_H
#define BLOCKCHAIN_TRXPOOL_H

#include <vector>
#include "Trx.h"
#include "../user/User.h"

class TrxPool {

public:
    void AddTrx(const Trx &pTrx);

    void AddManyTrx(const std::vector<Trx> &pTrx);

    void ValidateTrx(const std::vector<User> &pUser);

    std::vector<Trx> GetTrxFromBack(unsigned int pNumOfTrxToGet);

    std::string GetTrxPoolInfo();

private:
    std::vector<Trx> prTrx;
    std::vector<Trx> prRemovedTrx;

    bool IsValidTrxByHash();

    bool IsValidTrxByUsers(const std::vector<User> &pUser);

    //User GetUserByPublicKey(const std::string& pPublicKey, const std::vector<User> &pUser);
};


#endif //BLOCKCHAIN_TRXPOOL_H
