//
// Created by Paulius on 2019-10-18.
//

#ifndef BLOCKCHAIN_HASH_H
#define BLOCKCHAIN_HASH_H

#include <vector>
#include <string>

class Hash {
public:
    static std::string HashString(const std::string &pInp1);

private:
    static std::vector<std::string> MakeBlocks(const std::string &pInp1);

    static std::string HashFunc(std::string pBlock);

    static std::string HashFunc192(std::string &pBlock1, std::string &pBlock2);

    static std::string HashFunc(std::string &pBlock1, std::string &pBlock2);

    static std::string HexToString(unsigned int hex);
};


#endif //BLOCKCHAIN_HASH_H
