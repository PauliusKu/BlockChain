//
// Created by Paulius on 2019-10-17.
//

#include "TrxGen.h"
#include <iostream>

TrxGen::TrxGen(std::vector<User> &pUserList) {
    userList = pUserList;
    prPrevTrxNum = 0;
}

void TrxGen::GenerateManyTrxRand(unsigned int pNumToGen) {
    for (unsigned int i = 0; i < pNumToGen; i++){
        trxList.push_back(GenerateOneTrxRand());
    }
}

Trx TrxGen::GenerateOneTrxRand(){
    Trx trx;
    User userFrom{};
    User userTo{};
    FillTwoUsersDiff(userFrom, userTo);

    trx.trxNum = GetNextTrxNum();
    trx.fromUserName = userFrom.GetName();
    trx.toUserName = userTo.GetName();
    trx.trxAmt = GetRandAmtForUser(userFrom);

    return trx;
}

void TrxGen::FillTwoUsersDiff(User &user1, User &user2){
    do{
        user1 = GetRandUser();
        user2 = GetRandUser();
    } while (user1.GetName() == user2.GetName());
}

User TrxGen::GetRandUser() {
    return userList[rand.RandomNum(0, userList.size() - 1)];
}

long int TrxGen::GetRandAmtForUser(User &pUser){
    return rand.RandomNum(0, pUser.GetBalance());
}

unsigned long TrxGen::GetNextTrxNum(){
    return ++prPrevTrxNum;
}

std::vector<Trx> TrxGen::GetTrxList() {
    return trxList;
}