#pragma once

#include <string>

#include "VisibleElement.h"
#include "../Utils/BoundingBox.h"

class TextElement : public VisibleElement
{
public:
    void Render(RenderData& renderData, Vec2<float> parentPosition, Paint parentPaint) const;

    BoundingBox GetBoundingBox(Paint parentPaint) const;

public:

    std::string text = "";
};