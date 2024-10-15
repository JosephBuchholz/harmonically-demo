#include "Demo.h"

#include <array>
#include <vector>
#include <string>
#include <iostream>

#include "Rendering/Renderer.h"
#include "Rendering/MusicManager.h"

std::vector<std::string> Split(const std::string& string, char delim)
{
    std::vector<std::string> strings;
    std::string current = "";
    for (char c : string)
    {
        if (c == delim)
        {
            if (current != "")
            {
                strings.push_back(current);
                current = "";
            }
        }
        else
        {
            current += c;
        }
    }
    
    if (current != "")
        strings.push_back(current);
    
    return strings;
}

std::shared_ptr<Song> ConstructSong()
{
    std::shared_ptr<Song> song = std::make_shared<Song>("Amazing Grace", Vec2<float>{ 800.0f, 200.0f });
    song->position = { 40.0f, 40.0f };

    std::shared_ptr<Instrument> instrument = std::make_shared<Instrument>("Guitar");

    instrument->position = { 0.0f, 80.0f };
    
    std::shared_ptr<Staff> staff = std::make_shared<Staff>();

    std::vector<std::string> chordGroupings = Split("| C Gm | C | F | C | C | C | G | G | C | C | F | C | Am | G6 | F | C |", '|');
    for (const auto& chordGrouping : chordGroupings)
    {
        std::shared_ptr<Measure> measure = std::make_shared<Measure>();

        std::vector<std::string> chordStrings = Split(chordGrouping, ' ');
        float currentBeatPosition = 0.0f;
        for (auto chordString : chordStrings)
        {
            std::shared_ptr<Chord> chord = std::make_shared<Chord>(chordString);
            chord->beatPosition = currentBeatPosition;
            measure->AddChord(chord);
            currentBeatPosition += 1.0f;
        }

        staff->AddMeasure(measure);
    }

    std::vector<std::string> lyricGroupings = Split("| Amazing | grace how | sweet the | sound that | saved a | wretch like | me | I | once was | lost but | now am | found was | blind but | now I | see | |", '|');
    for (int i = 0; i < lyricGroupings.size(); i++)
    {
        std::shared_ptr<Measure> measure = staff->GetMeasure(i);
        std::string lyricGrouping = lyricGroupings[i];

        std::vector<std::string> lyricStrings = Split(lyricGrouping, ' ');
        float currentBeatPosition = 0.0f;
        for (auto lyricString : lyricStrings)
        {
            std::shared_ptr<Lyric> lyric = std::make_shared<Lyric>(lyricString);
            lyric->beatPosition = currentBeatPosition;
            measure->AddLyric(lyric);
            currentBeatPosition += 1.0f;
        }
    }

    for (int i = 0; i < staff->GetMeasureCount(); i++)
    {
        staff->GetMeasure(i)->Init(MusicDisplayConstants());
    }

    instrument->AddStaff(staff);

    song->AddInstrument(instrument);
    
    return song;
}

void RunDemo()
{
    // Initialize the music manager
    MusicManager manager = MusicManager();
    manager.SetSong(ConstructSong());

    Renderer& renderer = Renderer::GetInstance();
 
    // Start the main loop
    while (renderer.m_Window.isOpen())
    {
        // Process events
        sf::Event event;
        while (renderer.m_Window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                renderer.m_Window.close();
        }

        // Clear screen
        renderer.Clear();

        // Render the music
        manager.Render();
 
        // Update the window
        renderer.Display();
    }
}