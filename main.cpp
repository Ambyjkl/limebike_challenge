/**
 * @brief Example usage for `ItemCounter` and `Ride` classes
 *
 * @file main.cpp
 * @author Amby Balaji
 * @date 2018-05-28
 */

#include <iostream>

#include "ItemCounter.h"
#include "Ride.h"


int main() {
    ItemCounter counter;

    // nice declarative initializer list that almost looks like JSON
    const Ride* rides[] = {
        new Ride(420, 450, {
            { "apple", 2 },
            { "brownie", 1 }
        }),
        new Ride(430, 480, {
            { "apple", 1 },
            { "carrot", 3 }
        }),
        new Ride(440, 465, {
            { "apple", 1 },
            { "brownie", 2 },
            { "diamond", 4 }
        })
    };

    for (const auto ride : rides) {
        counter.process_ride(ride);
    }

    counter.print_items_per_interval();

    // since it's not the `ItemCounter`'s business to free the Ride objects
    for (const auto ride : rides) {
        delete ride;
    }
    return 0;
}
