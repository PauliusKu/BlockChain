//
// Created by Paulius on 2019-10-17.
//

#ifndef BLOCKCHAIN_TIMER_H
#define BLOCKCHAIN_TIMER_H

#include <chrono>

class Timer {
public:
    typedef std::chrono::high_resolution_clock h_r_clock;
    typedef std::chrono::duration<double> double_duration;
private:
    std::chrono::time_point<h_r_clock> start;
public:
    Timer() :start(h_r_clock::now()){}
    inline void Reset() {
        start = h_r_clock::now();
    }
    [[nodiscard]] inline double GetElapsed() const {
        return double_duration(h_r_clock::now() - start).count();
    }
};

#endif //BLOCKCHAIN_TIMER_H
