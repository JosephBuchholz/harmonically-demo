#include "RenderMeasurement.h"

#include "Renderer.h"

BoundingBox RenderMeasurement::GetTextBoundingBox(const RenderableText& text)
{
    BoundingBox boundingBox = BoundingBox();

    Renderer& renderer = Renderer::GetInstance();

    boundingBox = renderer.MeasureText(text.text, text.paint);

    return boundingBox;
}