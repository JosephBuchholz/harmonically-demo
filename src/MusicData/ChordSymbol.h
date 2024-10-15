#pragma once

#include <vector>
#include <string>

#include "../Rendering/RenderData.h"
#include "../Utils/BoundingBox.h"
#include "VisibleElement.h"

class ChordSymbol : public VisibleElement
{
public:
    ChordSymbol(const std::string& chordName)
        : m_ChordName(chordName) {}

    void Render(RenderData& renderData, Vec2<float> measurePosition) const;

    BoundingBox GetBoundingBox() const;

private:
    float duration = 1.0f;
    float beatPosition = 0.0f; // the position of the note in the measure in beats(quarter notes)
    float beatPositionInSong = 0.0f; // the position of the note in the song(not counting repeats) in beats(quarter notes)

    std::string m_ChordName;
};