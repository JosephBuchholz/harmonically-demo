#pragma once

#include <functional>

#include "../Rendering/RenderData.h"
#include "VisibleElement.h"
#include "LyricPickup.h"

#include "TextElement.h"

/**
 * A renderable object that represents a single lyric (word or syllable) of a song.
 */
class Lyric : public VisibleElement
{
public:

    /**
     * Constructs a Lyric object.
     * 
     * @param lyricText The the text of this Lyric object.
     */
    Lyric(const std::string& lyricText);

    /**
     * Renders this class relative to the given parentPosition.
     * 
     * @param renderData The RenderData to render to.
     * @param parentPosition The position of this object's parent.
     */
    void Render(RenderData& renderData, Vec2<float> parentPosition, bool isPickup = false) const;

    /**
     * Gets the bounds of this object.
     * 
     * @returns A BoundingBox.
     */
    BoundingBox GetBoundingBox() const;

    /**
     * Getter and setter for m_Duration.
     */
    float GetDuration() const { return m_Duration; }
    void SetDuration(float duration) { m_Duration = duration; }

    /**
     * Getter and setter for m_BeatPostion.
     */
    float GetBeatPosition() const { return m_BeatPosition; }
    void SetBeatPosition(float beatPosition) { m_BeatPosition = beatPosition; }

private:
    TextElement m_LyricText;

    float m_Duration = 0.0f;
    float m_BeatPosition = 0.0f;
};