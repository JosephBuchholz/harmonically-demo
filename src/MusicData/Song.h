#pragma once

#include <vector>

#include "../Rendering/RenderData.h"
#include "Instrument.h"
#include "VisibleElement.h"
#include "TextElement.h"

class Song : public VisibleElement
{
public:
    Song(const std::string& songName, Vec2<float> pageSize);

    void Render(RenderData& renderData) const;

    void AddInstrument(std::shared_ptr<Instrument> instrument);

private:
    std::vector<std::shared_ptr<Instrument>> m_Instruments;

    TextElement m_SongName;

    Vec2<float> m_PageSize;
};