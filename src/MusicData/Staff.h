#pragma once

#include "Measure.h"

#include <vector>

class Staff
{
public:
    void Render(RenderData& renderData, Vec2<float> parentPosition) const;

    void AddMeasure(std::shared_ptr<Measure> measure);

private:
    std::vector<std::shared_ptr<Measure>> m_Measures;
};