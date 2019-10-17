//
// Created by Paulius on 2019-10-17.
//

#ifndef BLOCKCHAIN_TRX_H
#define BLOCKCHAIN_TRX_H

#include <string>

class Trx {
public:
    unsigned long trxNum;
    std::string toUserName;
    std::string fromUserName;
    long int trxAmt;
    std::string PrintAll(){
        return std::to_string(trxNum) + " " + toUserName + " " + fromUserName + " " + std::to_string(trxAmt);
    }
};


#endif //BLOCKCHAIN_TRX_H
