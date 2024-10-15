#include "Lyric.h"

Lyric::Lyric()
{
    this->lyricText.fontSize.size = 12.0f;
}

Lyric::Lyric(const std::string& lyricText)
    : lyricText(lyricText)
{
    this->lyricText.fontSize.size = 12.0f;
}

void Lyric::Init(Vec2<float> position)
{
    this->position = position;
}

void Lyric::Render(RenderData& renderData, Vec2<float> parentPosition, bool renderPickup) const
{
    lyricText.Render(renderData, parentPosition + position, Paint());
}