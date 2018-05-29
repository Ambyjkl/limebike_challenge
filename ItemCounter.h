/**
 * @brief Header file for ItemCounter class
 *
 * @file ItemCounter.h
 * @author Amby Balaji
 * @date 2018-05-28
 */

#ifndef ITEMCOUNTER_H
#define ITEMCOUNTER_H

#include <set>

#include "Ride.h"

/**
 * @brief A class that counts items taken on `Ride`s by their type.
 */
class ItemCounter
{
    /**
     * @brief A struct that represents a point in time.
     *
     * Used to denote a the time when a `Ride` either starts or ends.
     */
    struct TimePoint
    {
        /**
         * @brief Pointer to the current `Ride`.
         */
        const Ride* ride;

        /**
         * @brief Time in minutes.
         */
        const unsigned int time;

        /**
         * @brief Whether or not the current `Ride` ends now.
         */
        const bool end;
    };

    /**
     * @brief A struct that compares two `TimePoint`s by their time.
     * Used for sorting in `m_points`.
     *
     * @see m_points
     */
    struct TimePointCmp
    {
        bool operator()(const TimePoint& tpt1, const TimePoint& tpt2) const {
            return tpt1.time < tpt2.time;
        }
    };

    /**
     * @brief An ordered set of the all `TimePoint`s.
     * These correspond to the start and end of the rides we are tracking.
     */
    std::set<TimePoint, TimePointCmp> m_points;

public:
    /**
     * @brief Creates `TimePoint`s for the ride passed in.
     * One for the start, another for the end.
     *
     * @param ride pointer to ride passed in.
     */
    void process_ride(const Ride* ride);

    /**
     * @brief Prints all items present per interval in the active rides
     */
    void print_items_per_interval();
};

#endif // ITEMCOUNTER_H
