#pragma once

#include <vector>

#include "Chord.h"
#include "Lyric.h"
#include "VisibleElement.h"
#include "../Utils/BoundingBox.h"
#include "LyricPickup.h"

class Measure : VisibleElement
{
public:
    void Init(const MusicDisplayConstants& displayConstants);

    void Render(RenderData& renderData, Vec2<float> parentPosition) const;

    void AddChord(std::shared_ptr<Chord> chord) { m_Chords.push_back(chord); }
    void AddLyric(std::shared_ptr<Lyric> lyric) { m_Lyrics.push_back(lyric); }

private:
    float GetPositionXFromBeatPositionOfChords(float beatPosition) const;
    std::shared_ptr<Chord> GetChordFromBeatPosition(float beatPosition);

public:
    float width = 0.0f;
    float duration = 0.0f;

    std::vector<std::shared_ptr<Chord>> m_Chords;
    std::vector<std::shared_ptr<Lyric>> m_Lyrics;
};
