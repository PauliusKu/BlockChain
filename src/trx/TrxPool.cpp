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

void TrxPool::ValidateAndRemoveTrx(const std::vector<User> &pUsers) {

    std::vector<Trx> remList;

    for (auto &trx: prTrx){
        if (IsValidTrxByHash(trx))
            std::cout << "Not valid hash" << std::endl;
        if (!IsValidTrxByUsers(trx, pUsers)){
            std::cout << "Not valid users: " << trx.GetPrFromUserPublicKey() << " " << trx.GetPrToUserPublicKey() << " " << trx.GetPrTrxAmt() << std::endl;
            remList.push_back(trx);
        }
    }

    RemoveTrx(remList);
}

bool TrxPool::IsValidTrxByHash(Trx &trx) {
    return Hash::HashString(trx.GetAll()) == trx.GetPrTrxHash();

}

bool TrxPool::IsValidTrxByUsers(const Trx &trx, const std::vector<User> &pUsers) {
    int valid = 0;

    for(const User &user: pUsers){
        if (user.GetPublicKey() == trx.GetPrFromUserPublicKey() && user.GetBalance() >= trx.GetPrTrxAmt())
            valid++;
        else if (user.GetPublicKey() == trx.GetPrToUserPublicKey())
            valid++;
    }

    return valid == 2;
}


std::vector<Trx> TrxPool::GetRandomTrx(unsigned int pNumOfTrxToGet) {
    std::vector<Trx> trx{};
    Random random;

    for (unsigned int i = 0; i < pNumOfTrxToGet; i++){
        trx.push_back(prTrx.at(random.RandomNum(0, prTrx.size() - 1)));
    }

    return trx;
}

void TrxPool::RemoveTrx(const std::vector<Trx> trx) {

}


//User TrxPool::GetUserByPublicKey(const std::string& pPublicKey, const std::vector<User> &pUser) {
//    for (auto &obj: pUser){
//        if (obj.GetPublicKey() == pPublicKey)
//            return obj;
//    }
//}
