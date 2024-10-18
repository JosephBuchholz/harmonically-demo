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

BoundingBox Staff::GetBoundingBox(int startMeasureIndex, int endMeasureIndex) const
{
    BoundingBox boundingBox = BoundingBox();

    if (!m_Measures.empty())
    {
        boundingBox = m_Measures[0]->GetBoundingBox();
    }

    for (int i = startMeasureIndex; i <= endMeasureIndex; i++)
    {
        std::shared_ptr<Measure> measure = m_Measures[i];

        boundingBox = BoundingBox::CombineBoundingBoxes(boundingBox, measure->GetBoundingBox());
    }

    boundingBox.position += m_Position;

    return boundingBox;
}

void Staff::AddMeasure(std::shared_ptr<Measure> measure)
{
    m_Measures.push_back(measure);
}

std::shared_ptr<Measure> Staff::GetMeasure(int index) const
{
    return m_Measures.at(index);
}