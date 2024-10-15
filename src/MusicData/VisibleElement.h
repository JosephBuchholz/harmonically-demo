#pragma once

#include "Types.h"
#include "../Utils/Vec2.h"
#include "../Debugging/Debug.h"
#include "../Rendering/RenderData.h"

/**
 * This class represents a element that is visible.
 */
class VisibleElement
{

public:
    VisibleElement() {}
    VisibleElement(Vec2<float> position)
        : position(position) {}

public:
    // Relative to the parent element
    Vec2<float> position = { 0.0f, 0.0f };
};