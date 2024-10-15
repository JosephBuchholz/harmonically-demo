#include "Rendering/Renderer.h"
#include "Rendering/MusicManager.h"
 
int main()
{
    MusicManager manager = MusicManager();

    std::shared_ptr<Song> song = std::make_shared<Song>();

    std::shared_ptr<Instrument> instrument = std::make_shared<Instrument>("Guitar");
    
    std::shared_ptr<Staff> staff = std::make_shared<Staff>();

    std::shared_ptr<Measure> measure = std::make_shared<Measure>();

    std::shared_ptr<Chord> chord = std::make_shared<Chord>();

    measure->AddChord(chord);

    measure->Init(MusicDisplayConstants());

    staff->AddMeasure(measure);

    instrument->AddStaff(staff);

    song->AddInstrument(instrument);


    manager.SetSong(song);

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
 
    return 0;
}