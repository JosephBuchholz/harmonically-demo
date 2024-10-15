#include "Staff.h"

void Staff::Render(RenderData& renderData, Vec2<float> parentPosition) const
{
    Vec2<float> currentPosition = position + parentPosition;
    for (auto measure : m_Measures)
    {
        measure->Render(renderData, currentPosition);

        currentPosition.x += measure->width;
    }
}

void Staff::AddMeasure(std::shared_ptr<Measure> measure)
{
    m_Measures.push_back(measure);
}

std::shared_ptr<Measure> Staff::GetMeasure(int index) const
{
    return m_Measures.at(index);
}