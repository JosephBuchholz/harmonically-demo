#pragma once

#include <vector>

#include "Chord.h"
#include "Lyric.h"
#include "VisibleElement.h"
#include "../Utils/BoundingBox.h"
#include "LyricPickup.h"

/**
 * Renderable object that reperesents a measure in music notation.
 */
class Measure : public VisibleElement
{
public:

    /**
     * Updates/calculates the positions of this measure's child elmenets and this measure's width.
     * Should be called after all chords and lyrics have been added.
     * 
     * @param displayConstants The display constants.
     */
    void Init(const MusicDisplayConstants& displayConstants);

    /**
     * Renders this class relative to the given parentPosition.
     * 
     * @param renderData The RenderData to render to.
     * @param parentPosition The position of this object's parent.
     */
    void Render(RenderData& renderData, Vec2<float> parentPosition) const;

    /**
     * Calculates the bounding box of this measure.
     * 
     * @returns The bounding box.
     */
    BoundingBox GetBoundingBox() const;

    /**
     * Adds a new chord to this measure.
     * 
     * @param chord The chord to add.
     */
    void AddChord(std::shared_ptr<Chord> chord) { m_Chords.push_back(chord); }

    /**
     * Adds a new lyric to this measure.
     * 
     * @param lyric The lyric to add.
     */
    void AddLyric(std::shared_ptr<Lyric> lyric) { m_Lyrics.push_back(lyric); }

    /**
     * Gets the width of this measure.
     * 
     * @returns The width.
     */
    float GetWidth() const { return m_Width; }

private:
    float GetPositionXFromBeatPositionOfChords(float beatPosition) const;
    std::shared_ptr<Chord> GetChordFromBeatPosition(float beatPosition);

private:
    float m_Width = 0.0f;
    float m_Duration = 0.0f;

    std::vector<std::shared_ptr<Chord>> m_Chords;
    std::vector<std::shared_ptr<Lyric>> m_Lyrics;
};
