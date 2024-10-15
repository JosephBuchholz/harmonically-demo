#include "RenderMeasurement.h"

#include "Rendering/Renderer.h"

BoundingBox RenderMeasurement::GetTextBoundingBox(const Text& text)
{
    BoundingBox boundingBox = BoundingBox();

    Renderer& renderer = Renderer::GetInstance();

    boundingBox = renderer.MeasureText(text.text, text.paint);

    return boundingBox;
}