//
// Created by Paulius on 2019-10-19.
//

#ifndef BLOCKCHAIN_TRXPOOL_H
#define BLOCKCHAIN_TRXPOOL_H

#include <vector>
#include "Trx.h"

class TrxPool {

public:
    void AddTrx(const Trx &pTrx);

    void AddManyTrx(const std::vector<Trx> &pTrx);

    std::vector<Trx> GetTrxFromBack(unsigned int pNumOfTrxToGet);

    std::string GetTrxPoolInfo();

private:
    std::vector<Trx> prTrx;
};


#endif //BLOCKCHAIN_TRXPOOL_H
