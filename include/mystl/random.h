//
// Created by ivan on 5/22/15.
//

#ifndef _MYSTL_RANDOM_H
#define _MYSTL_RANDOM_H

#include <limits>

namespace mystd {

    template<typename T>
    T random(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max()) {
        return rand() * (max - min) + min;
    }
}


#endif //_MYSTL_RANDOM_H
