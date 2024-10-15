#include "Renderer.h"

#include "../Utils/Converters.h"

#include <iostream>

Renderer& Renderer::GetInstance()
{
    static Renderer instance;
    return instance;
}

Renderer::Renderer()
	: m_Window(sf::VideoMode(800, 600), "Harmonically Demo")
{
    if (!currentFont.loadFromFile("assets/fonts/times.ttf"))
        std::cout << "Failed to load font file" << std::endl;
}

void Renderer::Clear()
{
    m_Window.clear(sf::Color::White);
}

void Renderer::Display()
{
    m_Window.display();
}

void Renderer::DrawLine(Vec2<float> start, Vec2<float> end, const Paint& paint)
{
    start += offset;
    end += offset;

    sf::VertexArray lines(sf::LinesStrip, 2);
    lines[0].position = sf::Vector2f(start.x * scale, start.y * scale);
    lines[0].color  = sf::Color::Black;
    lines[1].position = sf::Vector2f(end.x * scale, end.y * scale);
    lines[1].color  = sf::Color::Black;

    m_Window.draw(lines);
}

void Renderer::DrawRect(Vec2<float> position, Vec2<float> size, const Paint& paint)
{
    position += offset;
    DrawLine({ position.x, position.y }, { position.x + size.x, position.y }, paint);
    DrawLine({ position.x + size.x, position.y }, { position.x + size.x, position.y + size.y }, paint);
    DrawLine({ position.x + size.x, position.y + size.y }, { position.x, position.y + size.y }, paint);
    DrawLine({ position.x, position.y + size.y }, { position.x, position.y }, paint);
}

void Renderer::DrawText(const std::string& text, Vec2<float> position, const Paint& paint)
{
    position += offset;

    sf::Text rendererableText(text, currentFont, paint.textSize * scale);
    rendererableText.setPosition(sf::Vector2f(position.x * scale, position.y * scale));
    rendererableText.setColor(sf::Color::Black);

    m_Window.draw(rendererableText);
}

/*BoundingBox Renderer::MeasureText(const std::string &text, const Paint &paint)
{
    BoundingBox boundingBox;
    float* boundingBoxArray = MeasureTextCallback(text.c_str(), EncodePaintObject(paint).c_str());

    if (boundingBoxArray == nullptr)
    {
        LOGE("BoundingBoxArray from JS is nullptr");
        return boundingBox;
    }

    boundingBox.position.x = boundingBoxArray[0];
    boundingBox.position.y = boundingBoxArray[1];
    boundingBox.size.x = boundingBoxArray[2];
    boundingBox.size.y = boundingBoxArray[3];

    free(boundingBoxArray);

    return boundingBox;
}*/