#include "Instrument.h"

void Instrument::Render(RenderData& renderData, Vec2<float> parentPosition, int startMeasureIndex, int endMeasureIndex) const
{
    for (auto staff : m_Staves)
    {
        staff->Render(renderData, m_Position + parentPosition, startMeasureIndex, endMeasureIndex);
    }
}

BoundingBox Instrument::GetBoundingBox(int startMeasureIndex, int endMeasureIndex) const
{
    BoundingBox boundingBox = BoundingBox();

    if (!m_Staves.empty())
    {
        boundingBox = m_Staves[0]->GetBoundingBox(startMeasureIndex, endMeasureIndex);
    }

    for (auto staff : m_Staves)
    {
        boundingBox = BoundingBox::CombineBoundingBoxes(boundingBox, staff->GetBoundingBox(startMeasureIndex, endMeasureIndex));
    }

    boundingBox.position += m_Position;

    return boundingBox;
}

void Instrument::AddStaff(std::shared_ptr<Staff> staff)
{
    m_Staves.push_back(staff);
}