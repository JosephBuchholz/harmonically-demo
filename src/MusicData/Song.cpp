#include "Song.h"

void Song::Render(RenderData& renderData) const
{
    for (auto instrument : m_Instruments)
    {
        instrument->Render(renderData);
    }
}

void Song::AddInstrument(std::shared_ptr<Instrument> instrument)
{
    m_Instruments.push_back(instrument);
}