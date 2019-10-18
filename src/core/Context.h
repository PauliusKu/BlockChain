//
// Created by Paulius on 2019-10-17.
//

#ifndef BLOCKCHAIN_CONTEXT_H
#define BLOCKCHAIN_CONTEXT_H

#include <chrono>

class Context {
public:
    static inline std::chrono::milliseconds millisecondsGetTimestamp(){
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    }
};


#endif //BLOCKCHAIN_CONTEXT_H
