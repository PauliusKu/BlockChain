//
// Created by Paulius on 2019-10-17.
//

#ifndef BLOCKCHAIN_CONTEXT_H
#define BLOCKCHAIN_CONTEXT_H

#include <chrono>
#include <string>

const unsigned int VERSION = 1;
const unsigned long NONCE = 10000000;
const unsigned long DIFF_TARGET = 4;

class Context {
public:
    static inline unsigned int GetVersion() {
        return VERSION;
    }

    static inline std::chrono::microseconds GetTimestampMicroseconds() {
        return std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::system_clock::now().time_since_epoch());
    }

    static inline std::string GetTimestampString() {
        return std::to_string(GetTimestampMicroseconds().count());
    }

    static inline unsigned long GetMaxNonce(){
        return NONCE;
    }

    static inline unsigned long GetDiffTarget(){
        return DIFF_TARGET;
    }
};


#endif //BLOCKCHAIN_CONTEXT_H
