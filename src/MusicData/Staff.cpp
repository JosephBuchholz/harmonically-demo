#include "Staff.h"

void Staff::Render(RenderData& renderData, Vec2<float> parentPosition, int startMeasureIndex, int endMeasureIndex) const
{
    Vec2<float> currentPosition = m_Position + parentPosition;
    for (int i = startMeasureIndex; i <= endMeasureIndex; i++)
    {
        std::shared_ptr<Measure> measure = m_Measures[i];

        measure->Render(renderData, currentPosition);

        currentPosition.x += measure->GetWidth();
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