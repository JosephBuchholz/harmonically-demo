#include "Renderer.h"

#include "../Utils/Converters.h"

Renderer& Renderer::GetInstance()
{
    static Renderer instance;
    return instance;
}

Renderer::Renderer()
	: m_Window(sf::VideoMode(1000, 600), "Harmonically Demo")
{
    // Load font file
    if (!m_CurrentFont.loadFromFile("assets/fonts/times.ttf"))
        throw std::exception("Failed to load 'assets/fonts/times.ttf'");
}

void Renderer::Clear()
{
    m_Window.clear(sf::Color::White);
}

void Renderer::Display()
{
    m_Window.display();
}

void Renderer::HandleEvents()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_Window.close();
	}
}

bool Renderer::IsWindowOpen() const
{
    return m_Window.isOpen();
}

void Renderer::DrawLine(Vec2<float> start, Vec2<float> end, const Paint& paint)
{
    start += m_Offset;
    end += m_Offset;

    sf::VertexArray lines(sf::LinesStrip, 2);
    lines[0].position = sf::Vector2f(start.x * m_Scale, start.y * m_Scale);
    lines[0].color  = sf::Color::Black;
    lines[1].position = sf::Vector2f(end.x * m_Scale, end.y * m_Scale);
    lines[1].color  = sf::Color::Black;

    m_Window.draw(lines);
}

void Renderer::DrawRect(Vec2<float> position, Vec2<float> size, const Paint& paint)
{
    position += m_Offset;
    DrawLine({ position.x, position.y }, { position.x + size.x, position.y }, paint);
    DrawLine({ position.x + size.x, position.y }, { position.x + size.x, position.y + size.y }, paint);
    DrawLine({ position.x + size.x, position.y + size.y }, { position.x, position.y + size.y }, paint);
    DrawLine({ position.x, position.y + size.y }, { position.x, position.y }, paint);
}

void Renderer::DrawText(const std::string& text, Vec2<float> position, const Paint& paint)
{
    position += m_Offset;

    sf::Text rendererableText(text, m_CurrentFont, paint.textSize * m_Scale);
    rendererableText.setPosition(sf::Vector2f(position.x * m_Scale, position.y * m_Scale));
    rendererableText.setColor(sf::Color::Black);

    m_Window.draw(rendererableText);
}

BoundingBox Renderer::MeasureText(const std::string& text, const Paint& paint)
{
    sf::Text rendererableText(text, m_CurrentFont, paint.textSize * m_Scale);

    sf::FloatRect bounds = rendererableText.getLocalBounds();

    BoundingBox boundingBox = BoundingBox();
    boundingBox.size.x = bounds.width;
    boundingBox.size.y = bounds.height;

    return boundingBox;
}