#pragma once

#include <vector>

#include "Measure.h"
#include "VisibleElement.h"

class Staff : VisibleElement
{
public:
    void Render(RenderData& renderData, Vec2<float> parentPosition) const;

    void AddMeasure(std::shared_ptr<Measure> measure);
    std::shared_ptr<Measure> GetMeasure(int index) const;

    int GetMeasureCount() const { return m_Measures.size(); };

private:
    std::vector<std::shared_ptr<Measure>> m_Measures;
};