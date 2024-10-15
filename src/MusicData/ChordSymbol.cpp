#include "ChordSymbol.h"

#include "../Utils/Converters.h"

void ChordSymbol::Render(RenderData& renderData, Vec2<float> measurePosition) const
{
    renderData.AddText(Text(m_ChordName, position + measurePosition));
}

BoundingBox ChordSymbol::GetBoundingBox() const
{
    BoundingBox bb;

    /*Paint paint = Paint();
    if (fontStyle == FontStyle::Italic)
        paint.isItalic = true;
    if (fontWeight == FontWeight::Bold)
        paint.isBold = true;
    paint.textSize = fontSize.size;

    BoundingBox textBoundingBox = RenderMeasurement::GetTextBoundingBox(Text(m_ChordName, position.x, position.y, paint));

    bb.position.x = textBoundingBox.position.x + position.x;
    bb.position.y = textBoundingBox.position.y + position.y;
    
    if (justify == Justify::Left)
        bb.position.x += textBoundingBox.size.x / 2.0f;

    bb.size.x = textBoundingBox.size.x;
    bb.size.y = textBoundingBox.size.y;
    */

    return bb;
}