#include "TextElement.h"

#include "../Rendering/RenderMeasurement.h"

void TextElement::Render(RenderData& renderData, Vec2<float> parentPosition, Paint parentPaint) const
{
    ModifyPaint(parentPaint);

    renderData.AddText(RenderableText(text, { m_Position.x + parentPosition.x, m_Position.y + parentPosition.y }, parentPaint));
}


BoundingBox TextElement::GetBoundingBox(Paint parentPaint) const
{
    ModifyPaint(parentPaint);

    BoundingBox bb = RenderMeasurement::GetTextBoundingBox(RenderableText(text, { 0.0f, 0.0f }, parentPaint));

    return bb;
}

void TextElement::ModifyPaint(Paint& paint) const
{
    paint.textSize = fontSize.size;
    paint.isItalic = (fontStyle == FontStyle::Italic);
    paint.isBold = (fontWeight == FontWeight::Bold);

    switch (align)
    {
        case TextAlign::Left: paint.align = Paint::Align::Left; break;
        case TextAlign::Center: paint.align = Paint::Align::Center; break;
        case TextAlign::Right: paint.align = Paint::Align::Right; break;
        default: break;
    }
}