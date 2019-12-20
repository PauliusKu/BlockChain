//
// Created by Paulius on 2019-10-19.
//

#ifndef BLOCKCHAIN_TRXPOOL_H
#define BLOCKCHAIN_TRXPOOL_H

#include <vector>
#include "Trx.h"
#include "../user/User.h"
#include "../core/Hash.h"
#include "../core/Random.h"

class TrxPool {

public:
    void AddTrx(const Trx &pTrx);

    void AddManyTrx(const std::vector<Trx> &pTrx);

    void ValidateAndRemoveTrx(const std::vector<User> &pUsers);

    std::vector<Trx> GetTrxFromBack(unsigned int pNumOfTrxToGet);

    std::vector<Trx> GetRandomTrx(unsigned int pNumOfTrxToGet);

    std::vector<Trx> GetAllTrx();

    std::string GetTrxPoolInfo();

private:
    std::vector<Trx> prTrx;
    std::vector<Trx> prRemovedTrx;

    bool IsValidTrxByHash(Trx &trx);

    bool IsValidTrxByUsers(const Trx &trx, const std::vector<User> &pUsers);

    void RemoveTrx(std::vector<Trx> trx);

    //User GetUserByPublicKey(const std::string& pPublicKey, const std::vector<User> &pUser);
};


#endif //BLOCKCHAIN_TRXPOOL_H
