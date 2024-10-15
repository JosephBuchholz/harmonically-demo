#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "../Utils/Vec2.h"
#include "Paint.h"

class Renderer
{
public:
	static Renderer& GetInstance();

private:
	Renderer();

	Renderer(Renderer const&) = delete;
	void operator=(Renderer const&) = delete;

public:

	void Clear();
	void Display();

	void SetScale(float scale) { this->scale = scale; }
	void SetOffset(Vec2<float> offset) { this->offset = offset; }

	void DrawLine(Vec2<float> start, Vec2<float> end, const Paint& paint = Paint());
	void DrawRect(Vec2<float> position, Vec2<float> size, const Paint& paint = Paint());
	void DrawText(const std::string& text, Vec2<float> position, const Paint& paint = Paint());

	//BoundingBox MeasureText(const std::string& text, const Paint& paint = Paint());

private:
	std::string EncodePaintObject(const Paint& paint, float scale = 1.0f);

	// TODO: change
public:
	sf::RenderWindow m_Window;

private:
    sf::Font currentFont;

	float scale = 1.0f;
	Vec2<float> offset = { 0.0f, 0.0f };
};