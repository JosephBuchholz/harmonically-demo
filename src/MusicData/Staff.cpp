#include "Staff.h"

void Staff::Render(RenderData& renderData, Vec2<float> parentPosition) const
{
    for (auto measure : m_Measures)
    {
        measure->Render(renderData, parentPosition);
    }
}

void Staff::AddMeasure(std::shared_ptr<Measure> measure)
{
    m_Measures.push_back(measure);
}