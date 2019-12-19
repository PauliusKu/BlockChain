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
    return "trx size: " + std::to_string(prTrx.size());
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

std::vector<Trx> TrxPool::GetRandomTrx(unsigned int pNumOfTrxToGet) {
    std::vector<Trx> trx{};
    Random random;

    for (unsigned int i = 0; i < pNumOfTrxToGet; i++){
        trx.push_back(prTrx.at(random.RandomNum(0, prTrx.size() - 1)));
    }

    return trx;
}


//User TrxPool::GetUserByPublicKey(const std::string& pPublicKey, const std::vector<User> &pUser) {
//    for (auto &obj: pUser){
//        if (obj.GetPublicKey() == pPublicKey)
//            return obj;
//    }
//}
