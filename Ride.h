/**
 * @brief Header file for `Ride` class.
 *
 * @file Ride.h
 * @author Amby Balaji
 * @date 2018-05-28
 */

#ifndef RIDE_H
#define RIDE_H
#include <unordered_map>
#include <string>

/**
 * A struct that represents a ride.
 */
struct Ride
{
    /**
     * @brief Start time of ride as minutes since the beginning of the day.
     * Included in the interval.
     */
    const unsigned int start;

    /**
     * @brief End time of ride as minutes since the beginning of the day.
     * Excluded from the interval. Must be greater than `start` for this purpose
     */
    const unsigned int end;

    /**
     * @brief A key-value dictionary storing items by name and their count.
     */
    const std::unordered_map<std::string, unsigned int> items;

    /**
     * @brief Constructor.
     * Asserts that the end time is greater than the start time.
     */
    Ride(
        const unsigned int start,
        const unsigned int end,
        const std::unordered_map<std::string, unsigned int>& items
    );
};

#endif // RIDE_H
