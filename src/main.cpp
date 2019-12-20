#include <iostream>

#include "user/UserGen.h"
#include "trx/TrxGen.h"
#include "core/Timer.h"
#include "trx/TrxPool.h"
#include "blockchain/Block.h"
#include "blockchain/Blockchain.h"

int main() {
    std::string input;
    Blockchain blockchain;

    std::cout << "Program start" << std::endl;

    std::cout << "Starting users generation..." << std::endl;
    UserGen userGen;

    userGen.SetRulesDflt();
    userGen.GenAllRandom();
    std::vector<User> usersList = userGen.GetUsers();

    for (auto &item: usersList)
        std::cout << "Users: " << item.GetAllInfo() << std::endl;

    std::cout << "Users generated successfully!" << std::endl;
    std::cin >> input;

    do{
        std::cout << "Starting random transactions generation..." << std::endl;

        TrxGen trxGen(usersList);
        trxGen.GenerateManyTrxRand(1000);

        std::cout << "Transactions generated successfully!" << std::endl;
        std::cin >> input;
        std::cout << "Creating Transactions pool..." << std::endl;

        TrxPool trxPool;

        trxPool.AddManyTrx(trxGen.GetTrxList());
        trxPool.ValidateAndRemoveTrx(usersList);

        std::cout << "Validating Transaction pool..." << std::endl;
        std::cout << trxPool.GetTrxPoolInfo() << std::endl;

        std::cout << "Transaction poll was created!" << std::endl;
        std::cin >> input;
        std::cout << "Printing transaction pool...!" << std::endl;

        std::vector<Trx> trxList = trxPool.GetAllTrx();
        for (auto &item: trxList)
            std::cout << item.GetAllNice() << std::endl;

        std::cout << "Transaction poll was printed!" << std::endl;
        std::cin >> input;
        std::cout << "Starting generating final block..." << std::endl;

        Block finalBlock;
        double finalBlockGenDuration = 9999999;

        for (unsigned int i = 0; i < 5; i++){
            Timer timer = Timer();
            std::vector<Trx> trxList1 = trxPool.GetRandomTrx(10);

            Block block(blockchain.GetGenBlock());
            block.Mine(trxList1);

            double elapsedTime = timer.GetElapsed();
            std::cout << "Elapsed time " << i << ": " << elapsedTime << std::endl;

            if (elapsedTime < finalBlockGenDuration){
                finalBlockGenDuration = elapsedTime;
                finalBlock = block;
            }
        }

        std::cout << "Final block was generated!" << std::endl;
        std::cin >> input;
        std::cout << "Adding new block to Blockchain..." << std::endl;

        if (finalBlock.DoesExists()){
            std::cout << "----------------------------------------------" << std::endl;
            std::cout << "fastest is " << finalBlockGenDuration << std::endl;
            blockchain.AddBlock(finalBlock);
            blockchain.UpdateUsers(usersList);
            blockchain.PrintBlockChainInfo();
        }

        std::cout << "New block was added!" << std::endl;
        std::cout << "Input leave if you want to end program." << std::endl;
        std::cin >> input;
    }while(input != "leave");

    for (auto &item: usersList)
        std::cout << "Users: " << item.GetAllInfo() << std::endl;

    std::cout << "End of the program!" << std::endl;
    return 0;
}