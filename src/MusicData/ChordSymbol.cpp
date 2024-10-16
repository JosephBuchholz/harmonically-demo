#include "ChordSymbol.h"

#include "../Utils/Converters.h"

ChordSymbol::ChordSymbol(const std::string& chordName)
        : m_TextElement(chordName)
{
    m_TextElement.justify = Justify::Left;
    m_TextElement.fontSize.size = 12.0f;
}

void ChordSymbol::Render(RenderData& renderData, Vec2<float> parentPosition) const
{
    m_TextElement.Render(renderData, m_Position + parentPosition, Paint());
}

BoundingBox ChordSymbol::GetBoundingBox() const
{
    return m_TextElement.GetBoundingBox(Paint());
}