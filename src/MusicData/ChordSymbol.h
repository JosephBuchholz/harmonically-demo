#pragma once

#include <vector>
#include <string>

#include "../Rendering/RenderData.h"
#include "../Utils/BoundingBox.h"
#include "VisibleElement.h"
#include "TextElement.h"

/**
 * This class represents a chord symbol, like: "Gm" or "Abm7b5" (at the moment is is basically just a wrapper around a TextElement).
 */
class ChordSymbol : public VisibleElement
{
public:
    ChordSymbol(const std::string& chordName);

    void Render(RenderData& renderData, Vec2<float> measurePosition) const;

    BoundingBox GetBoundingBox() const;

private:
    TextElement m_TextElement;
};