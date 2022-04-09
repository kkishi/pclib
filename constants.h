#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <cstdint>
#include <limits>

// big = 2305843009213693951 = 2^61-1 ~= 2.3*10^18
const int64_t big = std::numeric_limits<int64_t>::max() / 4;

#endif  // CONSTANTS_H_
