cmake_minimum_required(VERSION 3.15)
project(BlockChain)

set(CMAKE_CXX_STANDARD 17)

add_executable(BlockChain src/main.cpp src/user/User.cpp src/user/User.h src/user/UserGen.cpp src/user/UserGen.h src/core/Random.h src/core/Random.cpp src/trx/Trx.h src/trx/TrxGen.cpp src/trx/TrxGen.h src/core/Timer.h src/core/Context.h src/core/Hash.cpp src/core/Hash.h src/blockchain/Block.cpp src/blockchain/Block.h src/trx/TrxPool.cpp src/trx/TrxPool.h src/trx/Trx.cpp src/blockchain/Mine.cpp src/blockchain/Mine.h src/blockchain/Blockchain.cpp src/blockchain/Blockchain.h)