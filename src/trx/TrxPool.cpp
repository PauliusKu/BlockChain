//
// Created by Paulius on 2019-10-19.
//

#include "TrxPool.h"

void TrxPool::AddTrx(const Trx &pTrx) {
    prTrx.push_back(pTrx);
}

std::vector<Trx> TrxPool::GetTrxFromBack(unsigned int pNumOfTrxToGet) {
    if (pNumOfTrxToGet <= prTrx.size())
        return std::vector<Trx>(prTrx.end() - pNumOfTrxToGet, prTrx.end());
    return std::vector<Trx>{};
}

void TrxPool::AddManyTrx(const std::vector<Trx> &pTrx) {
    prTrx = pTrx;
}

std::string TrxPool::GetTrxPoolInfo() {
    return std::to_string(prTrx.size());
}

