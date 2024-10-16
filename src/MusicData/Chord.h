#pragma once

#include <string>

#include "../Rendering/RenderData.h"
#include "VisibleElement.h"
#include "../Utils/BoundingBox.h"
#include "ChordSymbol.h"

/**
 * Represetents a chord with a certain duration and position in the parent Measure.
 */
class Chord : public VisibleElement
{
public:

    /**
     * Constructs a Chord object.
     * 
     * @param chordName The name of the chord symbol. Like for example: "C" or "Bm7b5".
     */
    Chord(const std::string& chordName);

    /**
     * Renders this class relative to the given parentPosition.
     * 
     * @param renderData The RenderData to render to.
     * @param parentPosition The position of this object's parent.
     */
    void Render(RenderData& renderData, Vec2<float> parentPosition) const;

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
    ChordSymbol m_ChordSymbol;

    float m_Duration = 1.0f;
    float m_BeatPosition = 0.0f;
};
