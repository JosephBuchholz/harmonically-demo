#include "Song.h"

Song::Song(const std::string& songName, Vec2<float> pageSize)
    : m_SongName(songName), m_PageSize(pageSize)
{
    m_SongName.SetPosition({ m_PageSize.x / 2.0f, 10.0f });
    m_SongName.fontSize = FontSize(20.0f);
}

void Song::Render(RenderData& renderData) const
{
    m_SongName.Render(renderData, m_Position, Paint());

    for (auto instrument : m_Instruments)
    {
        instrument->Render(renderData, m_Position);
    }
}

void Song::AddInstrument(std::shared_ptr<Instrument> instrument)
{
    m_Instruments.push_back(instrument);
}