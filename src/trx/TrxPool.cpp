//
// Created by Paulius on 2019-10-19.
//

#include "TrxPool.h"
#include <iostream>

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

void TrxPool::ValidateTrx(const std::vector<User> &pUser) {

    for (auto &obj: prTrx){
        if (!IsValidTrxByHash())
            std::cout << "Not valid hash" << std::endl;
        if (!IsValidTrxByUsers(pUser))
            std::cout << "Not valid user" << std::endl;
    }
}

bool TrxPool::IsValidTrxByHash() {
    return true;
}

bool TrxPool::IsValidTrxByUsers(const std::vector<User> &pUser) {
    return true;
}

//User TrxPool::GetUserByPublicKey(const std::string& pPublicKey, const std::vector<User> &pUser) {
//    for (auto &obj: pUser){
//        if (obj.GetPublicKey() == pPublicKey)
//            return obj;
//    }
//}
