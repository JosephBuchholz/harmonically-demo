#pragma once

#include <string>

#include "VisibleElement.h"
#include "../Utils/BoundingBox.h"

class TextElement : public VisibleElement
{
public:
    TextElement() {}
    TextElement(const std::string& text)
        : text(text) {}

    void Render(RenderData& renderData, Vec2<float> parentPosition, Paint parentPaint) const;

    BoundingBox GetBoundingBox(Paint parentPaint) const;

private:
    void ModifyPaint(Paint& paint) const;

public:
    std::string text = "";

    FontFamily fontFamily = FontFamily();
    FontSize fontSize = FontSize();
    FontStyle fontStyle = FontStyle::Normal;
    FontWeight fontWeight = FontWeight::Normal;

    Justify justify = Justify::Left;

    enum class TextAlign {
        None = 0, Left, Center, Right
    } align = TextAlign::Center;

    unsigned int linesThrough = 0;
    unsigned int overline = 0;
    unsigned int underline = 0;
};