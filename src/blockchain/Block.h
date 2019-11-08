//
// Created by Paulius on 2019-10-18.
//

#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include <string>
#include <vector>
#include "../core/Context.h"
#include "../core/Hash.h"
#include "../trx/Trx.h"

class Block {
public:
    explicit Block(std::string &pPrevBlockHash);

    explicit Block(std::string pPrevBlockHash);

    void Mine(std::vector<Trx>& pTrx);

    void SetHash();

    bool DoesExists();

    void PrintBlockInfo() const;

private:

    std::string prBlockHash{};
    std::string prPrevBlockHash{};
    std::string prTimeStamp{};
    std::string prMerkelRootHash{};

    unsigned int prVersion{};
    unsigned long prNonce{};
    unsigned int prDifficultyTarget{};

    std::vector<Trx> prTrx;
    bool prExists{};

    void SetPrTrx(std::vector<Trx>& pTrx);
    std::string CalcMerkleRoot();
    bool OkWithDiffTarget();
};


#endif //BLOCKCHAIN_BLOCK_H
