//
// Created by Paulius on 2019-10-12.
//

#include "User.h"

User::User() {
    prName = "fcbfcb";
    prPublicKey = "dsafffdsaf";
    prBalance = 100;
}

User::User(std::string &pName, std::string &pPublicKey, long int pBalance) {
    prName = pName;
    prPublicKey = pPublicKey;
    prBalance = pBalance;
}

User::User(std::string pName, std::string pPublicKey, long int pBalance) {
    prName = pName;
    prPublicKey = pPublicKey;
    prBalance = pBalance;
}

void User::GetAllInfo(std::string &pName, std::string &pPublicKey, long int& pBalance) {
    pName = prName;
    pPublicKey = prPublicKey;
    pBalance = prBalance;
}

std::string User::GetAllInfo() {
    return prName + " " + prPublicKey + " " + std::to_string(prBalance);
}

void User::UpdateBalance(long int &pBalance) {
    prBalance = pBalance;
}