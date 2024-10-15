#include "Rendering/Renderer.h"
#include "Rendering/MusicRenderer.h"
 
int main()
{
    MusicRenderer musicRenderer = MusicRenderer();

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
        musicRenderer.Render();
 
        // Update the window
        renderer.Display();
    }
 
    return 0;
}