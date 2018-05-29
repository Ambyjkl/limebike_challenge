/**
 * @brief Implementation for `ItemCounter` class.
 *
 * @file ItemCounter.cpp
 * @author Amby Balaji
 * @date 2018-05-28
 */

#include <algorithm>
#include <map>
#include <string>
#include <iterator>
#include <iostream>

#include "ItemCounter.h"

void ItemCounter::process_ride(const Ride* ride)
{
    // we use an ordered std::map for storing points so they would remain sorted
    m_points.insert({ ride, ride->start, false });
    m_points.insert({ ride, ride->end, true });
}

void ItemCounter::print_items_per_interval()
{
    // ordered map that stores items of current interval in alphabetical order
    std::map<const std::string, unsigned int> currentState;

    // we start iterating
    auto it = m_points.begin();
    // if empty, return
    if (it == m_points.end()) {
        return;
    }

    // we have n - 1 intervals if we have n time points
    // hence we run the loop accordingly, and stop one from the end
    for (; std::next(it) != m_points.end(); it++) {
        const auto& point = *it;

        // perform if check inside the loop to reduce code duplication
        // the compiler optimizes this away for us anyway
        for (const auto& [itemName, count] : point.ride->items) {
            const auto existing = currentState.find(itemName);
            if (!point.end) {
                // upsert into `currentState`
                if (existing == currentState.end()) {
                    currentState[itemName] = count;
                } else {
                    existing->second += count;
                }
            } else {
                // delete entry if the count will drop to zero
                if (existing->second == count) {
                    currentState.erase(existing);
                } else {
                    existing->second -= count;
                }
            }
        }

        // the full print format for each interval is:
        // HH:MM-HH:MM -> <item count> <item>(s), ...

        auto formatAndPrintTime = [](const unsigned int time) {
            // time is stored as minutes since the beginning of the day
            const unsigned int hours = time / 60;
            const unsigned int minutes = time % 60;

            // since the format is HH:MM, we may need to pad numbers with zeroes
            auto padAndPrint = [](const auto value) {
                if (value < 10) {
                    std::cout << "0";
                }
                std::cout << value;
            };
            padAndPrint(hours);
            std::cout << ":";
            padAndPrint(minutes);
        };

        // this section:
        // HH:MM-HH:MM ->
        formatAndPrintTime(point.time);
        std::cout << "-";
        formatAndPrintTime(std::next(it)->time);
        std::cout << " -> ";

        // this loop:
        // <item count> <item>(s), ...
        auto stateIt = currentState.begin();
        for (; stateIt != currentState.end(); stateIt++) {
            const auto& [itemName, count] = *stateIt;
            std::cout << count << " " << itemName;

            // rudimentary plural check, can be made more complex if needed
            if (count != 1) {
                std::cout << "s";
            }
            if (std::next(stateIt) != currentState.end()) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}
