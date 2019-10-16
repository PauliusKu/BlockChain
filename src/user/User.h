//
// Created by Paulius on 2019-10-12.
//

#ifndef BLOCKCHAIN_USER_H
#define BLOCKCHAIN_USER_H

#include <string>

class User {
public:
    User();
    User(std::string& pName, std::string& pPublicKey, long int pBalance);
    User(std::string pName, std::string pPublicKey, long int pBalance);
    void GetAllInfo(std::string& pName, std::string& pPublicKey, long int& pBalance);
    std::string GetAllInfo();
    void UpdateBalance(long int& pBalance);

private:
    std::string prName;
    std::string prPublicKey;
    long int prBalance;
};


#endif //BLOCKCHAIN_USER_H
