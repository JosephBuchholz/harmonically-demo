#include "Instrument.h"

void Instrument::Render(RenderData& renderData, Vec2<float> parentPosition) const
{
    for (auto staff : m_Staves)
    {
        staff->Render(renderData, position + parentPosition);
    }
}

void Instrument::AddStaff(std::shared_ptr<Staff> staff)
{
    m_Staves.push_back(staff);
}