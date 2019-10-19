//
// Created by Paulius on 2019-10-16.
//

#include "Random.h"

Random::Random() = default;

double Random::RandomNum(double &a, double &b) {
    static auto rng = RandomlySeededEngine();
    static std::uniform_real_distribution<double> distribution;

    distribution.param(std::uniform_real_distribution<double>::param_type{a, b});
    return distribution(rng);
}

int Random::RandomNumConst(const int &a, const int &b) {
    static auto rng = RandomlySeededEngine();
    static std::uniform_int_distribution<int> distribution;

    distribution.param(std::uniform_int_distribution<int>::param_type{a, b});
    return distribution(rng);
}

int Random::RandomNum(int a, int b) {
    static auto rng = RandomlySeededEngine();
    static std::uniform_int_distribution<int> distribution;

    distribution.param(std::uniform_int_distribution<int>::param_type{a, b});
    return distribution(rng);
}

double Random::RandomNum() {
    static auto rng = RandomlySeededEngine();
    static std::uniform_real_distribution<double> distribution;

    distribution.param(std::uniform_real_distribution<double>::param_type{0, 1});
    return distribution(rng);
}

char Random::RandomChar() {
    return RandomNum(65, 90);
}

std::string Random::RandomString(const int &length) {
    std::string randStr{};

    for (unsigned int i = 0; i < length; i++) {
        randStr += RandomChar();
    }
    return randStr;
}

std::string Random::RandomString(const int &prMinLength, const int &prMaxLength) {
    return RandomString(RandomNum(prMinLength, prMaxLength));
}

std::mt19937 Random::RandomlySeededEngine() {
    // create a seed sequence of several reasonably random values
    std::seed_seq seed_seq{(unsigned int) std::random_device{}(),
                           (unsigned int) std::chrono::system_clock::now().time_since_epoch().count(),
                           (unsigned int) std::random_device{}(),
                           (unsigned int) std::chrono::steady_clock::now().time_since_epoch().count(),
                           (unsigned int) std::random_device{}()};

    return std::mt19937(seed_seq); // note: the seed sequence provides a warm up sequence for the rng
}