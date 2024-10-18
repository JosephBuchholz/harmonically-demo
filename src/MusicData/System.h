#pragma once

#include <unordered_map>

#include "../Utils/Vec2.h"

/**
 * A structure that stores data for a sheet music system (a system is one line of music).
 */
struct System
{
    int beginningMeasureIndex = 0; // The index of the first measure in this system
    int endingMeasureIndex = 0; // The index of the last measure in this system

    // The position relative to the page
    Vec2<float> position = { 0.0f, 0.0f };
};
