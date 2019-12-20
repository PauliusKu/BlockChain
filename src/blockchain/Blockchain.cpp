//
// Created by Paulius on 2019-10-19.
//

#include <iostream>
#include "Blockchain.h"

std::string Blockchain::GetGenBlock() {
    return prGenBlock;
}

bool Blockchain::AddBlock(Block &block) {
    if (!IsValid(block))
        return false;

    prBlockChain.push_back(block);

    if (prBlockChain.size() > 1)
        prBlockChain.at(prBlockChain.size() - 1).SetPrevBlockHash(prBlockChain.at(prBlockChain.size() - 2).GetBlockHash());
    else prBlockChain.at(prBlockChain.size() - 1).SetPrevBlockHash("ABCDEFG");

    return true;
}

bool Blockchain::IsValid(Block &block) {
    return true;
}

void Blockchain::PrintBlockChainInfo() {
    for(const auto& b : prBlockChain)
        b.PrintBlockInfo();
}

void Blockchain::UpdateUsers(std::vector<User> &users) {
    for(auto& a : prBlockChain.at(prBlockChain.size() - 1).GetBlockTrx()){
        for(auto& b : users){
            if (a.GetPrFromUserPublicKey() == b.GetPublicKey()){
                std::cout << b.GetBalance() << std::endl;
                b.UpdateBalance(b.GetBalance() - a.GetPrTrxAmt());
                std::cout << "lalalala" << std::endl;
                std::cout << a.GetPrTrxAmt() << " " << b.GetBalance() << std::endl;
            }
        }
    }
}
