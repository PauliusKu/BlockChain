#include <iostream>

#include "user/UserGen.h"
#include "trx/TrxGen.h"
#include "core/Timer.h"
#include "trx/TrxPool.h"
#include "blockchain/Block.h"
#include "blockchain/Blockchain.h"

int main() {
    UserGen userGen;

    userGen.SetRulesDflt();
    userGen.GenAllRandom();
    std::vector<User> usersList = userGen.GetUsers();

    for (auto &item: usersList)
        std::cout << "Users: " << item.GetAllInfo() << std::endl;

    TrxGen trxGen(usersList);
    trxGen.GenerateManyTrxRand(100);

    TrxPool trxPool;

    trxPool.AddManyTrx(trxGen.GetTrxList());
    std::cout << trxPool.GetTrxPoolInfo() << std::endl;
    trxPool.ValidateAndRemoveTrx(usersList);

    Block finalBlock;
    double finalBlockGenDuration = 9999999;
    Blockchain blockchain;

    Timer performance = Timer();

    for (unsigned int i = 0; i < 50; i++){
        Timer timer = Timer();
        std::vector<Trx> trxList = trxPool.GetRandomTrx(10);

        Block block(blockchain.GetGenBlock());
        block.Mine(trxList);

        double elapsedTime = timer.GetElapsed();
        std::cout << "Elapsed time " << i << ": " << elapsedTime << std::endl;

        if (elapsedTime < finalBlockGenDuration){
            finalBlockGenDuration = elapsedTime;
            finalBlock = block;
        }
     }


    std::cout << "Perf: " << performance.GetElapsed() << std::endl;

    if (finalBlock.DoesExists()){
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << "fastest is " << finalBlockGenDuration << std::endl;
        blockchain.AddBlock(finalBlock);
        blockchain.PrintBlockChainInfo();
    }

    std::cout << "End of the program!" << std::endl;
    return 0;
}