#pragma once

#include <string>
#include <vector>

#include "Staff.h"
#include "VisibleElement.h"

/**
 * Renderable object that represents an instrument in a song.
 * May contain multiple staves, as for example in a piano part.
 */
class Instrument : public VisibleElement
{
public:

    /**
     * Constructs an Instrument object.
     * 
     * @param name The name of the instrument. Which may be displayed next
     * to the part if there are multiple instrument in the same song.
     */
    Instrument(const std::string& name)
        : m_Name(name) {}

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
     * Adds a new staff to this instrument.
     * 
     * @param staff The staff to add.
     */
    void AddStaff(std::shared_ptr<Staff> staff);

private:
    std::string m_Name;

    std::vector<std::shared_ptr<Staff>> m_Staves;
};