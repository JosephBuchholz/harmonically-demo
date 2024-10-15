#pragma once

#include <string>

#include "Paint.h"
#include "../Utils/Vec2.h"

/**
 * An object that holds data needed to render text.
 */
struct RenderableText
{
    RenderableText() {}
    RenderableText(const std::string& text, Vec2<float> position, const Paint& paint = Paint())
            : text(text), position(position), paint(paint) {}

    std::string text = "";
    Vec2<float> position = { 0.0f, 0.0f };
    Paint paint = Paint();
};