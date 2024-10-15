#pragma once

#include "Text.h"
#include "../Utils/BoundingBox.h"

/**
 * This class handles the measuring of different renderable elements, such as SMuFL glyphs or text.
 */
class RenderMeasurement
{
private:
    RenderMeasurement() {}

public:
    static BoundingBox GetTextBoundingBox(const Text& text);
};
