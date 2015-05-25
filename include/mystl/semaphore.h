//
// Created by ivan on 5/22/15.
//

#ifndef _MYSTL_SEMAPHORE_H
#define _MYSTL_SEMAPHORE_H

#include <condition_variable>
#include <vector>

namespace mystd {
    class semaphore {
    public:
        semaphore(int count = 0) : count_(count) { }

        inline void notify() {
            std::unique_lock<std::mutex> lock(mtx_);
            count_++;

            cv_.notify_one();
        }

        inline void wait() {
            std::unique_lock<std::mutex> lock(mtx_);

            while (count_ == 0) {
                cv_.wait(lock);
            }
            count_--;
        }

    private:
        std::mutex mtx_;
        std::condition_variable cv_;
        int count_;
    };


}


#endif //_MYSTL_SEMAPHORE_H
