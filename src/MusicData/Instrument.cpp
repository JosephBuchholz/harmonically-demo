#include "Instrument.h"

void Instrument::Render(RenderData& renderData) const
{
    for (auto staff : m_Staves)
    {
        staff->Render(renderData, { 0.0f, 0.0f });
    }
}

void Instrument::AddStaff(std::shared_ptr<Staff> staff)
{
    m_Staves.push_back(staff);
}