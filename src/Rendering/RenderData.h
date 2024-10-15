#pragma once

#include <vector>

#include "RenderableLine.h"
#include "RenderableText.h"

#include "MusicDisplayConstants.h"

/**
 * An object that holds data to render something to the screen.
 */
class RenderData
{

public:
    void AddLine(const RenderableLine& line);
    void AddText(const RenderableText& text);

    std::vector<RenderableLine> m_Lines;
    std::vector<RenderableText> m_Texts;

    MusicDisplayConstants displayConstants = MusicDisplayConstants();

    float zoom = 1.0f;
    Vec2<float> offset = { 0.0f, 0.0f };
};
