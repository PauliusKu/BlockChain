//
// Created by Paulius on 2019-10-17.
//

#ifndef BLOCKCHAIN_TRX_H
#define BLOCKCHAIN_TRX_H

#include <string>
#include "../core/Hash.h"

class Trx {
public:
    std::string GetAll() const;

private:
    unsigned long prTrxNum;
    std::string prToUserPublicKey;
    std::string prFromUserPublicKey;
    long int prTrxAmt;
    std::string prTimestamp;
    std::string prTrxHash;

public:
    void CalcPrTrxHash();

    const std::string &GetPrTrxHash() const;

    unsigned long GetPrTrxNum() const;

    void SetPrTrxNum(unsigned long prTrxNum);

    const std::string &GetPrToUserPublicKey() const;

    void SetPrToUserPublicKey(const std::string &prToUserPublicKey);

    const std::string &GetPrFromUserPublicKey() const;

    void SetPrFromUserPublicKey(const std::string &prFromUserPublicKey);

    long GetPrTrxAmt() const;

    void SetPrTrxAmt(long prTrxAmt);

    const std::string &GetPrTimestamp() const;

    void SetPrTimestamp(const std::string &prTimestamp);
};


#endif //BLOCKCHAIN_TRX_H
