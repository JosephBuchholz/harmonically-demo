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
    Chord();
    Chord(const std::string& chordName);

    void Init(Vec2<float> position);

    void Render(RenderData& renderData, Vec2<float> measurePosition) const;

    BoundingBox GetBoundingBox() const;

    void SetPosition(Vec2<float> position) { this->position = position; }

public:
    ChordSymbol chordSymbol;

    float duration = 1.0f;

    float beatPosition = 0.0f;
    float beatPositionInSong = 0.0f;
};
