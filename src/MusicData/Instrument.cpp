#include "Instrument.h"

void Instrument::Render(RenderData& renderData, Vec2<float> parentPosition, int startMeasureIndex, int endMeasureIndex) const
{
    for (auto staff : m_Staves)
    {
        staff->Render(renderData, m_Position + parentPosition, startMeasureIndex, endMeasureIndex);
    }
}

void Instrument::AddStaff(std::shared_ptr<Staff> staff)
{
    m_Staves.push_back(staff);
}