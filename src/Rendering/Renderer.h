#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "../Utils/Vec2.h"
#include "../Utils/BoundingBox.h"
#include "Paint.h"

/**
* Singleton that provides rendering functionality (uses SFML for rendering and windowing).
*/
class Renderer
{
public:
	static Renderer& GetInstance();

private:
	Renderer();

	Renderer(Renderer const&) = delete;
	void operator=(Renderer const&) = delete;

public:

	// Clears the display
	void Clear();

	// Actually renders onto the window
	void Display();
	
	// Handle window events
	void HandleEvents();

	// Whether the window is open (Can be used to test to see if the window has been closed)
	bool IsWindowOpen() const;

	void SetScale(float scale) { this->m_Scale = scale; }
	void SetOffset(Vec2<float> offset) { this->m_Offset = offset; }

	// Drawing methods
	void DrawLine(Vec2<float> start, Vec2<float> end, const Paint& paint = Paint());
	void DrawRect(Vec2<float> position, Vec2<float> size, const Paint& paint = Paint());
	void DrawText(const std::string& text, Vec2<float> position, const Paint& paint = Paint());

	BoundingBox MeasureText(const std::string& text, const Paint& paint = Paint());


private:
	// The SFML window
	sf::RenderWindow m_Window;

	// The current font used for rendering text
    sf::Font m_CurrentFont;

	float m_Scale = 1.0f;
	Vec2<float> m_Offset = { 0.0f, 0.0f };
};