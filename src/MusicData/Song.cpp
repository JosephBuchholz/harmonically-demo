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

    for (auto system : m_Systems)
    {
        for (auto instrument : m_Instruments)
        {
            instrument->Render(renderData, m_Position + system.position, system.beginningMeasureIndex, system.endingMeasureIndex);
        }
    }
}

void Song::CalculateSystemPositions()
{
    float currentYPosition = 0.0f;
    for (auto& system : m_Systems)
    {
        system.position = { 0.0f, currentYPosition };

        BoundingBox boundingBox = BoundingBox();

        if (!m_Instruments.empty())
        {
            boundingBox = m_Instruments[0]->GetBoundingBox(system.beginningMeasureIndex, system.endingMeasureIndex);

            for (auto instrument : m_Instruments)
            {
                boundingBox = BoundingBox::CombineBoundingBoxes(boundingBox, instrument->GetBoundingBox(system.beginningMeasureIndex, system.endingMeasureIndex));
            }
        }

        // The height of this system's bounding box + a margin
        currentYPosition += boundingBox.size.y + 15.0f;
    }
}

void Song::AddInstrument(std::shared_ptr<Instrument> instrument)
{
    m_Instruments.push_back(instrument);
}

void Song::AddSystem(const System& system)
{
    m_Systems.push_back(system);
}