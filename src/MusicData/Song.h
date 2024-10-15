#pragma once

#include <vector>

#include "../Rendering/RenderData.h"
#include "Instrument.h"

class Song
{
public:
    void Render(RenderData& renderData) const;

    void AddInstrument(std::shared_ptr<Instrument> instrument);

private:
    std::vector<std::shared_ptr<Instrument>> m_Instruments;
};