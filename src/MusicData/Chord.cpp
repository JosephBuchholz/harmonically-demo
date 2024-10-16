#include "Chord.h"

Chord::Chord(const std::string& chordName)
    : m_ChordSymbol(chordName) {}

void Chord::Render(RenderData& renderData, Vec2<float> parentPosition) const
{
    m_ChordSymbol.Render(renderData, parentPosition + m_Position);
}

BoundingBox Chord::GetBoundingBox() const
{
    BoundingBox bb = m_ChordSymbol.GetBoundingBox();
    bb.position += m_Position;
    return bb;
}