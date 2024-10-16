#pragma once

#include <vector>

#include "../Rendering/RenderData.h"
#include "Instrument.h"
#include "VisibleElement.h"
#include "TextElement.h"

/**
 * A renderable object that displays the sheet music for a song.
 */
class Song : public VisibleElement
{
public:
    /**
     * Constructs a Song object.
     * 
     * @param songName The name of the song.
     * @param pageSize The size of the page in tenths.
     */
    Song(const std::string& songName, Vec2<float> pageSize);

    /**
     * Renders this class.
     * 
     * @param renderData The RenderData object to render to.
     */
    void Render(RenderData& renderData) const;

    /**
     * Adds an instrument to this song.
     * 
     * @param instrument The instrument to add.
     */
    void AddInstrument(std::shared_ptr<Instrument> instrument);

private:
    std::vector<std::shared_ptr<Instrument>> m_Instruments;

    TextElement m_SongName;

    Vec2<float> m_PageSize;
};