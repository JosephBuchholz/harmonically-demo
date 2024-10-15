#include "TextElement.h"

void TextElement::Render(RenderData& renderData, Vec2<float> parentPosition, Paint parentPaint) const
{
    std::string t = text;
    if (t == "")
        t = "e";
    renderData.AddText(Text(t, { position.x + parentPosition.x, position.y + parentPosition.y }, parentPaint));
}

BoundingBox TextElement::GetBoundingBox(Paint parentPaint) const
{
    //TextualElement::ModifyPaint(parentPaint);

    //BoundingBox bb = RenderMeasurement::GetTextBoundingBox(Text(text, 0.0f, 0.0f, parentPaint));
    BoundingBox bb;

    return bb;
}