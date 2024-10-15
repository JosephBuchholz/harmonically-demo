#pragma once

#include <memory>

#include "RenderData.h"

#include "../MusicData/Song.h"

/**
 * This class manages rendering the music to the screen.
 */
class MusicManager
{
public:
    void Render();

    void SetSong(std::shared_ptr<Song> song) { m_Song = song; }

public:
    std::shared_ptr<Song> m_Song;
};
