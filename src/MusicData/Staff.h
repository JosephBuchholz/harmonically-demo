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
     * @param startMeasureIndex The measure index to start rendering at.
     * @param endMeasureIndex The last measure index to render (the range is inclusive).
     */
    void Render(RenderData& renderData, Vec2<float> parentPosition, int startMeasureIndex, int endMeasureIndex) const;

    /**
     * Calculates the bounding box of a section of this staff given the measure range.
     * 
     * @param startMeasureIndex The measure index to start at.
     * @param endMeasureIndex The measure index to end at (inclusivly).
     * @returns The bounding box.
     */
    BoundingBox GetBoundingBox(int startMeasureIndex, int endMeasureIndex) const;

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