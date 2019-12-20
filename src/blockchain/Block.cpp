//
// Created by Paulius on 2019-10-18.
//

#include "Block.h"
#include <iostream>
#include <utility>

Block::Block(std::string &pPrevBlockHash) {
    prPrevBlockHash = pPrevBlockHash;
    prTimeStamp = Context::GetTimestampString();
    prVersion = Context::GetVersion();
    prMerkelRootHash = "";
    prDifficultyTarget = Context::GetDiffTarget();
}

Block::Block(std::string pPrevBlockHash) {
    prPrevBlockHash = std::move(pPrevBlockHash);
    prTimeStamp = Context::GetTimestampString();
    prVersion = Context::GetVersion();
    prMerkelRootHash = "";
    prDifficultyTarget = Context::GetDiffTarget();
}

void Block::Mine(std::vector<Trx>& pTrx) {
    SetPrTrx(pTrx);
    prMerkelRootHash = CalcMerkleRoot();

    for (prNonce = 0; prNonce < Context::GetMaxNonce(); prNonce++){
        SetHash();

        if (OkWithDiffTarget()){
            prExists = true;
            break;
        }
    }
}

void Block::SetPrTrx(std::vector<Trx> &pTrx) {
    prTrx = pTrx;
}

void Block::SetHash() {
    prBlockHash = Hash::HashString(prMerkelRootHash + prPrevBlockHash + std::to_string(prNonce));
}

std::string Block::CalcMerkleRoot() {
    std::vector<std::string> merkleTree;
    for (const auto& t : prTrx)
        merkleTree.push_back(t.GetPrTrxHash());

    while (merkleTree.size() > 1){
        if (merkleTree.size()%2 != 0)
            merkleTree.emplace_back("");

        std::vector<std::string> newMerkleTree;
        for (unsigned long i = 0; i < merkleTree.size(); i += 2){
            std::string first = merkleTree.at(i);
            std::string second = merkleTree.at(i+1);

            newMerkleTree.push_back(Hash::HashString(first + second));
        }
        merkleTree = newMerkleTree;
    }
    return merkleTree.at(0);
}

bool Block::OkWithDiffTarget() {
    char diffTargSymb = '0';

    for (unsigned long i = 0; i < prDifficultyTarget; i++){

        if (prBlockHash.at(i) != diffTargSymb)
            return false;
    }

    return true;
}

bool Block::DoesExists() {
    return prExists;
}

void Block::PrintBlockInfo() const {
    std::cout << "Version: " << prVersion << " DiffTarget: " << prDifficultyTarget << " TimeStamp: " << prTimeStamp << " Nonce: " << prNonce << " Exists: " << prExists << std::endl;
    std::cout << "BlockHash: " << prBlockHash << " PrevBlockHash: " << prPrevBlockHash << " MerkelRootHash:" << prMerkelRootHash << std::endl;
    for(const auto& t : prTrx){
        std::cout << t.GetAllNice() << std::endl;
    }

}

std::string Block::GetBlockHash() {
    return prBlockHash;
}

void Block::SetPrevBlockHash(std::string pPrevBlockHash) {
    prPrevBlockHash = pPrevBlockHash;
}

std::vector<Trx> Block::GetBlockTrx() {
    return prTrx;
}

Block::Block() = default;



