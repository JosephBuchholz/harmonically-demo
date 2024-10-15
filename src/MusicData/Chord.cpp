#include "Chord.h"

Chord::Chord()
    : chordSymbol("C") {}

Chord::Chord(const std::string& chordName)
    : chordSymbol(chordName) {}

void Chord::Render(RenderData& renderData, Vec2<float> measurePosition) const
{
    chordSymbol.Render(renderData, measurePosition + position);
}

void Chord::Init(Vec2<float> position)
{
    this->position = position;
}

BoundingBox Chord::GetBoundingBox() const
{
    BoundingBox bb = chordSymbol.GetBoundingBox();
    bb.position += position;
    return bb;
}