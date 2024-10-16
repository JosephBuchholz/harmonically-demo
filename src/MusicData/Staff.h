#pragma once

#include <vector>

#include "Measure.h"
#include "VisibleElement.h"

/**
 * A renderable object that represents a staff in a song.
 * This class should normally be a child of an Instrument object.
 */
class Staff : public VisibleElement
{
public:

    /**
     * Renders this class relative to the given parentPosition.
     * 
     * @param renderData The RenderData to render to.
     * @param parentPosition The position of this object's parent.
     */
    void Render(RenderData& renderData, Vec2<float> parentPosition) const;

    /**
     * Adds a new measure to this staff.
     * 
     * @param measure The measure to add.
     */
    void AddMeasure(std::shared_ptr<Measure> measure);

    /**
     * Gets a measure contained in this staff.
     * 
     * @param index The index of the measure to get.
     * @returns The measure.
     */
    std::shared_ptr<Measure> GetMeasure(int index) const;

    /**
     * Gets the number of measures contained within this staff.
     * 
     * @returns The number of measures.
     */
    int GetMeasureCount() const { return m_Measures.size(); };

private:
    std::vector<std::shared_ptr<Measure>> m_Measures;
};