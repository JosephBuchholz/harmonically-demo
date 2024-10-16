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

    /**
     * Constructs a Chord object.
     * 
     * @param chordName The name of the chord symbol. Like for example: "C" or "Bm7b5".
     */
    ChordSymbol(const std::string& chordName);

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

private:
    TextElement m_TextElement;
};