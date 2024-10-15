#include "Lyric.h"

void Lyric::Init(Vec2<float> position)
{
    this->position = position;
}

void Lyric::Render(RenderData& renderData, Vec2<float> parentPosition, bool renderPickup) const
{
    lyricText.Render(renderData, parentPosition + position, Paint());
}