#include <iostream>
#include "user/UserGen.h"
#include "trx/TrxGen.h"
#include "core/Context.h"

int main() {
    Context ctx;
    std::cout << std::to_string(ctx.millisecondsGetTimestamp().count()) << std::endl;

    UserGen userGen;

    userGen.SetRulesDflt();
    userGen.GenAllRandom();
    std::vector<User> usersList = userGen.GetUsers();

    for(auto& item: usersList)
        std::cout << "Rez: " << item.GetAllInfo() << std::endl;

    TrxGen trxGen(usersList);
    trxGen.GenerateManyTrxRand(10000);

    std::vector<Trx> trxList = trxGen.GetTrxList();

    for(auto& item: trxList)
        std::cout << "Trx: " << item.PrintAll() << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}