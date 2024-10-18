#include "Demo.h"

#include <vector>
#include <string>

#include "Rendering/Renderer.h"
#include "Rendering/MusicManager.h"

/**
* Splits the given string into a list of substrings sperated by the given delimiter.
*/
static std::vector<std::string> Split(const std::string& string, char delim)
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

/**
* Creates the Song object for this demo.
*/
static std::shared_ptr<Song> ConstructSong()
{
    std::shared_ptr<Song> song = std::make_shared<Song>("Amazing Grace", Vec2<float>{ 800.0f, 200.0f });
    song->SetPosition({ 40.0f, 40.0f });


    std::shared_ptr<Instrument> instrument = std::make_shared<Instrument>("Guitar");
    instrument->SetPosition({ 0.0f, 80.0f });
    
    std::shared_ptr<Staff> staff = std::make_shared<Staff>();

    // Add some chords, measures, and systems
    int currentMeasureIndex = 0;
    float currentSystemYPosition = 0.0f;

    std::vector<std::string> chordLines = Split(
R"(| C | C | F | C | C | C | G |
| G | C | C | F | C | Am | G6 | F | C |
| C | C | F | C | C | C | G |
| G | C | C | F | C | Am | G6 | F | C |
| C | C | F | C | C | C | G |
| G | C | C | F | C | Am | G6 | F | C |)", '\n');
    
    for (const auto& chordLine : chordLines)
    {
        std::vector<std::string> chordGroupings = Split(chordLine, '|');

        for (const auto& chordGrouping : chordGroupings)
        {
            std::shared_ptr<Measure> measure = std::make_shared<Measure>();

            std::vector<std::string> chordStrings = Split(chordGrouping, ' ');
            float currentBeatPosition = 0.0f;
            for (auto chordString : chordStrings)
            {
                std::shared_ptr<Chord> chord = std::make_shared<Chord>(chordString);
                chord->SetBeatPosition(currentBeatPosition);
                measure->AddChord(chord);
                currentBeatPosition += 1.0f;
            }

            staff->AddMeasure(measure);
        }

        System system = System();
        system.beginningMeasureIndex = currentMeasureIndex;
        system.endingMeasureIndex = (chordGroupings.size() - 1) + currentMeasureIndex;
        system.position = { 0.0f, currentSystemYPosition };
        song->AddSystem(system);

        currentMeasureIndex += chordGroupings.size();
        currentSystemYPosition += 60.0f;
    }

    // Add some lyrics to those measures
    std::vector<std::string> lyricLines = Split(
R"(| Amazing | grace how | sweet the | sound that | saved a | wretch like | me |
| I | once was | lost but | now am | found was | blind but | now I | see | |
| 'Twas grace that | taught my | heart to | fear and | grace my | fears re - | leieved |
| How | precious | did that | grace a - | ppear the | hour I | first be - | lieved | |
| When we've been | there ten | thousand | years bright | shining | as the | sun |
| We've | no less | days to | sing God's | praise than | when we'd | first be - | gun | |)", '\n');

    currentMeasureIndex = 0;
    for (const auto& lyricLine : lyricLines)
    {
        std::vector<std::string> lyricGroupings = Split(lyricLine, '|');

        for (int i = 0; i < lyricGroupings.size(); i++)
        {
            std::shared_ptr<Measure> measure = staff->GetMeasure(currentMeasureIndex);
            std::string lyricGrouping = lyricGroupings[i];

            std::vector<std::string> lyricStrings = Split(lyricGrouping, ' ');
            float currentBeatPosition = 0.0f;
            for (auto lyricString : lyricStrings)
            {
                std::shared_ptr<Lyric> lyric = std::make_shared<Lyric>(lyricString);
                lyric->SetBeatPosition(currentBeatPosition);
                measure->AddLyric(lyric);
                currentBeatPosition += 1.0f;
            }

            currentMeasureIndex++;
        }
    }

    // Initialize the measures (which will calculate the positions of the chords and lyrics)
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
    while (renderer.IsWindowOpen())
    {
        // Process events
        renderer.HandleEvents();

        // Clear screen
        renderer.Clear();

        // Render the music
        manager.Render();
 
        // Update the window
        renderer.Display();
    }
}