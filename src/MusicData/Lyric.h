#pragma once

#include <functional>

#include "../Rendering/RenderData.h"
#include "VisibleElement.h"
#include "LyricPickup.h"

#include "TextElement.h"

class Lyric : public VisibleElement
{
public:
    Lyric();
    Lyric(const std::string& lyricText);

    void Init(Vec2<float> position);

    void Render(RenderData& renderData, Vec2<float> parentPosition, bool isPickup = false) const;

public:
    float beatPosition = 0.0f;
    float duration = 0.0f;

    TextElement lyricText;
};