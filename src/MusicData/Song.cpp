#include "Song.h"

Song::Song(const std::string& songName, Vec2<float> pageSize)
    : m_SongName(songName), m_PageSize(pageSize)
{
    m_SongName.position.x = m_PageSize.x / 2.0f;
    m_SongName.position.y = 10.0f;
    m_SongName.fontSize = FontSize(20.0f);
}

void Song::Render(RenderData& renderData) const
{
    m_SongName.Render(renderData, position, Paint());

    for (auto instrument : m_Instruments)
    {
        instrument->Render(renderData, position);
    }
}

void Song::AddInstrument(std::shared_ptr<Instrument> instrument)
{
    m_Instruments.push_back(instrument);
}