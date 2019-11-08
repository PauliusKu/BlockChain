#include <iostream>
#include "user/UserGen.h"
#include "trx/TrxGen.h"
#include "core/Context.h"
#include "core/Hash.h"
#include "trx/TrxPool.h"
#include "blockchain/Block.h"
#include "blockchain/Blockchain.h"

int main() {

//    std::cout << std::to_string(Context::millisecondsGetTimestamp().count()) << std::endl;
//    std::cout << std::to_string(Context::millisecondsGetTimestamp().count()) << std::endl;

    UserGen userGen;

    userGen.SetRulesDflt();
    userGen.GenAllRandom();
    std::vector<User> usersList = userGen.GetUsers();

    for (auto &item: usersList)
        std::cout << "Rez: " << item.GetAllInfo() << std::endl;

    TrxGen trxGen(usersList);
    trxGen.GenerateManyTrxRand(1000);

    TrxPool trxPool;

    trxPool.AddManyTrx(trxGen.GetTrxList());
    std::cout << trxPool.GetTrxPoolInfo() << std::endl;
    std::vector<Trx> trxList = trxPool.GetRandomTrx(100);


    for (auto &item: trxList)
        std::cout << "Trx: " << item.GetAll() << std::endl;

    Blockchain blockchain;

    Block block(blockchain.GetGenBlock());
    block.Mine(trxList);

    if (block.DoesExists()){
        blockchain.AddBlock(block);
        blockchain.PrintBlockChainInfo();
    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}