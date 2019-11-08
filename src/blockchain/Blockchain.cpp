//
// Created by Paulius on 2019-10-19.
//

#include "Blockchain.h"

std::string Blockchain::GetGenBlock() {
    return prGenBlock;
}

bool Blockchain::AddBlock(Block &block) {
    if (!IsValid(block))
        return false;

    prBlockChain.push_back(block);
    return true;
}

bool Blockchain::IsValid(Block &block) {
    return true;
}

void Blockchain::PrintBlockChainInfo() {
    for(const auto& b : prBlockChain)
        b.PrintBlockInfo();
}
