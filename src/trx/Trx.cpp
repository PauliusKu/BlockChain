//
// Created by Paulius on 2019-10-19.
//

#include "Trx.h"

std::string Trx::GetAll() const {
    return std::to_string(prTrxNum) + " " + prToUserPublicKey + " " + prFromUserPublicKey + " " +
           std::to_string(prTrxAmt) + " " + prTimestamp + " " + prTrxHash;
}

unsigned long Trx::GetPrTrxNum() const {
    return prTrxNum;
}

void Trx::SetPrTrxNum(unsigned long pTrxNum) {
    Trx::prTrxNum = pTrxNum;
}

const std::string &Trx::GetPrToUserPublicKey() const {
    return prToUserPublicKey;
}

void Trx::SetPrToUserPublicKey(const std::string &pToUserPublicKey) {
    Trx::prToUserPublicKey = pToUserPublicKey;
}

const std::string &Trx::GetPrFromUserPublicKey() const {
    return prFromUserPublicKey;
}

void Trx::SetPrFromUserPublicKey(const std::string &pFromUserPublicKey) {
    Trx::prFromUserPublicKey = pFromUserPublicKey;
}

long Trx::GetPrTrxAmt() const {
    return prTrxAmt;
}

void Trx::SetPrTrxAmt(long pTrxAmt) {
    Trx::prTrxAmt = pTrxAmt;
}

const std::string &Trx::GetPrTimestamp() const {
    return prTimestamp;
}

void Trx::SetPrTimestamp(const std::string &pTimestamp) {
    Trx::prTimestamp = pTimestamp;
}

const std::string &Trx::GetPrTrxHash() const {
    return prTrxHash;
}

void Trx::CalcPrTrxHash() {
    prTrxHash = Hash::HashString(GetAll());
}
