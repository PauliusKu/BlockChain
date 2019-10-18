//
// Created by Paulius on 2019-10-18.
//

#include "Hash.h"

std::string Hash::HashString(const std::string& pInp1){
    std::vector<std::string> blocks = MakeBlocks(pInp1);
    std::string seed = "FCB469D2";

    for(auto& value: blocks){
        seed = HashFunc(value, seed);
    }
    return seed;
}

std::vector<std::string> Hash::MakeBlocks(const std::string& pInp1){
    std::vector<std::string> blocks;
    for(unsigned long i = 0; i < pInp1.size(); i++)
        blocks.push_back(pInp1.substr(i, 8));
    return blocks;
}

std::string Hash::HashFunc(std::string pBlock){
    unsigned int hash = 0xAAAAAAAA;
    unsigned long i = 0;

    for (i = 0; i < pBlock.size(); ++pBlock[i], ++i){
        if ((i & 1u) == 0)
            hash ^= hash << 7u ^ (pBlock[i]) * (hash >> 3u);
        else hash ^= ~((hash << 11u) + ((pBlock[i] + 0u) ^ (hash >> 5u)));
    }

    return HexToString(hash);
}

std::string Hash::HashFunc96(std::string& pBlock1, std::string& pBlock2){
    std::string pBlockSum = HashFunc(pBlock1 + pBlock2);
    pBlock1 = HashFunc(pBlock1);
    pBlock2 = HashFunc(pBlock2);
    pBlock1 = HashFunc(pBlock1 + pBlock2);
    pBlock2 = HashFunc(pBlock1 + pBlockSum);

    return pBlockSum + pBlock1 + pBlock2;
}

std::string Hash::HashFunc(std::string& pBlock1, std::string& pBlock2){
    return HashFunc96(pBlock1, pBlock2);
}

std::string Hash::HexToString(unsigned int hex){
    std::string str {"00000000"};
    int itr = 0;

    do{
        str[itr] = "0123456789ABCDEF"[hex % 16];
        hex >>= 4u;
        itr++;
    } while(hex);

    return str;
}