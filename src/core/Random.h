//
// Created by Paulius on 2019-10-16.
//

#ifndef BLOCKCHAIN_RANDOM_H
#define BLOCKCHAIN_RANDOM_H

#include <random>
#include <chrono>
#include <string>

class Random {
public:
    Random();

    double RandomNum(double &a, double &b);

    int RandomNumConst(const int &a, const int &b);

    int RandomNum(int a, int b);

    double RandomNum();

    char RandomChar();

    std::string RandomString(const int &length);

    std::string RandomString(const int &prMinLength, const int &prMaxLength);

private:
    static std::mt19937 RandomlySeededEngine();

};


#endif //BLOCKCHAIN_RANDOM_H
