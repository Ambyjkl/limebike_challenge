/**
 * @brief Implementation for `Ride` class.
 *
 * @file Ride.cpp
 * @author Amby Balaji
 * @date 2018-05-28
 */

#include <cassert>

#include "Ride.h"

Ride::Ride(
    const unsigned int start,
    const unsigned int end,
    const std::unordered_map<std::string, unsigned int>& items
)
    :
    start(start),
    end(end),
    items(items)
{
    assert(end > start);
}
