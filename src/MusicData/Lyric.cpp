#include "Lyric.h"

Lyric::Lyric(const std::string& lyricText)
    : m_LyricText(lyricText)
{
    m_LyricText.fontSize.size = 12.0f;
}

void Lyric::Render(RenderData& renderData, Vec2<float> parentPosition, bool renderPickup) const
{
    m_LyricText.Render(renderData, parentPosition + m_Position, Paint());
}

BoundingBox Lyric::GetBoundingBox() const
{
    return m_LyricText.GetBoundingBox(Paint());
}