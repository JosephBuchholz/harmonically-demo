#pragma once

#include "RenderableText.h"
#include "../Utils/BoundingBox.h"

/**
 * This class handles the measuring of different renderable elements, such as text (currently only has support for text).
 */
class RenderMeasurement
{
private:
    RenderMeasurement() {}

public:
    static BoundingBox GetTextBoundingBox(const RenderableText& text);
};
