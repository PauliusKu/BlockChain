//
// Created by Paulius on 2019-10-19.
//

#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H

#include "Block.h"
#include <vector>

class Blockchain {

public:
    std::string GetGenBlock();

    bool AddBlock(Block &block);

    void PrintBlockChainInfo();

private:
    std::vector<Block> prBlockChain;

    std::string prGenBlock;

    bool IsValid(Block &block);
};


#endif //BLOCKCHAIN_BLOCKCHAIN_H
